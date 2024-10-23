#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	

class Bone_Animation
{
public:
	Bone_Animation();
	~Bone_Animation();

	void init();
	void update(float delta_time);
	void reset();
	glm::mat4 yellowRotate(glm::mat4 root_bone_obj_mat);
	glm::mat4 magentaRotate(glm::mat4 yellow);
	glm::mat4 cyanRotate(glm::mat4 magenta);

public:

	// Here the head of each vector is the root bone
	std::vector<glm::vec3> scale_vector;
	std::vector<glm::vec3> rotation_degree_vector;
	std::vector<glm::vec4> colors;

	glm::vec3 root_position;

	glm::mat4 yellow;
	glm::mat4 magenta;
	glm::mat4 cyan;
	glm::mat4 yellow_bone;
	glm::mat4 magenta_bone;
	


};