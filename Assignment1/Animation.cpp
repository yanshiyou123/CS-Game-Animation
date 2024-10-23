#include "Animation.h"

Animation::Animation()
{
	this->m_model_mat = glm::mat4(1.0f);
	this->x_angles;
	this->y_angles;
}

Animation::~Animation()
{
}

void Animation::init()
{
	reset();
}

void Animation::update(float delta_time)
{
	
}
void Animation::rotateLocalX() {
	
	glm::vec3 x_axis = glm::vec3(1.0f, 0.0f, 0.0f);
	float radian = glm::radians(x_angles);
	m_model_mat = glm::rotate(m_model_mat, radian, x_axis);
}
void Animation::rotateGlobalY() {
	glm::vec3 y_axis = glm::vec3(0.0f, 1.0f, 0.0f);  // Y Öá
	float radian = glm::radians(y_angles);
	
	m_model_mat = glm::translate(m_model_mat, glm::vec3(-5.0f, 0.0f, 0.0f));
	m_model_mat = glm::rotate(m_model_mat, radian, y_axis);
	m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0f, 0.0f, 0.0f));
	
}


void Animation::reset()
{
	m_model_mat = glm::mat4(1.0f);
	m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0f, 0.0f, 0.0f));
}
