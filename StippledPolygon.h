#ifndef STIPPLEDPOLYGON_H
#define STIPPLEDPOLYGON_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"

class StippledPolygon : public RenderTest
{
public:
	int RenderInit();
	int Render();
	int Resize(SDL_Window* cur_window);
};

#endif