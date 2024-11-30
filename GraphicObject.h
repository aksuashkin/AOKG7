#pragma once
#include "GL/freeglut.h"
#include "Mesh.h"
#include "Material.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <memory>
#include <Windows.h>
using namespace glm;
using namespace std;
// КЛАСС ДЛЯ ПРЕДСТАВЛЕНИЯ ОДНОГО ГРАФИЧЕСКОГО ОБЪЕКТА
class GraphicObject
{
public:
	// Конструктор
	GraphicObject();
	// Установка и получение позиции объекта
	void setPosition(vec3 position);
	vec3 getPosition();
	// Установка и получения угла поворота в градусах
	// поворот осуществляется в горизонтальной плоскости
	// вокруг оси Oy по часовой стрелке
	void setAngle(float grad);
	float getAngle();
	// Установка текущего цвета объекта
	void setColor(vec3 color);
	vec3 getColor();
	// Установка используемого материала
	void setMaterial(shared_ptr<PhongMaterial> material);
	// Установка используемого меша
	void setMesh(shared_ptr<Mesh> mesh);
	// Вывести объект
	void draw();
private:
	// Позиция объекта в глобальной системе координат
	vec3 position;
	// Угол поворота в горизонтальной плоскости (в градусах)
	float angle;
	// Цвет модели
	vec3 color;
	// Матрица модели - чтоб не вычислять каждый раз
	mat4 modelMatrix;
	// Используемый материал
	shared_ptr<PhongMaterial> material;
	// Используемый меш
	shared_ptr<Mesh> mesh;
private:
	// расчет матрицы modelMatrix на основе position и angle
	void recalculateModelMatrix();
};
