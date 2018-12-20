#include "MainGame.h"
#include "Camera.h"
#include <iostream>
#include <string>
#include <vector>
#include "Scene.h"

// Constructor initializes the game states and class pointers
MainGame::MainGame()
{
	_gameState = GameState::PLAY;
	startScenePtr = &startScene;
	collisionManagerPtr = &collisionManager;
}

// Destructor called when the object is deleted
MainGame::~MainGame(){}

// Initializes game starts gameLoop
void MainGame::run()
{
	initSystems(); 
	gameLoop();
}

// Initializes objects used in the game Alogn with the SDL libraries
void MainGame::initSystems()
{
	_gameDisplay.initDisplay(); 

	string soundName = "background.wav";
	startScenePtr->initSound(soundName);

	startScenePtr->init(_gameDisplay);
	startScenePtr->editor();

	for (int i = 0; i < *startScenePtr->getObjCounter(); i++)
	{
		collisionManagerPtr->setGameObject(startScene.sceneObjPtr[i]);
	}

	for (int i = 0; i < *startScenePtr->getCharCounter(); i++)
	{
		collisionManagerPtr->setGameObject(startScenePtr->sceneCharPtr[i]);
	}
}

// The Game Loop: one each function call the system passes input to gameObjects, renders the scene
// updates each gameObject, checks for collisions between game Objects and plays the scenes sound
void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)	// Checks if the application's game state is not equal to exit
	{
		processInput();
		drawGame();
		updateGame();
		collisionCheck();
		playSound();
	}
}

// Stores the pushed SDL event. Passes Input to the scenes object.
void MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				startScenePtr->input(&evnt.key.keysym.sym);
				break;
		}
	}
}

// Renders scene objects
void MainGame::drawGame()
{
	_gameDisplay.clearDisplay(0.0f, 0.0f, 0.0f, 1.0f);


	startScenePtr->render();

	// Render Game Objects
	
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
}

// updates scene objects
void MainGame::updateGame()
{	
	startScenePtr->update();
}

// checks for collisions between scene objects
void MainGame::collisionCheck()
{
	collisionManagerPtr->checkForCollisions();
}

// Plays scene sounds
void MainGame::playSound()
{
	startScenePtr->playSound();
}
