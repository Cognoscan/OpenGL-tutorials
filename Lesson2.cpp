#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"

#include "Lesson2.h"

Lesson2::Lesson2()
{
	gColorMode = COLOR_MODE_CYAN;
	gProjectionScale = 1.0f;
}


int Lesson2::RenderInit()
{
	// Select background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	return 0;
}

int Lesson2::Resize(SDL_Window* cur_window)
{
	SDL_GetWindowSize(cur_window, &screen_width, &screen_height);

	// Make viewport same size as window
	glViewport (0, 0, (GLsizei) screen_width, (GLsizei) screen_height);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0.0, screen_width * gProjectionScale, screen_height * gProjectionScale, 0.0, 1.0, -1.0);
	
	return 0;
}

int Lesson2::Render()
{
	// Clear buffer
	glClear (GL_COLOR_BUFFER_BIT);

	// Reset modelview matrix
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	// Center of screen
	glTranslatef( screen_width / 2.0f, screen_height / 2.0f, 0.0f );

	//Render quad
    if( gColorMode == COLOR_MODE_CYAN )
    {
        //Solid Cyan
        glBegin( GL_QUADS );
            glColor3f( 0.f, 1.f, 1.f );
            glVertex2f( -50.f, -50.f );
            glVertex2f(  50.f, -50.f );
            glVertex2f(  50.f,  50.f );
            glVertex2f( -50.f,  50.f );
        glEnd();
    }
	else
    {
        //RYGB Mix
        glBegin( GL_QUADS );
            glColor3f( 1.f, 0.f, 0.f ); glVertex2f( -50.f, -50.f );
            glColor3f( 1.f, 1.f, 0.f ); glVertex2f(  50.f, -50.f );
            glColor3f( 0.f, 1.f, 0.f ); glVertex2f(  50.f,  50.f );
            glColor3f( 0.f, 0.f, 1.f ); glVertex2f( -50.f,  50.f );
        glEnd();
    }

	glFlush ();

	return 0;
}

int Lesson2::HandleKey(SDL_Keycode sym)
{
	// If user presses q
	if (sym == SDLK_q)
	{
		if ( gColorMode == COLOR_MODE_CYAN )
		{
			gColorMode = COLOR_MODE_MULTI;
		}
		else
		{
			gColorMode = COLOR_MODE_CYAN;
		}
	}
	else if (sym == 'e')
	{
		gProjectionScale += 0.1f;
		if (gProjectionScale > 2.0f)
		{
			gProjectionScale -= 2.0f;
		}

		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
		glOrtho(0.0, screen_width * gProjectionScale, screen_height * gProjectionScale, 0.0, 1.0, -1.0);
	}

	return 0;
}