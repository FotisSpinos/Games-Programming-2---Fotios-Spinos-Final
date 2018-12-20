#pragma once
#include <string>
#include <GL\glew.h>
#include "transform.h"
#include "Camera.h"

class Shader
{
public:
	//Constructor 
	Shader();

	void Bind(); //Set gpu to use our shaders
	void Update(const Transform& transform, const Camera& camera);	//updates shader
	void init(const std::string& filename);	//initializes shader

	std::string Shader::LoadShader(const std::string& fileName);	//loads shader
	void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);	//Error check method
	GLuint Shader::CreateShader(const std::string& text, unsigned int type);	// Creates Shader

	//Destructor 
    ~Shader();


protected:
private:
	static const unsigned int NUM_SHADERS = 2; // number of shaders

	enum
	{
		TRANSFORM_U,
		NUM_UNIFORMS
	};

	GLuint program; // Track the shader program
	GLuint shaders[NUM_SHADERS]; //array of shaders
	GLuint uniforms[NUM_UNIFORMS]; //no of uniform variables
};
