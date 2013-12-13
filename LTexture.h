#ifndef LTEXTURE_H
#define LTEXTURE_H

#include "SDL/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL/SDL_image.h"

class LTexture
{
private:
	GLuint texture_id_;
	GLuint texture_width_;
	GLuint texture_height_;
public:
	LTexture();
	~LTexture();
	int LoadTextureFromPixels32( GLuint* pixels, GLuint width, GLuint height );
	int LoadTextureFromFile( const char *path );
	void FreeTexture();
	void render( GLfloat x, GLfloat y );
	GLuint get_texture_id();
	GLuint get_texture_width();
	GLuint get_texture_height();
};

#endif