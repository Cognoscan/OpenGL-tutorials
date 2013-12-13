#include "Lesson5.h"


Lesson5::Lesson5()
{
}

int Lesson5::RenderInit()
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable( GL_TEXTURE_2D );

	LoadMedia();

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		SDL_Log( "Error initializing OpenGL: %i", error );
		return error;
	}
	return 0;
}

int Lesson5::Resize(SDL_Window *cur_window)
{
	SDL_GetWindowSize(cur_window, &screen_width_, &screen_height_);

	// Set viewport to whole window
	glViewport( 0, 0, screen_width_, screen_height_);

	// Find aspect ratio
	float aspect_ratio = ((float) screen_width_) / ((float) screen_height_);

	// Set up projection matrix
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( -2.0f * aspect_ratio, 2.0f * aspect_ratio , -2.0f, 2.0f, 1.0, -1.0 );

	return 0;
}

int Lesson5::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	GLfloat x = 0.0f;
	GLfloat y = 0.0f;

	checkerboard_texture_.render( x, y);

	return 0;
}

int Lesson5::LoadMedia()
{
	const int CHECKERBOARD_WIDTH = 128;
	const int CHECKERBOARD_HEIGHT = 128;
	const int CHECKERBOARD_PIXEL_COUNT = CHECKERBOARD_WIDTH * CHECKERBOARD_HEIGHT;

	GLuint checkerboard[ CHECKERBOARD_PIXEL_COUNT ];

	for ( int i = 0; i < CHECKERBOARD_PIXEL_COUNT; i++ )
	{
		GLubyte* colors = (GLubyte*)&checkerboard[i];
		// Next is someone being too clever for their own good...
		// If the 5th bit of the x and y offsets don't match
		if( i / 128 & 16 ^ i % 128 & 16 )
		{
			// White
			colors[0] = 0xFF;
			colors[1] = 0xFF;
			colors[2] = 0xFF;
			colors[3] = 0xFF;
		}
		else
		{
			// Red
			colors[0] = 0xFF;
			colors[1] = 0x00;
			colors[2] = 0x00;
			colors[3] = 0xFF;
		}
	}

	/*GLenum error = checkerboard_texture_.LoadTextureFromPixels32(
		checkerboard,
		CHECKERBOARD_WIDTH,
		CHECKERBOARD_HEIGHT );*/
	GLenum error = checkerboard_texture_.LoadTextureFromFile("C:\\Users\\Richard.s.teal\\Documents\\Visual Studio 2008\\Projects\\sdl_test2\\resources\\test.jpg");
	if (error != GL_NO_ERROR)
	{
		SDL_Log("Unable to load checkerboard texture!");
		return error;
	}
	return 0;
}


int Lesson5::HandleKey(SDL_Keycode sym)
{
	glMatrixMode( GL_MODELVIEW );
	switch (sym)
	{
	case SDLK_UP:
		glTranslatef(0.0, 0.0, 1.0f);
		break;
	case SDLK_DOWN:
		glTranslatef(0.0, 0.0, -1.0f);
		break;
	}
	return 0;
}
