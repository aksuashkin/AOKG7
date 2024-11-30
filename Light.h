#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
using namespace glm;
using namespace std;
// ÊËÀÑÑ ÄËß ÐÀÁÎÒÛ Ñ ÈÑÒÎ×ÍÈÊÎÌ ÑÂÅÒÀ
class Light
{
public:
	// êîíñòðóêòîðû
	Light();
	Light(vec3 position);
	Light(float x, float y, float z);
	// çàäàíèå ðàçëè÷íûõ ïàðàìåòðîâ èñòî÷íèêà ñâåòà
	void setPosition(vec3 position);
	void setAmbient(vec4 color);
	void setDiffuse(vec4 color);
	void setSpecular(vec4 color);
	// óñòàíîâêà âñåõ ïàðàìåòðîâ èñòî÷íèêà ñâåòà ñ çàäàííûì íîìåðîì
	// äàííàÿ ôóíêöèÿ äîëæíà âûçûâàòüñÿ ïîñëå óñòàíîâêè êàìåðû,
	// ò.ê. çäåñü óñòàíàâëèâàåòñÿ ïîçèöèÿ èñòî÷íèêà ñâåòà
	void apply(GLenum LightNumber);
private:
	// ïîçèöèÿ èñòî÷íèêà ñâåòà
	vec4 position;
	// ôîíîâàÿ ñîñòàâëÿþùàÿ èñòî÷íèêà ñâåòà
	vec4 ambient;
	// äèôôóçíàÿ ñîñòàâëÿþùàÿ
	vec4 diffuse;
	// çåðêàëüíàÿ ñîñòàâëÿþùàÿ
	vec4 specular;
};
