#ifndef LESSON5_H
#define LESSON5_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"
#include "LTexture.h"

class Lesson5 : public RenderTest
{
private:
	int screen_width_;
	int screen_height_;
	LTexture checkerboard_texture_;
	int LoadMedia();
public:
	Lesson5();
	int RenderInit();
	int Render();
	int Resize(SDL_Window* cur_window);
	int HandleKey(SDL_Keycode sym);
};

#endif