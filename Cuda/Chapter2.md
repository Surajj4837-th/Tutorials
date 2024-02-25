# 2. Getting Started

## Development Environment
The prerequisites to developing code in CUDA C are as follows:
- A CUDA-enabled graphics processor
- An NVIDIA device driver
- A CUDA development toolkit
- A standard C compiler

**A CUDA-enabled graphics processor**: Graphics processor with inbuilt CUDA architecture is needed. Every NVIDIA GPU since the 2006 release of the GeForce 8800 GTX has been CUDA-enabled. 

**NVIDIA device driver**: NVIDIA provides system software that allows your programs to communicate with the CUDA-enabled hardware. If you have installed your NVIDIA GPU properly, you likely already have this software installed on your machine. Also you can check the officialwebsite for the latest update.

**A CUDA development toolkit**: If you want to develop code for NVIDIA GPUs using CUDA C, you will need additional software. Since your CUDA C applications are going to be computing on two different processors, you are consequently going to need two compilers. One compiler will compile code for your GPU, and one will compile code for your CPU. NVIDIA provides the compiler for your GPU code. This CUDA Toolkit is available on official website.

**A standard C compiler**: Recommended compilers:
1. Windows: MSVC C compiler for Windows
2. LINUX: GNU C compiler 
3. MACINTOSH OS X > v10.5.7: GNU C compiler 