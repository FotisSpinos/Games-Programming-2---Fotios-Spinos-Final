#include "CollisionManager.h"


// Initializes class variables
CollisionManager::CollisionManager()
{
	elementCounter = 0;
}

//Destructor
CollisionManager::~CollisionManager()
{
}

//stores an object from the scene to the object
void CollisionManager::setGameObject(GameObject *gameObject)
{
	gameObjects[elementCounter] = gameObject;
	elementCounter++;
}

//Iterates theough every stored object and checks for collisions
void CollisionManager::checkForCollisions()
{
	for (int x = 0; x < elementCounter; x++)
	{
		for (int y = 0; y < elementCounter; y++)
		{
			if (collisionDetection(gameObjects[x], gameObjects[y]))
			{
				gameObjects[x]->collidedWith(gameObjects[y]);
			}
		}
	}
}

// checks a collision between two game objects occurs
bool CollisionManager::collisionDetection(GameObject *gameObj1, GameObject *gameObj2)
{
	if (gameObj1 == gameObj2)
		return false;

	//Records object position and rotation
	glm::vec3 m2Pos = *gameObj2->transformptr->GetPos();
	glm::vec3 m1Pos = *gameObj1->transformptr->GetPos();
	float m1Rad = *gameObj1->meshSphereptr->getRadPtr();
	float m2Rad = *gameObj2->meshSphereptr->getRadPtr();

	//Culculates the distance
	float dist = glm::sqrt(glm::pow((m2Pos.x - m1Pos.x), 2) + glm::pow((m2Pos.y - m1Pos.y), 2) + glm::pow((m2Pos.z - m1Pos.z), 2));

	if (dist <= m1Rad + m2Rad)
	{
		return true;
	}
	return false;
}