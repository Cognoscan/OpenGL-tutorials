#ifndef LESSON2_H
#define LESSON2_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"

class Lesson2 : public RenderTest
{
private:
	static const int COLOR_MODE_CYAN = 0;
	static const int COLOR_MODE_MULTI = 1;
	int gColorMode;
	GLfloat gProjectionScale;
	int screen_width;
	int screen_height;
public:
	Lesson2();
	int RenderInit();
	int Render();
	int Resize(SDL_Window* cur_window);
	int HandleKey(SDL_Keycode sym);
};

#endif