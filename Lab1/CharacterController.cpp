#include "CharacterController.h"


CharacterController::CharacterController()	// Constractor: declares speed
{
	speed = 0.1f;
	ySpeed = 0;
	xSpeed = 0;
	zSpeed = 0;
}


CharacterController::~CharacterController()
{
}

void CharacterController::setSpeed(float speed)	// speed Setter
{
	this->speed = speed;
}

void CharacterController::update()	// Update functino for character controller
{
	//Transforms object
	transform.Translate(glm::vec3(xSpeed, ySpeed, zSpeed));

	//Resets axis speeds
	ySpeed = 0;
	xSpeed = 0;
	zSpeed = 0;
}

//Processes input sets apropriate axis variable to be equal to the speed or negative speed
void CharacterController::input(SDL_Keycode *evnt)	//processes input
{
	switch (*evnt)
	{
	case SDLK_a:
		// A pressed
		xSpeed = speed;
		break;
	case SDLK_d:
		// D pressed
		xSpeed = -speed;
		break;
	case SDLK_s:
		// S pressed
		ySpeed = -speed;
		break;
	case SDLK_w:
		// W pressed
		ySpeed = speed;
		break;
	}
}