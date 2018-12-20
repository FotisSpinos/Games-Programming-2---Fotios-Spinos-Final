#pragma once
#include <SDL/SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <string>
using namespace std;


class Display
{
public:
	Display();	//Display constructor
	~Display();	//Display destractor
	void initDisplay();	//Initializes display
	void swapBuffer();	// Swaps buffers 
	void clearDisplay(float r, float g, float b, float a);	//Clears desplay

	float getWidth();	//Returns width
	float getHeight();	//Returns height

private:

	void returnError(std::string errorString);	//Error checking
	
	SDL_GLContext glContext; //global variable to hold the SDL context
	SDL_Window* sdlWindow; //holds pointer to out window
	float screenWidth;		// Holds the width of the window
	float screenHeight;		// Holds the height of the window
};

