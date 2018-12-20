#include "GameObject.h"

#pragma once
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	GameObject *gameObjects[10];	// Array holding all game objects checked for collisions


	int elementCounter;				// Number of elements stored in the array
	void setGameObject(GameObject *gameObject);		//Adds a gameObject to the array
	void checkForCollisions();		// Checks for collisions between elements in the array

	bool collisionDetection(GameObject *gameObj1, GameObject *gameObj2);	//returns true if a collision has beed detected
};

