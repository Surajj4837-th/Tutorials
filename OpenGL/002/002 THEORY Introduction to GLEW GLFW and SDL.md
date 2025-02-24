### GLEW
* OpenGL extension wrangler.
* Helps in interfacing with modern OpenGL versions i.e. above 1.1.
* Load OpenGL extensions.
* Some extensions are platform specific, GLEW can check if they exist on that platform.
* Alternatives: GL3W , glLoadGen, glad, glsdk, glbinding, libepoxy, Glee.
* Use GLEW: `#include <GL/glew.h>`
* After initialisation of OpenGL context: `glewExperimental = GL_TRUE;`
This is used for allowing to access the modern features of GLEW which are not activated ptherwise.
* Initialise GLEW: `glewInit();`
It should return GLEW_OK if successful else error. Error can be read using `glewGetErrorString(result);`
* Some extensions are platform specific (Windows, Unix, Mac, etc.). To check extensions exist: `if(!GLEW_EXT_framebuffer_object){}`
* **wglew.h** is a header file specially for Windows only functions.

### GLFW
* Inorder to create a context for GLEW code to work we need GLFW library. This context is needed for OpenGL to interact.
* It handles window creation and control. When a window is created in display, GLFW defines its properties like size, period, etc and the content.
* It allows pickup and process input from the keyboard, mouse, joystick and gamepad.
* It also allows multiple monitor support.
* It uses OpenGL context for windows(not to be mistaken with Windows OS).
* SDL (Simple directmedia layer) is the alternative to GLFW:
  - Can do almost everything as GLFW.
  - Audio, threading, filesystems, etc.
  - Very popular.
  - Used in games.
  - Used in level editors for Source Engine and Cryengine.
  - SDL allows more than GLFW but for this course we do not need that many features.
* Other alternative:
    - SMFL(Simple and fast multimedia library): Based on 2D graphics only
    - GLUT (OpenGL utility toolkit): No longer maintained. Avoid.
    - Win32 API: Lowest level for window creation.