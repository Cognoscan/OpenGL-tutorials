#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "RenderTest.h"
#include "Lesson5.h"

const Uint32 FRAMES_PER_SECOND = 60;

int RenderInit();
int Render();
int Resize(SDL_Window* cur_window);

int main(int argc, char* args[] )
{
	SDL_Window* screen = NULL;
	SDL_GLContext glcontext = NULL;

	RenderTest* renderer = new Lesson5();

    //Start SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		return false;
	}

	// Set up OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Set up the screen
	screen = SDL_CreateWindow("Radar Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	glcontext = SDL_GL_CreateContext(screen);

	SDL_Event polled_event;

	SDL_Log("Starting up OpenGL...");

	// Start up OpenGL
	renderer->RenderInit();
	renderer->Resize(screen);

	SDL_Log("Resize Complete");

	// Main render loop
	bool done = false;
	Uint32 ticks = SDL_GetTicks();
	Uint32 new_ticks = ticks;
	while (!done)
	{
		while ( SDL_PollEvent( &polled_event ) )
		{
			switch (polled_event.type)
			{
			case SDL_QUIT:
				done = true;
				break;
			case SDL_KEYDOWN:
				switch( polled_event.key.keysym.sym )
				{
				case SDLK_ESCAPE:
					done = true;
					break;
				default:
					renderer->HandleKey(polled_event.key.keysym.sym);
				}
				break;
			case SDL_WINDOWEVENT:
				switch (polled_event.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
					renderer->Resize(screen);
					break;
				}
			}
		}
		renderer->Render();

		// Update Screen
		SDL_GL_SwapWindow(screen);

		new_ticks = SDL_GetTicks();
		if ((new_ticks - ticks) < (1000 / FRAMES_PER_SECOND))
		{
			SDL_Delay( (1000 / FRAMES_PER_SECOND) - (new_ticks - ticks) );
		}
		ticks = new_ticks;
	}

	// Remove glContext when done with OpenGL
	SDL_GL_DeleteContext(glcontext);

	// Quit SDL
    SDL_Quit();
    return 0;
}