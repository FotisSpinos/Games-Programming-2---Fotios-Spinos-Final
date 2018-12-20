#include "Scene.h"

// Initializes class variables
Scene::Scene()
{
	objCounter = 0;
	sceneName = "";
	sceneNamePtr = &sceneName;
	sountPtr = &sound;

	// Sets array pointer elements
	for (int i = 0; i < size(sceneObjPtr); i++)
	{
		sceneObjPtr[i] = &sceneObj[i];
	}

	for (int i = 0; i < size(sceneCharPtr); i++)
	{
		sceneCharPtr[i] = &sceneChar[i];
	}
}

Scene::~Scene()
{
}

// Initializes the display
void Scene::init(Display &display)
{
	if (&display != nullptr)
	{
		camera.initCamera(glm::vec3(0, 0, -5), 70.0f, (float)display.getWidth() / display.getHeight(), 0.01f, 1000.0f);
		this->displayPtr = &display;
	}
	else
		std::cout << "Display reference is empty";
}

// Creates and stores game object
void Scene::createGameObject(const std::string & meshFileName, const std::string & texFileName, const std::string & shaderFileName, Transform& transform)
{
	if (objCounter < size(sceneObjPtr))
	{
		sceneObjPtr[objCounter]->initObj(meshFileName, texFileName, shaderFileName, camera);
		sceneObjPtr[objCounter]->initTransform(transform);

		objCounter++;
	}
}

// Creates and stores Character controller
void Scene::createCharacterController(const std::string & meshFileName, const std::string & texFileName, const std::string & shaderFileName, Transform & transform)
{
	if (charCounter < size(sceneObjPtr))
	{
		sceneCharPtr[charCounter]->initObj(meshFileName, texFileName, shaderFileName, camera);
		sceneCharPtr[charCounter]->initTransform(transform);

		string name = "Character Controller: " + charCounter;
		sceneCharPtr[charCounter]->setName(name);

		charCounter++;
	}
}

// Contains the state of every sceen object before any function is called in the game loop 
void Scene::editor()
{
	cout << "Default Editor is running";

	//Transform components
	Transform transform1(glm::vec3(0.1f, 0.7f, 0.0f), glm::vec3(0, 90, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	Transform transform2(glm::vec3(1.0f, 0.5f, 0), glm::vec3(0, 180, 0), glm::vec3(0.1f, 0.1f, 0.1f));
	Transform transform3(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.1f, 0.1f, 0.1f));
	Transform transform4(glm::vec3(1.7, 0.5f, 0), glm::vec3(0, 0, 0), glm::vec3(0.1f, 0.1f, 0.1f));

	// Create GameObjects
	createGameObject("Sample_Book.obj", "Book.jpg", "shader", transform1);
	sceneObjPtr[0]->setName("monkey 1");
	createGameObject("monkey3.obj", "ironTexture.jpg", "shader", transform2);
	sceneObjPtr[1]->setName("monkey 2");

	// Create CharacterControllers
	createCharacterController("monkey3.obj", "Water.jpg", "shader", transform3);
}

// Sets Scene Name
void Scene::SetSceneName(string &sceneName)
{
	sceneNamePtr = &sceneName;
}

// Renders scene Objects
void Scene::render()
{
	// Render Game Objects
	for (int i = 0; i < size(sceneObjPtr); i++)
	{
		sceneObjPtr[i]->render();
	}

	// Render Characters
	for (int x = 0; x < size(sceneCharPtr); x++)
	{
		sceneCharPtr[x]->render();
	}
}

// Updates scene objects
void Scene::update()
{
	// Render Game Objects
	for (int i = 0; i < size(sceneObjPtr); i++)
	{
		sceneObjPtr[i]->update();
	}

	// Render Characters
	for (int x = 0; x < size(sceneCharPtr); x++)
	{
		sceneCharPtr[x]->update();
	}
}

// Passses the input to all character controllers
void Scene::input(SDL_Keycode *evnt)
{
	for (int x = 0; x < size(sceneCharPtr); x++)
	{
		sceneCharPtr[x]->input(evnt);
	}
}

// object counter pointer getter
int * Scene::getObjCounter()
{
	return &objCounter;
}

// character counter pointer getter
int * Scene::getCharCounter()
{
	return &charCounter;
}

// Sets listener and loads sound from the fileName parameter
void Scene::initSound(string &fileName)
{
	sountPtr->setlistener(camera.getPos(), camera.getForward());

	string soundPath = "..\\res\\Music\\" + fileName;


	sountPtr->loadSound(soundPath.c_str());
}

// Plays sound in the scene 
void Scene::playSound()
{
	sountPtr->playSound(1);
}
