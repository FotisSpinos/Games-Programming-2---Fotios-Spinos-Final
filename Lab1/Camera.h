#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera()	//Camera constructor
	{
	}

	// Initializes camera sets position, forward, up and projection class variables
	void initCamera(const glm::vec3& pos, float fov, float aspect, float nearClip, float farClip)
	{
		this->pos = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, nearClip, farClip);
	}

	// Returns view projection
	inline glm::mat4 GetViewProjection() const
	{
		return projection * glm::lookAt(pos, pos + forward, up);
	}

	// Moves object forward
	void MoveForward(float amt)
	{
		pos += forward * amt;
	}

	// Moves object right
	void MoveRight(float amt)
	{
		pos += glm::cross(up, forward) * amt;
	}

	// Rotates angle on the y axis 
	void RotateY(float angle)
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

	// Returns Position
	glm::vec3 getPos()
	{
		return pos;
	}

	// Returns forward direction
	glm::vec3 getForward()
	{
		return forward;
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};


