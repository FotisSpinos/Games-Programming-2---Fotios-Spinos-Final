#pragma once
#include <string>
#include <GL\glew.h>

class Texture
{
public:
	// Condtructor, initializes texture
	Texture();

	void Bind(unsigned int unit); // bind upto 32 textures

	//Initializes texture using the path to its location
	void init(const std::string& fileName);	

	//Clears texture data
	~Texture();

protected:
private:

	//The variable representing texture data
	GLuint textureHandler;
};

