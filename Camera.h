#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <cmath>
using namespace glm;

class Camera
{
public:
	// êîíñòðóêòîðû
	Camera();
	Camera(vec3 position);
	Camera(float x, float y, float z);
	// óñòàíîâêà è ïîëó÷åíèå ïîçèöèè êàìåðû
	void setPosition(vec3 position);
	vec3 getPosition();
	//ôóíêöèè äëÿ ïåðåìåùåíèÿ êàìåðû
	void rotateLeftRight(float degree);
	void rotateUpDown(float degree);
	void zoomInOut(float distance);
	// ôóíêöèÿ äëÿ óñòàíîâêè ìàòðèöû êàìåðû
	void apply();
private:
	// ïåðåðàñ÷åò ïîçèöèè êàìåðû ïîñëå ïîâîðîòîâ
	void recalculatePosition();
private:
	// ðàäèóñ è óãëû ïîâîðîòà
	float r;
	float angleX;
	float angleY;
	// ïîçèöèÿ êàìåðû
	vec3 position;
};
