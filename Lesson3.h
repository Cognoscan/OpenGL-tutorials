#ifndef LESSON3_H
#define LESSON3_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"

class Lesson3 : public RenderTest
{
private:
	//Viewport mode
	enum ViewPortMode
	{
		VIEWPORT_MODE_FULL,
		VIEWPORT_MODE_HALF_CENTER,
		VIEWPORT_MODE_HALF_TOP,
		VIEWPORT_MODE_QUAD,
		VIEWPORT_MODE_RADAR
	};

	int g_viewport_mode;
	int screen_width;
	int screen_height;

public:
	Lesson3();
	int RenderInit();
	int Render();
	int Resize(SDL_Window* cur_window);
	int HandleKey(SDL_Keycode sym);
};

#endif