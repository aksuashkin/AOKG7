#pragma once
#include <iostream>
#include<iomanip>
#include <vector>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include <fstream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <memory>
#include <string>
#include <sstream>
#include <map>
using namespace std;
using namespace glm;
struct Vertex
{
	// ãåîìåòðè÷åñêèå êîîðäèíàòû
	vec3 coord;
	// âåêòîð íîðìàëè
	vec3 normal;
	// òåêñòóðíûå êîîðäèíàòû íóëåâîãî òåêñòóðíîãî áëîêà 
	vec3 texCoord;
};


class Mesh
{
public:
	// êîíñòðóêòîð
	Mesh();
	// çàãðóçêà ìåøà èç ôàéëà ñ óêàçàííûì èìåíåì
	void load(std::string filename);
	// âûâîä ìåøà (ïåðåäà÷à âñåõ âåðøèí â OpenGL)
	void draw();
private:
	// ìàññèâ âåðøèí ïîëèãîíàëüíîé ñåòêè
	vector<Vertex> vertices;
	vector<GLuint> indices;
};
