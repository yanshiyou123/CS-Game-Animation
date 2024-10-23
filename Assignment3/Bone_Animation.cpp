#include "Bone_Animation.h"



Bone_Animation::Bone_Animation()
{
}


Bone_Animation::~Bone_Animation()
{
}

void Bone_Animation::init()
{
	root_position = { 2.0f,1.0f,2.0f };
	scale_vector =
	{
		{1.0f,1.0f,1.0f},
		{0.5f,4.0f,0.5f},
		{0.5f,3.0f,0.5f},
		{0.5f,2.0f,0.5f}
	};

	rotation_degree_vector =
	{
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f}
	};

	colors =
	{
		{0.7f,0.0f,0.0f,1.0f},
		{0.7f,0.7f,0.0f,1.0f},
		{0.7f,0.0f,0.7f,1.0f},
		{0.0f,0.7f,0.7f,1.0f}
	};



}



glm::mat4 Bone_Animation::yellowRotate(glm::mat4 root_bone_obj_mat) {
	yellow = root_bone_obj_mat;
	float b = scale_vector[0][1] * 0.5f;
	float s = scale_vector[0][1] * 0.5f + scale_vector[1][1] * 0.5;
	yellow = glm::translate(yellow, glm::vec3(0.0f, b, 0.0f));
	yellow = glm::rotate(yellow, glm::radians(rotation_degree_vector[1][0]), glm::vec3(1.0, 0.0, 0.0));
	yellow = glm::rotate(yellow, glm::radians(rotation_degree_vector[1][1]), glm::vec3(0.0, 1.0, 0.0));
	yellow = glm::rotate(yellow, glm::radians(rotation_degree_vector[1][2]), glm::vec3(0.0, 0.0, 1.0));
	yellow = glm::translate(yellow, glm::vec3(0.0f, -b, 0.0f));
	yellow = glm::translate(yellow, glm::vec3(0.0f, s, 0.0f));
	yellow_bone = yellow;
	yellow = glm::scale(yellow, scale_vector[1]);
	return yellow;
}

glm::mat4 Bone_Animation::magentaRotate(glm::mat4 yellow) {
	magenta = yellow;
	float b = scale_vector[1][1] * 0.5f;
	float s = scale_vector[1][1] * 0.5f + scale_vector[2][1] * 0.5f;
	magenta = glm::translate(magenta, glm::vec3(0.0f, b, 0.0f));
	magenta = glm::rotate(magenta, glm::radians(rotation_degree_vector[2][0]), glm::vec3(1.0, 0.0, 0.0));
	magenta = glm::rotate(magenta, glm::radians(rotation_degree_vector[2][1]), glm::vec3(0.0, 1.0, 0.0));
	magenta = glm::rotate(magenta, glm::radians(rotation_degree_vector[2][2]), glm::vec3(0.0, 0.0, 1.0));
	magenta = glm::translate(magenta, glm::vec3(0.0f, -b, 0.0f));
	magenta = glm::translate(magenta, glm::vec3(0.0f, s, 0.0f));
	magenta_bone = magenta;
	magenta = glm::scale(magenta, scale_vector[2]);
	return magenta;
}


glm::mat4 Bone_Animation::cyanRotate(glm::mat4 magenta) {
	cyan = magenta;
	float b = scale_vector[2][1] * 0.5f;
	float s = scale_vector[2][1] * 0.5f + scale_vector[3][1] * 0.5f;
	cyan = glm::translate(cyan, glm::vec3(0.0f, b, 0.0f));
	cyan = glm::rotate(cyan, glm::radians(rotation_degree_vector[3][0]), glm::vec3(1.0, 0.0, 0.0));
	cyan = glm::rotate(cyan, glm::radians(rotation_degree_vector[3][1]), glm::vec3(0.0, 1.0, 0.0));
	cyan = glm::rotate(cyan, glm::radians(rotation_degree_vector[3][2]), glm::vec3(0.0, 0.0, 1.0));
	cyan = glm::translate(cyan, glm::vec3(0.0f, -b, 0.0f));
	cyan = glm::translate(cyan, glm::vec3(0.0f, s, 0.0f));
	cyan = glm::scale(cyan, scale_vector[3]);
	return cyan;
}

void Bone_Animation::update(float delta_time) {


}




void Bone_Animation::reset()
{
	rotation_degree_vector =
	{
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f},
		{0.0f,0.0f,0.0f}
	};
}

