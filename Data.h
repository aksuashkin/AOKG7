#pragma once
#include "Camera.h"
#include "GL/freeglut.h"
#include "GraphicObject.h"
#include "Light.h"
#include "Material.h"
#include <fstream>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include<iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <windows.h>
#include "Mesh.h"
#include "GameObject.h"
#include "GameObjectFactory.h"
using namespace std;
using namespace glm;

extern vector<GraphicObject> graphicObjects;
extern vector<shared_ptr<PhongMaterial>> materials;

extern Camera camera;
extern LARGE_INTEGER ticks, ticksPerSecond, lastChech, currentTime, frequency;
extern Light light;
extern vector<shared_ptr<Mesh>> meshes;
extern int passabilityMap[21][21];
// êàðòà ïðîõîäèìîñòè

// ñïèñîê èãðîâûõ îáúåêòîâ ðàñïîëîæåííûõ íà êàðòå
extern shared_ptr<GameObject> mapObjects[21][21];
extern shared_ptr<GameObject> player;
// ãðàôè÷åñêèé îáúåêò äëÿ ïëîñêîñòè (÷àñòíûé ñëó÷àé)
extern GraphicObject planeGraphicObject;
extern GameObjectFactory gameObjectFactory;
void initData(); 
