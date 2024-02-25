# 2. Getting Started

## Development Environment
The prerequisites to developing code in CUDA C are as follows:
- A CUDA-enabled graphics processor
- An NVIDIA device driver
- A CUDA development toolkit
- A standard C compiler

**A CUDA-enabled graphics processor**: Graphics processor with inbuilt CUDA architecture is needed. Every NVIDIA GPU since the 2006 release of the GeForce 8800 GTX has been CUDA-enabled. 

**NVIDIA device driver**: NVIDIA provides system software that allows your programs to communicate with the CUDA-enabled hardware. If you have installed your NVIDIA GPU properly, you likely already have this software installed on your machine. Also, you can check the official website for the latest update.

**A CUDA development toolkit**: If you want to develop code for NVIDIA GPUs using CUDA C, you will need additional software. Since your CUDA C applications are going to be computing on two different processors, you are consequently going to need two compilers. One compiler will compile code for your GPU, and one will compile code for your CPU. NVIDIA provides the compiler for your GPU code. This CUDA Toolkit is available on official website.

**A standard C compiler**: Recommended compilers:
1. Windows: MSVC C compiler for Windows
2. LINUX: GNU C compiler 
3. MACINTOSH OS X > v10.5.7: GNU C compiler 


## Install pre-requisites on Ubuntu
1. I am using HP Zbook laptop which has NVIDIA T500 GPU.
2. I am working on Ubuntu 20.04. Follow the steps to install NVIDIA driver.
   1. To check the available drivers on your Ubuntu system, run the following command:
        > sudo ubuntu-drivers list
   2. Install the drivers:
        > sudo ubuntu-drivers install  

        Or you can tell the system which version to install. Let’s assume we want to install the 525 driver:  
        > sudo ubuntu-drivers install nvidia:525

3. NVIDIA toolkit installation: Go to the official website [link](https://developer.nvidia.com/cuda-downloads) and select the required configurations to get commands and steps to install the toolkit.
4. Command to show drivers in use:
    > nvidia-smi
5. A standard GCC compiler is present in Ubuntu OS by default.