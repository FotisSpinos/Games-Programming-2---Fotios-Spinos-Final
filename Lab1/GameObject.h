#include "Display.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"

#pragma once

struct SphereCollider
{
	glm::vec3 position;	//Collider position
	float radius;		//Collder radious


	glm::vec3 *positionptr;	// position pointer
	float *radiusptr;		// radious pointer

	SphereCollider()		// Constructor sets pointers
	{
		positionptr = &position;
		radiusptr = &radius;
	}

	SphereCollider(glm::vec3 position, float radius) //Constructor sets position values and radious along with their respective pointers
	{ 
		positionptr = &position;
		radiusptr = &radius;

		this->position = position; this->radius = radius; 
	}

	void setPos(glm::vec3 position) { this->position = position; }	// Sets posiition value
	void setPosPtr(glm::vec3 *position) { this->positionptr = position; }	// Sets position pointer
	void setRad(float radius) { this->radius = radius; }	// Sets Radious

	glm::vec3 getPos() { return this->position; }	// Returns position value	
	float getRad() { return this->radius; }			// Returns radious value

	glm::vec3 *getPosPtr() { return this->positionptr; }	// returns position pointer
	float *getRadPtr() { return this->radiusptr; }			// returns radious pointer
};


class GameObject
{
public:
	GameObject();	//Constructor initializes object
	~GameObject();	//Destructor called when gameObject is swaped out of memory

	//Varialbes
	Mesh mesh;	// The mesh of the object
	Texture texture;	// The texture of the object
	Shader shader;		// The shader of the object
	Transform transform;	//The transform of the object
	SphereCollider meshSphere;	// The sphere collider of the object

	//Pointers to component varialbes
	Mesh* meshptr;
	Texture* textureptr;
	Shader* shaderptr;
	Transform* transformptr;
	Camera* camera;
	SphereCollider* meshSphereptr;

	// Initialize Varialbes
	void initObj(const std::string& meshFileName, const std::string& TexFileName, const std::string& shaderFileName, Camera &camera);	// Initializes Object
	void initMesh(const std::string& filename);	//Initializes mesh
	void initTexture(const std::string& fileName);	//Initializes texture
	void intitShader(const std::string& fileName);	//Initializes shader
	void initTransform(glm::vec3 pos, glm::vec3 rot, glm::vec3 scale);	//  initializes transform using three vectors for pos, rot and scale
	void initTransform(Transform &transform);	// initializes transform using transform parameter
	void setCamera(Camera &camera);	// Sets camera
	void declarePtrs();				// declare pointer class variables
	void SetActive(bool active);	// Sets active
	void setName(string name);	// Sets name value

	void collidedWith(GameObject *gameObject);	// handles collisions with GameObjects

	// Update State of Object
	virtual void update();	//updates object
	virtual void input() {}	// processes input

	// Render Object
	void render();	//Renders object
private:
	bool active;	// active status
	string name;	// name of the object
};