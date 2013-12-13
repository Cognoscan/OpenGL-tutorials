#ifndef LESSON4_H
#define LESSON4_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"

class Lesson4 : public RenderTest
{
private:
	GLfloat g_camera_x;
	GLfloat g_camera_y;
	int screen_width;
	int screen_height;

public:
	Lesson4();
	int RenderInit();
	int Render();
	int Resize(SDL_Window* cur_window);
	int HandleKey(SDL_Keycode sym);
};

#endif