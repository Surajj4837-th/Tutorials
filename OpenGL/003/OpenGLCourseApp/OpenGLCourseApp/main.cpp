#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Window dimension
const GLint WIDTH = 800, HEIGHT = 600;


int main()
{
	//Initialize GLFW
	if (!glfwInit())
	{
		printf("GLFW initialization failed.");
		glfwTerminate();
		return 1;
	}

	printf("GLFW initialization successful.");

	//Setup GLFW window properties.
	//OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//How OpenGL is going to treat the code. 
	//GLFW_OPENGL_CORE_PROFILE - No backward compatibility.

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);	//Allow forward compatibility

	//create window
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test_Window", NULL, NULL);
	//Verify window creation
	if (!mainWindow)
	{
		printf("GLFW initialization failed.");
		glfwTerminate();
		return 1;
	}

	//Get buffer size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);	//Get the size of main window

	//Set the context for GLEW to use
	//Let the GLEW know that the window created here should be tied to OpenGL
	glfwMakeContextCurrent(mainWindow);
	// In case of multiple windows we can change the context to work on different windows.

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	//Initialize GLEW libraries
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialization failed.");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setuo viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))		//Keep looping until window close button is pressed
	{
		//Get and handle user input events
		glfwPollEvents();	//This will check if any events have occurred like keyboard or other

		// clear the window
		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);		//Clear entire screen and apply a color to it, range (0,1), last parameter is alpha
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
		//In OpenGL there are 2 frames, one that is seen by user and other is used to draw by developer
		//Then the frames are swapped
		//There can be more than 2 frames
		//Here we are swapping the buffers after drawing in above commands
	}

	return 0;
}
