#include "Data.h"
#include "MazeGenerator.h"
using namespace std;
using namespace glm;

void makeMap(int** matrix, int rows, int columns) {
	int arr[21][21] = { 0 };

	auto maze = MazeGenerator::generate(20, 20);

	//MazeGenerator::print(maze);

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 20; i++) {
			arr[i][j] = maze[i][j];
		}
	}

	// Устанавливаем границы
	for (int i = 0; i < 21; ++i) {
		arr[0][i] = 3;
		arr[21 - 1][i] = 3;
		arr[i][0] = 3;
		arr[i][21 - 1] = 3;
	}
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < columns; c++)
			matrix[r][c] = arr[r][c];
}

Camera camera;

LARGE_INTEGER ticks, ticksPerSecond, lastChech, currentTime, frequency;

Light light;
int passabilityMap[21][21] = {
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
 3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,0,0,0,3,
 3,0,2,1,2,0,2,0,2,2,2,1,2,0,2,0,2,0,2,2,3,
 3,0,2,0,2,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,3,
 3,0,1,0,2,2,1,2,2,0,2,0,2,2,2,1,2,0,2,0,3,
 3,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,2,0,3,
 3,0,2,2,1,1,2,0,2,0,2,2,2,2,2,0,2,2,2,0,3,
 3,0,2,0,0,0,2,0,2,0,0,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,0,2,2,1,2,2,2,1,2,2,0,3,
 3,0,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,0,1,0,3,
 3,2,2,2,2,0,2,2,2,0,2,0,2,2,2,2,2,2,2,0,3,
 3,0,0,0,2,0,0,0,1,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,0,2,2,2,0,2,1,2,0,2,2,2,0,2,2,2,2,3,
 3,0,2,0,0,0,2,0,0,0,2,0,0,0,2,0,2,0,0,0,3,
 3,2,2,2,2,0,2,2,2,0,2,2,2,0,1,0,2,2,2,0,3,
 3,0,0,0,0,0,2,0,2,0,0,0,2,0,1,0,0,0,2,0,3,
 3,0,2,0,2,1,2,0,2,0,2,2,2,0,2,2,2,0,2,0,3,
 3,0,1,0,1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,3,
 3,0,2,1,2,0,2,2,2,2,2,0,2,0,2,0,2,2,2,2,3,
 3,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0,3,
 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};
// ñïèñîê èãðîâûõ îáúåêòîâ ðàñïîëîæåííûõ íà êàðòå
shared_ptr<GameObject> mapObjects[21][21];
shared_ptr<GameObject> player;

// ãðàôè÷åñêèé îáúåêò äëÿ ïëîñêîñòè (÷àñòíûé ñëó÷àé)
GraphicObject planeGraphicObject;

// ôàáðèêà äëÿ ñîçäàíèÿ èãðîâûõ îáúåêòîâ
GameObjectFactory gameObjectFactory;

void initData() {
	QueryPerformanceCounter(&lastChech);
	QueryPerformanceFrequency(&frequency);
	int** matrix = new int* [21];
	for (int row = 0; row < 21; row++)
		matrix[row] = new int[21];
	makeMap(matrix, 21, 21);

	camera.setPosition({ 20, 30, 25 });
	light.setDiffuse({ 1,1,1,1 });
	light.setSpecular({ 1,1,1,1 });

	// èíèöèàëèçàöèÿ ôàáðèêè (â äàëüíåéøåì íà îñíîâå json-ôàéëà)
	gameObjectFactory.init("data//GameObjectsDescription.json");
	// èíèöèàëèçàöèÿ îáúåêòîâ ñöåíû
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			switch (matrix[i][j]) {
			case 1:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::LIGHT_OBJECT, i - 10, j - 10);
				break;
			case 2:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::HEAVY_OBJECT, i - 10, j - 10);
				break;
			case 3:
				mapObjects[i][j] = gameObjectFactory.create(GameObjectType::BORDER_OBJECT, i - 10, j - 10);
				break;
			default:
				mapObjects[i][j] = nullptr;
				break;
			}
		}
	}
	// èíèöèàëèçàöèÿ ãëàâíîãî ãåðîÿ
	player = gameObjectFactory.create(GameObjectType::PLAYER, 9, -9);
	// èíèöèàëèçàöèÿ ïëîñêîñòè
	planeGraphicObject.setPosition(vec3(0, -0.501, 0));
	shared_ptr<Mesh> planeMesh = make_shared<Mesh>();
	planeMesh->load("data\\meshes\\HighPolyPlane.obj");
	planeGraphicObject.setMesh(planeMesh);
	shared_ptr<PhongMaterial> planeMaterial = make_shared<PhongMaterial>();
	planeMaterial->load("data\\materials\\PlaneMaterial.txt");
	planeGraphicObject.setMaterial(planeMaterial);
	for (int row = 0; row < 21; row++)
		delete[] matrix[row];
	delete[] matrix;
}
