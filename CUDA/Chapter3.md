# 3. Introduction to CUDA C

## First Program

Refer to [HelloWorld.cu](Programs/Chapter3/HelloWorld.cu).

CUDA C is similar to standard C with some extra keywords. This code runs entirely on the host. 

## Terminology
In CUDA terminology, the CPU and the system's memory are referred to as **host** and the GPU and its memory are referred to as **device**. A function that executes on the device is called **kernel**.

## CUDA code execution
Use the following command to create an executable file of the code.
`nvcc HelloWorld.cu -o Hello`

This will create an executable with the name Hello in the directory. Now run the executable by following the command:
`./Hello`

## Kernel Call

Refer to [KernelCall.cu](Programs/Chapter3/KernelCall.cu).

There are the following updates in the above code:
- An empty function named *kernel()* recognized with \_\_global__ keyword.
- A call to the empty function, added with <<<1,1>>>.

GNU gcc might compile your host code on Linux operating systems, while Microsoft Visual C compiles it on Windows systems. The NVIDIA tools simply feed this host compiler your code.

CUDA C adds the \_\_global__ qualifier to the standard C. This mechanism alerts the compiler that a function should be compiled to run on a device instead of the host. In this simple example, nvcc gives the function *kernel()* to the compiler that handles device code, and it feeds *main()* to the host compiler as it did in the previous example.

The angular brackets denote arguments we plan to pass to the runtime system. These are not arguments to the device code but are parameters that will influence how the runtime will launch our device code.

## Passing Parameters

Refer to [PassingParameters.cu](Programs/Chapter3/PassingParameters.cu).
This code introduces the following changes:
- We can pass parameters to a kernel as a regular C function in addition to the angular brackets information.
- *cudaMalloc()*
- *cudaMemcpy()*
- *cudaFree()*

We need to allocate memory to do anything on the device. *cudaMalloc()* which acts similarly to *malloc()* tells the CUDA runtime to allocate the memory on the device. 

**Important point**: it is the responsibility of the programmer not to dereference the pointer returned by *cudaMalloc()* from code that executes on the host. Host code may pass this pointer around, perform arithmetic on it, or even cast it to a different type. But you cannot use it to read or write from memory. The compiler cannot protect you from this mistake. The restriction summary is as follows:
- You **can pass** pointers allocated with *cudaMalloc()* to functions that execute on the device.
- You **can use** pointers allocated with *cudaMalloc()* to read or write memory from code that executes on the device.
- You **can pass** pointers allocated with *cudaMalloc()* to functions that execute on the host.
- You **cannot use** pointers allocated with *cudaMalloc()* to read or write memory from code that executes on the host.

**These points are applicable for host pointers as well.**

We cannot use the device memory locations directly to read or write in the host function and vice versa for host memory. We can copy the data to and from each memory. This is achieved by using cudaMemcpy(). The call is similar to a standard C function with an additional parameter:
- cudaMemcpyDeviceToHost: Copy device memory to the host.
- cudaMemcpyHostToDevice: Copy host memory to the device.
- cudaMemcpyDeviceToDevice: Both pointers are on the device.
- If the source and destination pointers are both on the host, we would simply use standard C’s *memcpy()*.

We use pointers from within the device code the same way we use them in standard C which runs on the host code. The statement *c = a + b is as simple as it looks.

To free the memory allocated by *cudaMalloc()*, we need to use a call to *cudaFree()*, which behaves exactly like *free()* does.

## Querying devices
Refer to [QueryingDevices.cu](Programs/Chapter3/QueryingDevices.cu).

Since we would like to be allocating memory and executing code on our device, it would be useful if our program had a way of knowing how much memory and what types of capabilities the device had. Furthermore, it is relatively common for people to have more than one CUDA-capable device per computer. In situations like this, we will want a way to determine which processor is which.

