#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();	//Constructor
	~StartScene();	//Destructor 

	// Overites the parent method editor
	void editor();
};

