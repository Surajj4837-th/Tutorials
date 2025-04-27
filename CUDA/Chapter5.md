# Thread Cooperation

Till now we have run multiple copies of a function in parallel, these parallel copies are called *blocks*. The CUDA runtime allows these blocks to be split into *threads*. In the vector addition on GPU code, we used the following line:
`add<<<N,1>>>( dev_a, dev_b, dev_c );`

In this line, the second parameter represents the number of threads per block we want the CUDA runtime to create on our behalf. We have currently launched only 1 thread per block thus:
`N blocks x 1 thread/block = N parallel threads`

Similarly, we could have launched N/2 blocks with two threads per block, N/4 blocks with four threads per block, and so on. 

What is the advantage of using threads rather than blocks?
Parallel threads within a block will have the ability to do things that parallel blocks cannot do.


## Vector Sum Using GPU Threads

Refer to [VectorSumBlocks.cu](Programs/Chapter5/VectorSumBlocks.cu).

Now let's modify the vector sum code we developed earlier using GPU blocks to threads. There will be 2 changes:
1. Change of kernel <<< >>> parameters in the function call.  
 Earlier we launched N blocks:
   `add<<<N,1>>>( dev _ a, dev _ b, dev _ c );`
 Now we will launch N threads:   
   `add<<<1,N>>>( dev _ a, dev _ b, dev _ c );`
1. Change of index.  
 Earlier we used blockIdx:
   `int tid = blockIdx.x;`
 Now we will use threadIdx:
   `int tid = threadIdx.x;`

## GPU Sums of a longer vector

We know that the hardware limits the number of blocks in a single launch to 65,535. Similarly, the hardware limits the number of threads per block with which we can launch a kernel. Specifically, this number cannot exceed the value specified by the **maxThreadsPerBlock** field of the device properties structure. In our case, the value was:
`max threads per block: 1024`

In case the vector size is greater than this number then we need to use a combination of threads and blocks. This will require 2 changes:  
1. Change the index computation within the kernel.  
 The indexing will be a combination of thread and blocks as:
   `int tid = threadIdx.x + blockIdx.x * blockDim.x;`

   **blockDim** is a new CUDA variable that is constant for all blocks and stores the number of threads along each block dimension. Since we use a one-dimensional block, we refer only to blockDim.x. It is similar to the gridDim variable. Moreover, gridDim is two-dimensional, whereas blockDim is three-dimensional. That is, the CUDA runtime allows you to launch a two-dimensional grid of blocks where each block is a three-dimensional array of threads. In total, we have 5 degrees of indexing freedom.
 The above indexing is similar to image indexing where threads represent columns and the blocks represent rows.
2. Change of kernel launch.
 Here, we need N parallel threads to launch, but we want them to launch across multiple blocks so we do not hit the 1024-thread limitation imposed upon us. One solution is to arbitrarily set the block size to some fixed number of threads; for this example, let’s use 128 threads per block. Then we can just launch N/128 blocks to get our total of N threads running. 
 The problem here is that N/128 is an integer division. This implies that if N were 127, N/128 would be zero. Thus we will be launching zero blocks. This can be solved either by using ceil() or by changing the computation to (N+127)/128 instead of N/128. Now the kernel launch call will be:
   `add<<< (N+127)/128, 128 >>>(dev_a, dev_b, dev_c);`

 Now consider the following cases:
 1. Size of vector, N = 120  
 We will create (120+127)/128 = 1 block, with 128 threads i.e. 1x128 = 128 threads, now we have 8 extra threads.
 1. Size of vector, N = 128  
 We will create (120+127)/128 = 1 block, with 128 threads i.e. 1x128 = 128 threads, now we have no extra threads.
 1. Size of vector, N = 200  
 We will create (200+127)/128 = 2 blocks, with 128 threads i.e. 2x128 = 256 threads, now we have 56 extra vectors.

 Hence, we launch too many threads when N is not an exact multiple of 128. To solve this problem we use an if condition:
 ```C
 if (tid < N)  
 c[tid] = a[tid] + b[tid];
 ```
 Thus, when our index overshoots the end of our array, as will always happen when we launch a non-multiple of 128, we automatically refrain from performing the calculation. More important, we refrain from reading and writing memory off the end of our array.

 ## GPU Sums of an arbitrarily longer vector

In addition to the limitation on thread count, there is also a hardware limitation on the number of blocks (albeit much greater than the thread limitation). As mentioned previously, neither dimension of a grid of blocks may exceed 65,535.
So, this raises a problem with our current vector addition implementation. If we launch N/128 blocks to add our vectors, we will hit launch failures when our vectors exceed 65,535 * 128 = 8,388,480 elements.
The solution is to reuse the threads to process all elements.
```C
__global__ void add( int *a, int *b, int *c ) 
{
   int tid = threadIdx.x + blockIdx.x * blockDim.x;
   while (tid < N) 
 {
      c[tid] = a[tid] + b[tid];
 tid += blockDim.x * gridDim.x;
 }
}
```

In the GPU implementation, we consider the number of parallel threads launched to be the number of processors although actual GPU may have fewer or more processors. Now fix the kernel launch parameters. To ensure we never launch too many blocks, we will just fix the number of blocks to some reasonably small value. We will use 128 blocks, each with 128 threads.
`add<<<128,128>>>(dev_a, dev_b, dev_c);`

## Shared Memory and Synchronization

CUDA C makes available a region of memory that we call shared memory. This region of memory brings along with it another extension to the C language akin to **\_\_device__** and **\_\_global__**. As a programmer, you can modify your variable declarations with the CUDA C keyword **\_\_shared__** to make this variable resident in shared memory.

The CUDA C compiler treats variables in shared memory differently than typical variables. It creates a copy of the variable for each block that you launch on the GPU. Every thread in that block shares the memory, but threads cannot see or modify the copy of this variable that is seen within other blocks.  
This provides an excellent means by which threads within a block can communicate and collaborate on computations. Furthermore, shared memory buffers reside physically on the GPU as opposed to residing in off-chip DRAM. Because of this, the latency to access shared memory tends to be far lower than typical buffers, making shared memory effective as a per-block, software-managed cache or scratchpad.

If we expect to communicate between threads, we also need a mechanism for synchronizing between threads. For example, if thread A writes a value to shared memory and we want thread B to do something with this value, we can’t have thread B start its work until we know the write from thread A is complete. Without synchronization, we have created a race condition where the correctness of the execution results depends on the nondeterministic details of the hardware.

Example:
``` C
#define imin(a,b) (a<b?a:b)

const int N = 33 * 1024;
const int threadsPerBlock = 256;

__global__ void dot( float *a, float *b, float *c ) 
{
 __shared__ float cache[threadsPerBlock];
   int tid = threadIdx.x + blockIdx.x * blockDim.x;
   int cacheIndex = threadIdx.x;
   float
 temp = 0;
   while (tid < N) {
 temp += a[tid] * b[tid];
 tid += blockDim.x * gridDim.x;
}
   // set the cache values
   cache[cacheIndex] = temp;
```
Shared memory buffer is declared. It is the array of size **threadsPerBlock** so each thread in the block has a place to store its temporary result.
`__shared__ float cache[threadsPerBlock];`

