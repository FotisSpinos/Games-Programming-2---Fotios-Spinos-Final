#pragma once
#include "GameObject.h"

class CharacterController : public GameObject
{
public:
	CharacterController();			// Constructor
	~CharacterController();			// Destructor

	void setSpeed(float speed);		// Sets the speed
	void update();					// Updates the object
	void input(SDL_Keycode *evnt);	// Processes input using the sld event parameter 

private:
	float xSpeed;	// x Axis speed
	float ySpeed;	// y Axis speed
	float zSpeed;	// z Axis speed

	float speed;	// xSpeed ySpeed and zSpeed are set to have the value of this variable on apropriate input
};

