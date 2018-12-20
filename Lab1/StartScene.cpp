#include "StartScene.h"

// Constructor
StartScene::StartScene()
{
}

// Destructor
StartScene::~StartScene()
{
}

// Holds the information of the scene before any gameObject updates or renders
void StartScene::editor()
{
	// Transform instances used to set the position, rotation and scale of gameObjects in the scene
	Transform transform1(glm::vec3(2.0f, 0.5f, 0), glm::vec3(0, 90, 0), glm::vec3(0.01f, 0.01f, 0.01f));
	Transform transform2(glm::vec3(-2.0f, -3.5f, 5), glm::vec3(0, 45, 0), glm::vec3(0.1f, 0.1f, 0.1f));
	Transform transform3(glm::vec3(0.0f, 0.5f, 0), glm::vec3(0, 0, 0), glm::vec3(0.1f, 0.1f, 0.1f));
	Transform transform4(glm::vec3(-2.0f, 0.5f, 0), glm::vec3(0, 90, 0), glm::vec3(0.1f, 0.1f, 0.1f));

	//Create GameObjects
	sceneObjPtr[objCounter]->setName("Pistol");
	createGameObject("M1911.obj", "ironTexture.jpg", "shader", transform1);

	sceneObjPtr[objCounter]->setName("Book 1");
	createGameObject("Sample_Book.obj", "_Old_Book_Cover_01.jpg", "shader", transform2);

	sceneObjPtr[objCounter]->setName("monkey 2");
	createGameObject("monkey3.obj", "bricks.jpg", "shader", transform4);

	// Create Character Controllers
	createCharacterController("monkey3.obj", "bricks.jpg", "shader", transform3);
}
