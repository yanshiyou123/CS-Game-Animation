#include "Curve.h"

Curve::Curve()
{
}

Curve::~Curve()
{
}

void Curve::init()
{
	this->control_points_pos = {
		{ 0.0, 8.5, -2.0 },
		{ -3.0, 11.0, 2.3 },
		{ -6.0, 8.5, -2.5 },
		{ -4.0, 5.5, 2.8 },
		{ 1.0, 2.0, -4.0 },
		{ 4.0, 2.0, 3.0 },
		{ 7.0, 8.0, -2.0 },
		{ 3.0, 10.0, 3.7 },
		{ 0.0, 8.5, -2.0 },
		{ -3.0, 11.0, 2.3 },
		{ -6.0, 8.5, -2.5 }
	};
}
glm::vec3 CatmullRom(glm::vec3 p0, glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, float t) {
	glm::vec3 a = -0.5f * p0 + 1.5f * p1 - 1.5f * p2 + 0.5f * p3;  
	glm::vec3 b = p0 - 2.5f * p1 + 2.0f * p2 - 0.5f * p3;          
	glm::vec3 c = -0.5f * p0 + 0.5f * p2;                           
	glm::vec3 d = p1;                                               

	return a * t * t * t + b * t * t + c * t + d;
}


void Curve::calculate_curve()
{
	
	
	this->curve_points_pos.clear();

	// Loop through control points, creating segments
	for (size_t i = 0; i < control_points_pos.size()-3; i++) {
		glm::vec3 P0 = control_points_pos[i];     // Control point before P1
		glm::vec3 P1 = control_points_pos[i + 1]; // Control point P1
		glm::vec3 P2 = control_points_pos[i + 2]; // Control point P2
		glm::vec3 P3 = control_points_pos[i + 3]; // Control point after P2

		
		
		// Interpolate points between P1 and P2
		for (int j = 0; j <= num_points; j++) {
			float t = j * step; // Calculate normalized parameter t [0, 1]
			glm::vec3 interpolated_point = CatmullRom(P0, P1, P2, P3, t);
			curve_points_pos.push_back(interpolated_point);
		}
	}
	
	

}

