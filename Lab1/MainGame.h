#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "GameObject.h"
#include "Scene.h"
#include "CharacterController.h"
#include "SceneManager.h"
#include "CollisionManager.h"

// The state of the game
enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	// Constructor 
	MainGame();

	// Destructor
	~MainGame();
	
	// Initializes game starts gameLoop
	void run();

private:
	//Initialize systems
	void initSystems();

	// GameLoop
	void gameLoop();

	// GameLoop methods 
	void processInput();
	void drawGame();
	void updateGame();
	void collisionCheck();
	void playSound();

	// The display of the game
	Display _gameDisplay;

	// The state of the game
	GameState _gameState;

	// The test scene of the application
	StartScene startScene;
	StartScene* startScenePtr;

	// The event polled and passed to other scene objects
	SDL_Event evnt;
	SDL_Event *evntptr;

	// Checks for collisions between scenes
	CollisionManager collisionManager;
	CollisionManager *collisionManagerPtr;
};

