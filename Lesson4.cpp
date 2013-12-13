#include "Lesson4.h"

Lesson4::Lesson4()
{
	g_camera_x = 0.0f;
	g_camera_y = 0.0f;
}

int Lesson4::RenderInit()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glPushMatrix();

	return 0;
}

int Lesson4::Resize(SDL_Window *cur_window)
{
	SDL_GetWindowSize(cur_window, &screen_width, &screen_height);

	glViewport(0, 0, screen_width, screen_height);

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( 0.0, screen_width, screen_height, 0.0, 1.0, -1.0 );
	return 0;
}

int Lesson4::Render()
{
	glClear( GL_COLOR_BUFFER_BIT );

	// Load up Modelview matrix
	glMatrixMode( GL_MODELVIEW );
	glPopMatrix();
	glPushMatrix();
//Move to center of the screen
    glTranslatef( screen_width / 2.f, screen_height / 2.f, 0.f );

    //Red quad
    glBegin( GL_QUADS );
        glColor3f( 1.f, 0.f, 0.f );
        glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
        glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
    glEnd();

    //Move to the right of the screen
    glTranslatef( (GLfloat) screen_width, 0.f, 0.f );

    //Green quad
    glBegin( GL_QUADS );
        glColor3f( 0.f, 1.f, 0.f );
        glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
        glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
    glEnd();

    //Move to the lower right of the screen
    glTranslatef( 0.f, (GLfloat) screen_height, 0.f );

    //Blue quad
    glBegin( GL_QUADS );
        glColor3f( 0.f, 0.f, 1.f );
        glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
        glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
    glEnd();

    //Move below the screen
    glTranslatef( (GLfloat) -screen_width, 0.f, 0.f );

    //Yellow quad
    glBegin( GL_QUADS );
        glColor3f( 1.f, 1.f, 0.f );
        glVertex2f( -screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f, -screen_height / 4.f );
        glVertex2f(  screen_width / 4.f,  screen_height / 4.f );
        glVertex2f( -screen_width / 4.f,  screen_height / 4.f );
    glEnd();

	return 0;
}

int Lesson4::HandleKey(SDL_Keycode sym)
{
	switch (sym)
	{
	case SDLK_UP:
	case SDLK_w:
		g_camera_y -= 16.0f;
		break;
	case SDLK_DOWN:
	case SDLK_s:
		g_camera_y += 16.0f;
		break;
	case SDLK_LEFT:
	case SDLK_a:
		g_camera_x -= 16.0f;
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		g_camera_x += 16.0f;
		break;
	}

	// Set Model matrix to new camera position
	// TODO: Why not just translate the matrix immediately?
	glMatrixMode( GL_MODELVIEW );
	glPopMatrix();
	glLoadIdentity();
	glTranslatef( -g_camera_x, -g_camera_y, 0.0f);
	glPushMatrix();

	return 0;
}
