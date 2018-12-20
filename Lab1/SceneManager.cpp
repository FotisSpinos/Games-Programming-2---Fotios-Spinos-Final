#include "SceneManager.h"



SceneManager::SceneManager()
{
	sceneIndex = 0;
}


SceneManager::~SceneManager()
{
}

void SceneManager::initialize()
{
	flowControl.push_back("StartScene");
	flowControl.push_back("MainScene");
	flowControl.push_back("EndScene");

	StartScene startScene;

	scenes.push_back(startScene);
	scenes.push_back(startScene);
	scenes.push_back(startScene);
}

void SceneManager::initializeScenes()
{

}

Scene * SceneManager::GetRunningScene()
{
	return &scenes[sceneIndex];
}
