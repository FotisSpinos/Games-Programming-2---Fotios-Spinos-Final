#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <string>
#include "obj_loader.h"

struct Vertex	//Class used to hold data about the meshe's / GameObject's postiion, rotation, scale
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord)	//Constructor setting the position texture coordinate and normal
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	glm::vec3* GetPos() { return &pos; }					// Returns a pointer to the object's position
	glm::vec2* GetTexCoord() { return &texCoord; }			// Returns a pointer to the object's tex coord
	glm::vec3* GetNormal() { return &normal; }				// Returns a pointer to the object's normal

private:
	glm::vec3 pos;											// Holds the position of the object
	glm::vec2 texCoord;										// Holds the texture coordinate of the object 
	glm::vec3 normal;										// Holds the normal of the object
};

class Mesh
{
public:
	Mesh();													// Class constructor													
	~Mesh();												// Class destructor (Clears data)

	void draw();											// Renders loaded model
	void loadModel(const std::string& filename);			// Loads model from file
	void initModel(const IndexedModel& model);				// Passes model data to the GPU

private:
	enum													//Enum of Buffer types
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	GLuint vertexArrayObject;								// Holds the number of vertices the mesh has
	GLuint vertexArrayBuffers[NUM_BUFFERS];					// Array holding the buffers used for mesh related functinos
	unsigned int drawCount;									// How much of the vertexArrayObject do we want to draw
};