// CUDA basics
#include <stdio.h>
#include "Common/book.h"


__global__ void kernel(void)
{
    printf("Hello World!!!\n");
}


int main()
{
    kernel <<<1,1>>> ();

    cudaDeviceProp  prop;
    int dev;

    //Get current CUDA device properties.
    HANDLE_ERROR( cudaGetDevice( &dev ) );
    printf( "ID of current CUDA device:  %d\n", dev );

    //get CUDA device which is closest to revision 1.3
    memset( &prop, 0, sizeof( cudaDeviceProp ) );
    prop.major = 1;
    prop.minor = 3;
    HANDLE_ERROR( cudaChooseDevice( &dev, &prop ) );
    printf( "ID of CUDA device closest to revision 1.3:  %d\n", dev );

    //Set CUDA device
    HANDLE_ERROR( cudaSetDevice( dev ) );

    return 0;

}
/************************************Summary*****************************************
1. Cuda files are to be save with .cu extension.

2. __global__ qualifier informs compiler that the function should be compiled to run on 
   device instead of host.

3. 
************************************************************************************/