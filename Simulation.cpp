#include "Simulation.h"

float getFPS() {
	long long oldTicks = ticks.QuadPart;
	QueryPerformanceCounter(&ticks);
	long long newTicks = ticks.QuadPart - oldTicks;
	QueryPerformanceFrequency(&ticksPerSecond);
	float rez = ticksPerSecond.QuadPart / newTicks;
	return rez;
}

void simulation()
{
	int fps = getFPS();
	QueryPerformanceCounter(&currentTime);
	if (currentTime.QuadPart - lastChech.QuadPart > frequency.QuadPart) {

		glutSetWindowTitle(to_string(fps).c_str());
		QueryPerformanceCounter(&lastChech);
	}

	// óñòàíàâëèâàåì ïðèçíàê òîãî, ÷òî îêíî íóæäàåòñÿ â ïåðåðèñîâêå
	keyboard();
	// ýòà æå ôóíêöèÿ áóäåò âûçâàíà åùå ðàç ÷åðåç 20 ìñ
	glutPostRedisplay();

};
void keyboard()
{
	int keyLeft = GetAsyncKeyState(VK_LEFT);
	int keyRight = GetAsyncKeyState(VK_RIGHT);
	int keyUp = GetAsyncKeyState(VK_UP);
	int keyDown = GetAsyncKeyState(VK_DOWN);
	int keyPlus = GetAsyncKeyState(VK_ADD);
	int keySub = GetAsyncKeyState(VK_SUBTRACT);
	// äëÿ ïðîâåêðè êëàññà êàìåðû âûçûâàåì ìåòîäû ïåðåäâèæåíèÿ
	if (keyUp & 0x01)
	{
		camera.rotateUpDown(5.0);
		return;
	}
	if (keyDown & 0x01)
	{
		camera.rotateUpDown(-5.0);
		return;
	}
	if (keyRight & 0x01)
	{
		camera.rotateLeftRight(-5.0);
		return;
	}
	if (keyLeft & 0x01)
	{
		camera.rotateLeftRight(5.0);
		return;
	}
	if (keyPlus & 0x01)
	{
		camera.zoomInOut(0.2);
		return;
	}
	if (keySub & 0x01)
	{
		camera.zoomInOut(-0.2);
		return;
	}

};