To get the count of CUDA devices we can use *cudaGetDeviceCount()* and iterate through each one of them to query relevant information. The CUDA runtime returns these properties in a structure of type *cudaDeviceProp*. It contains the following members:
```
 struct cudaDeviceProp 
 {
 char name[256];             // An ASCII string identifying the device (e.g., "GeForce GTX 280") 
 size_t totalGlobalMem;      // The amount of global memory on the device in bytes.
 size_t sharedMemPerBlock;   // The maximum amount of shared memory a single block may use in bytes.
 int regsPerBlock;           // The number of 32-bit registers available per block.
 int warpSize;               // The number of threads in a warp.
 size_t memPitch;            // The maximum pitch allowed for memory copies in bytes.
 int maxThreadsPerBlock;     // The maximum number of threads that a block may contain.
 int maxThreadsDim[3];       // The maximum number of threads allowed along each dimension of a block.
 int maxGridSize[3];         // The number of blocks allowed along each dimension of a grid.
 size_t totalConstMem;       // The amount of available constant memory.
 int major;                  // The major revision of the device’s compute capability.
 int minor;                  // The minor revision of the device’s compute capability.
 int clockRate;
 size_t textureAlignment;    // The device’s requirement for texture alignment.
 int deviceOverlap;          // A boolean value representing whether the device can simultaneously perform a cudaMemcpy() and kernel execution.
 int multiProcessorCount;    // The number of multiprocessors on the device.
 int kernelExecTimeoutEnabled;   // A boolean value representing whether there is a runtime limit for kernels executed on this device.
 int integrated;             // A boolean value representing whether the device is an integrated GPU (i.e., part of the chipset and not a discrete GPU).
 int canMapHostMemory;       // A boolean value representing whether the device can map host memory into the CUDA device address space.
 int computeMode;            // A value representing the device’s computing mode: default, exclusive, or prohibited.
 int maxTexture1D;           // The maximum size supported for 1D textures.
 int maxTexture2D[2];        // The maximum dimensions supported for 2D textures.
 int maxTexture3D[3];        // The maximum dimensions supported for 3D textures.
 int maxTexture2DArray[3];   // The maximum dimensions supported for 2D texture arrays.
 int concurrentKernels;      // A boolean value representing whether the device supports executing multiple kernels within the same context simultaneously.
 }
```
After running the referred code following is the printed output:
```
 --- General Information for device 0 ---
Name: NVIDIA T500
Compute capability: 7.5
Clock rate: 1560000
Device copy overlap: Enabled
Kernel execition timeout : Enabled
 --- Memory Information for device 0 ---
Total global mem: 3916300288 bytes
Total constant Mem: 65536 bytes
Max mem pitch: 2147483647 bytes
Texture Alignment: 512
 --- MP Information for device 0 ---
Multiprocessor count: 14
Shared mem per mp: 49152 bytes
Registers per mp: 65536
Threads in warp: 32
Max threads per block: 1024
Max thread dimensions: (1024, 1024, 64)
Max grid dimensions: (2147483647, 65535, 65535)
```

## Setting Devices
Refer to [SettingDevices.cu](Programs/Chapter3/SettingDevices.cu).

For our development, we might be interested in choosing the GPU with the most multiprocessors on which to run our code. Or if the kernel needs close interaction with the CPU, we might be interested in running our code on the integrated GPU that shares system memory with the CPU. These are both properties we can query with *cudaGetDeviceProperties()*.

Suppose that we are writing an application that depends on having double-precision floating-point support. After a quick consultation with Appendix A of the NVIDIA CUDA Programming Guide, we know that cards that have compute capability 1.3 or higher support double-precision floating-point math. So to successfully run the double-precision application that we’ve written, we need to find at least one device of compute capability 1.3 or higher.

Based on what we have seen with *cudaGetDeviceCount()* and *cudaGetDeviceProperties()*, we could iterate through each device and look for one that either has a major version greater than 1 or has a major version of 1 and a minor version greater than or equal to 3. But since this relatively common procedure is also relatively annoying to perform, the CUDA runtime offers us an automated way to do this. We first fill a *cudaDeviceProp* structure with the properties we need our device to have. After filling a *cudaDeviceProp* structure, we pass it to *cudaChooseDevice()* to have the CUDA runtime find a device that satisfies this constraint. The call to *cudaChooseDevice()* returns a device ID that we can then pass to *cudaSetDevice()*. From this point forward, all device operations will take place on the device we found in *cudaChooseDevice()*.


**Note**:  If your application depends on certain features of the GPU or depends on having the fastest GPU in the system, you should familiarize yourself with this API because there is no guarantee that the CUDA runtime will choose the best or most appropriate GPU for your application.

After running the referred code, the printed output is:
```
ID of current CUDA device: 0
ID of CUDA device closest to revision 1.3: 0
```