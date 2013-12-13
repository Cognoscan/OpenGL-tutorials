#include "Lesson3.h"

Lesson3::Lesson3()
{
	g_viewport_mode = VIEWPORT_MODE_FULL;
}

int Lesson3::RenderInit()
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	return 0;
}

int Lesson3::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	// Reset modelview matrix
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef( screen_width / 2.0f, screen_height / 2.0f, 0.0f);

	switch (g_viewport_mode)
	{
	case VIEWPORT_MODE_FULL:
		// Full View
		glViewport( 0, 0, screen_width, screen_height );
		// Red Quad
		glBegin( GL_QUADS );
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f( -screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, screen_height / 2.0f );
		glVertex2f( -screen_width / 2.0f, screen_height / 2.0f );
		glEnd();
		break;
	case VIEWPORT_MODE_HALF_CENTER:
		// Center View
		glViewport( screen_width / 4, screen_height / 4, screen_width / 2, screen_height / 2 );
		// Green Quad
		glBegin( GL_QUADS );
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f( -screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, screen_height / 2.0f );
		glVertex2f( -screen_width / 2.0f, screen_height / 2.0f );
		glEnd();
		break;
	case VIEWPORT_MODE_HALF_TOP:
		// Center View
		glViewport( screen_width / 4, screen_height / 2, screen_width / 2, screen_height / 2 );
		// Green Quad
		glBegin( GL_QUADS );
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2f( -screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, -screen_height / 2.0f );
		glVertex2f( screen_width / 2.0f, screen_height / 2.0f );
		glVertex2f( -screen_width / 2.0f, screen_height / 2.0f );
		glEnd();
		break;
	case VIEWPORT_MODE_QUAD:
		//Bottom left red quad
        glViewport( 0, 0, screen_width / 2, screen_height / 2 );
        glBegin( GL_QUADS );
            glColor3f( 1.f, 0.f, 0.f );
            glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
            glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
        glEnd();

        //Bottom right green quad
        glViewport( screen_width / 2, 0, screen_width / 2, screen_height / 2 );
        glBegin( GL_QUADS );
            glColor3f( 0.f, 1.f, 0.f );
            glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
            glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
        glEnd();

        //Top left blue quad
        glViewport( 0, screen_height / 2, screen_width / 2, screen_height / 2 );
        glBegin( GL_QUADS );
            glColor3f( 0.f, 0.f, 1.f );
            glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
            glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
        glEnd();

        //Top right yellow quad
        glViewport( screen_width / 2, screen_height / 2, screen_width / 2, screen_height / 2 );
        glBegin( GL_QUADS );
            glColor3f( 1.f, 1.f, 0.f );
            glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
            glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
            glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
        glEnd();
		break;
	case VIEWPORT_MODE_RADAR:
		//Full size quad
        glViewport( 0, 0, screen_width, screen_height );
        glBegin( GL_QUADS );
            glColor3f( 1.f, 1.f, 1.f );
            glVertex2f( -screen_width / 8.f, -screen_height / 8.f );
            glVertex2f(  screen_width / 8.f, -screen_height / 8.f );
            glVertex2f(  screen_width / 8.f,  screen_height / 8.f );
            glVertex2f( -screen_width / 8.f,  screen_height / 8.f );
            glColor3f( 0.f, 0.f, 0.f );
            glVertex2f( -screen_width / 16.f, -screen_height / 16.f );
            glVertex2f(  screen_width / 16.f, -screen_height / 16.f );
            glVertex2f(  screen_width / 16.f,  screen_height / 16.f );
            glVertex2f( -screen_width / 16.f,  screen_height / 16.f );
        glEnd();

        //Radar quad
        glViewport( screen_width / 2, screen_height / 2, screen_width / 2, screen_height / 2 );
        glBegin( GL_QUADS );
            glColor3f( 1.f, 1.f, 1.f );
            glVertex2f( -screen_width / 8.f, -screen_height / 8.f );
            glVertex2f(  screen_width / 8.f, -screen_height / 8.f );
            glVertex2f(  screen_width / 8.f,  screen_height / 8.f );
            glVertex2f( -screen_width / 8.f,  screen_height / 8.f );
            glColor3f( 0.f, 0.f, 0.f );
            glVertex2f( -screen_width / 16.f, -screen_height / 16.f );
            glVertex2f(  screen_width / 16.f, -screen_height / 16.f );
            glVertex2f(  screen_width / 16.f,  screen_height / 16.f );
            glVertex2f( -screen_width / 16.f,  screen_height / 16.f );
        glEnd();
		break;
	}


	return 0;
}

int Lesson3::Resize(SDL_Window* cur_window)
{
	SDL_GetWindowSize(cur_window, &screen_width, &screen_height);

	// Set the viewport
	glViewport( 0, 0, screen_width, screen_height );

	// Set Projection Matrix
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0f, screen_width, screen_height, 0.0, 1.0, -1.0 );

	return 0;
}

int Lesson3::HandleKey(SDL_Keycode sym)
{
	if ( sym == SDLK_q )
	{
		g_viewport_mode++;
		if (g_viewport_mode > VIEWPORT_MODE_RADAR)
		{
			g_viewport_mode = VIEWPORT_MODE_FULL;
		}
	}
	return 0;
}