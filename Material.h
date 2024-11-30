#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using namespace glm;
using namespace std;
// ÊËÀÑÑ ÄËß ÐÀÁÎÒÛ Ñ ÌÀÒÅÐÈÀËÎÌ
class PhongMaterial
{
public:
	// êîíñòðóêòîð ïî óìîë÷àíèþ
	PhongMaterial();
	// çàäàíèå ïàðàìåòðîâ ìàòåðèàëà
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	void setEmission(vec4 color);
	void setShininess(float p);
	// çàãðóçêà ïàðàìåòðîâ ìàòåðèàëà èç âíåøíåãî òåêñòîâîãî ôàéëà
	void load(std::string filename);
	// óñòàíîâêà âñåõ ïàðàìåòðîâ ìàòåðèàëà
	void apply();
private:
	// ôîíîâàÿ ñîñòàâëÿþùàÿ 
	vec4 ambient;
	// äèôôóçíàÿ ñîñòàâëÿþùàÿ
	vec4 diffuse;
	// çåðêàëüíàÿ ñîñòàâëÿþùàÿ
	vec4 specular;
	// ñàìîñâå÷åíèå
	vec4 emission;
	// ñòåïåíü îòïîëèðîâàííîñòè
	float shininess;
};
