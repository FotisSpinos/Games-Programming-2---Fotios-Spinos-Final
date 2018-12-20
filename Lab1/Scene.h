#pragma once
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "Camera.h"
#include "Display.h"
#include "CharacterController.h"
#include <string>
#include "Audio.h"

class Scene
{
public:
	Scene();	//Constructor 
	~Scene();	//Destructor

	void init(Display& display);	//Initializes scene

	GameObject sceneObj[10];	//Holds GameObjects the scene contains
	GameObject *sceneObjPtr[10];	//pointer to scene objects

	CharacterController sceneChar[10];	//Holds CharacterControllers the scene contains
	CharacterController *sceneCharPtr[10];	//pointer to scene objects

	void createGameObject(const std::string & meshFileName, const std::string & texFileName, const std::string & shaderFileName, Transform& transform);	//Creates GameObject
	void createCharacterController(const std::string & meshFileName, const std::string & texFileName, const std::string & shaderFileName, Transform& transform);	//Creates CharacterController

	virtual void editor();	//Rensponsible for creating GameObjects and CharacterControllers		

	string sceneName;
	string *sceneNamePtr;
	void SetSceneName(string &sceneName);

	virtual void render();	//Renders CharacterControllers and GameObjects of the scene
	virtual void update();	//Renders CharacterControllers and GameObjects of the scene
	virtual void input(SDL_Keycode *evnt);

	// Setters / Getters
	int *getObjCounter();	//Pointer to number of GameObjects
	int *getCharCounter();	//Pointer to number of CharacterControllers

	void initSound(string &fileName);
	void playSound();

protected:
	int objCounter;	//Number of GameObjects in the scene
	int charCounter;	//Number of CharacterControllers in the scene
private:
	Camera camera;		//Scene Camera
	Display *displayPtr;	// Pointer to gameDisplay

	Audio sound;	//The background sound of the scene
	Audio *sountPtr;	// Pointer to the sound variable
};