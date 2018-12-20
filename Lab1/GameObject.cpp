#include "GameObject.h"
#include <iostream>

// Class constructor
GameObject::GameObject()
{
	declarePtrs();
	name = "Empty Game Object";
}

// Class destructor
GameObject::~GameObject()
{
	cout << "GameOBj destroyed: " + name << endl;
}

// Initializes gameObjects Sets pointers, initializes variables, sets radious for the sphere collider and sets the active status to true
void GameObject::initObj(const std::string & meshFileName, const std::string & texFileName, const std::string & shaderFileName, Camera &camera)
{
	declarePtrs();

	GameObject::initMesh(meshFileName);
	GameObject::initTexture(texFileName);
	GameObject::intitShader(shaderFileName);
	GameObject::initTransform(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0.1f, 0.1f, 0.1f));
	GameObject::setCamera(camera);

	meshSphereptr->setRad(0.6f);
	active = true;
}

// initializes mesh
void GameObject::initMesh(const std::string& filename)
{
	meshptr->loadModel(filename);
}

// initializes texture
void GameObject::initTexture(const std::string& fileName)
{
	textureptr->init(fileName);
}

//Initializes shader
void GameObject::intitShader(const std::string& fileName)
{
	shaderptr->init(fileName); //new shader
}

// Sets transform position rotation and scale
void GameObject::initTransform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale)
{
	transformptr->SetPos(pos);
	transformptr->SetRot(rot);
	transformptr->SetScale(scale);
}

// Initializes transform
void GameObject::initTransform(Transform &transform)
{
	this->transform = transform;
}

// Sets Game Camera
void GameObject::setCamera(Camera &camera)
{
	GameObject::camera = &camera;
}

// Declares pointers using their coresponding class variables
void GameObject::declarePtrs()
{
	meshptr = &mesh;
	textureptr = &texture;
	shaderptr = &shader;
	transformptr = &transform;
	meshSphereptr = &meshSphere;
}

// Sets active
void GameObject::SetActive(bool active)
{
	this->active = active;
}

void GameObject::setName(string name)	// no need for rederence a string which is not stored is passed
{
	this->name = name;
}

// defines collision action and passes a pointer to the collided game object
void GameObject::collidedWith(GameObject* gameObject)
{
	cout << name << " collided with: " << gameObject->name << endl;
}

// Renders if 
void GameObject::render()
{
	if (active)	//renders if object is active
	{
		shaderptr->Bind();	//Binds shader pointer
		shaderptr->Update(*transformptr, *camera);
		textureptr->Bind(0);	// Unbinds texture pointer
		meshptr->draw();		// Draws mesh
	}
}

// Updates GameObject
void GameObject::update()
{
	meshSphereptr->setPosPtr(transformptr->GetPos());
}
