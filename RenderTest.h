#ifndef RENDERTEST_H
#define RENDERTEST_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

class RenderTest
{
public:
	virtual int RenderInit();
	virtual int Render();
	virtual int Resize(SDL_Window* cur_window);
	virtual int HandleKey(SDL_Keycode sym);
};

#endif