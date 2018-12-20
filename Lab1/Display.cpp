#include "Display.h"

// Sets sdlWindow, screenWidth, screenHeight
Display::Display()
{
	sdlWindow = nullptr; //initialise to generate null access violation for debugging. 
	screenWidth = 1024.0f;
	screenHeight = 768.0f; 
}

Display::~Display()
{
	SDL_GL_DeleteContext(glContext); // delete context
	SDL_DestroyWindow(sdlWindow); // detete window (make sure to delete the context and the window in the opposite order of creation in initDisplay())
	SDL_Quit();
}

float Display::getWidth() { return screenWidth; } // returns screen Width
float Display::getHeight() { return screenHeight; }	// returns screenHeight

void Display::returnError(std::string errorString)	// returns error
{
	std::cout << errorString << std::endl;
	std::cout << "press any  key to quit...";
	int in;
	std::cin >> in;
	SDL_Quit();
}

void Display::swapBuffer()
{
	SDL_GL_SwapWindow(sdlWindow); //swap buffers
}

void Display::clearDisplay(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear colour and depth buffer - set colour to colour defined in glClearColor
}

void Display::initDisplay()
{
	SDL_Init(SDL_INIT_EVERYTHING); //initalise everything

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8); //Min no of bits used to diplay red colour
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);	// Min no of bits used to diplay green colour
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);	// Min no of bits used to diplay blue colour
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);// set up z-buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); // set up double buffer   

	sdlWindow = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)screenWidth, (int)screenHeight, SDL_WINDOW_OPENGL); // create window

	if (sdlWindow == nullptr)	//Checks if the window instance is null
	{
		returnError("window failed to create");
	}

	glContext = SDL_GL_CreateContext(sdlWindow);

	if (glContext == nullptr)	// Checks if context is null
	{
		returnError("SDL_GL context failed to create");
	}

	GLenum error = glewInit();	// Chekcs if glew is null
	if (error != GLEW_OK)
	{
		returnError("GLEW failed to initialise");
	}

	glEnable(GL_DEPTH_TEST); //enable z-buffering 
	glEnable(GL_CULL_FACE); //dont draw faces that are not pointing at the camera

	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);	// sets clear colour values
}