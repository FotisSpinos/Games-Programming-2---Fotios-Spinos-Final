#pragma once
#include <vector>
#include "Scene.h"
#include "SceneManager.h"
#include "StartScene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	int sceneIndex;

	vector<Scene> scenes;
	vector<string> flowControl;
	void initialize();
	void initializeScenes();
	Scene *GetRunningScene();
};

