#include "LTexture.h"

LTexture::LTexture()
{
	texture_id_ = 0;
	texture_width_ = 0;
	texture_height_ = 0;
}

LTexture::~LTexture()
{
	FreeTexture();
}
int LTexture::LoadTextureFromFile( const char* path )
{
	SDL_Surface* texture = NULL;
	texture = IMG_Load(path);
	if (!texture)
	{
		SDL_FreeSurface(texture);
		SDL_Log("Failed to load: %s", path);
		SDL_Log("IMG_Load Failure: %s\n", IMG_GetError());
		return 1;
	}
	else
	{
		// Convert Surface to RGBA
		SDL_PixelFormat* format = SDL_AllocFormat(SDL_PIXELFORMAT_ABGR8888);
		texture = SDL_ConvertSurface(texture, format, NULL);
		SDL_FreeFormat(format);

		// Make texture into a power of 2 size
		int w = 1;
		int h = 1;
		while (w < texture->w) {
			w <<= 1;
		}
		while (h < texture->h) {
			h <<= 1;
		}
		texture_width_ = w;
		texture_height_ = h;

		if ((texture->w != w) || (texture->h != h))
		{
			SDL_Log("Warning: Texture width and/or height isn't power of 2");
		}

		FreeTexture();

		// Load and Bind the texture
		glGenTextures(1, &texture_id_);
		glBindTexture(GL_TEXTURE_2D, texture_id_);
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, NULL );
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture->w, texture->h,
			GL_RGBA, GL_UNSIGNED_BYTE, texture->pixels);
		// Determine how texture is filtered when it is magnified/minified
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glBindTexture( GL_TEXTURE_2D, NULL );

		SDL_FreeSurface(texture);

		// Look for OpenGL Error
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			SDL_Log("Error loading texture! %i", error);
			return error;
		}
		return 0;
	}
}
int LTexture::LoadTextureFromPixels32( GLuint* pixels, GLuint width, GLuint height )
{
	FreeTexture();

	texture_width_ = width;
	texture_height_ = height;

	// Generate a single texture ID number
	glGenTextures( 1, &texture_id_);
	// Make that texture the one to work on
	glBindTexture( GL_TEXTURE_2D, texture_id_ );

	// Load Texture into GPU
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels );

	// Determine how texture is filtered when it is magnified/minified
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

	glBindTexture( GL_TEXTURE_2D, NULL );

	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		SDL_Log("Error loading texture from %pi pixels! %i", pixels, error);
		return error;
	}
	return 0;

}

void LTexture::FreeTexture()
{
	if (texture_id_ != 0)
	{
		glDeleteTextures( 1, &texture_id_ );
		texture_id_ = 0;
	}
	
	texture_width_ = 0;
	texture_height_ = 0;
}

void LTexture::render( GLfloat x, GLfloat y, LFRect* clip )
{
	if (texture_id_ != 0)
	{
		// Reset transformations
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity();
		
		glTranslatef(x, y, 0.0f);

		glBindTexture( GL_TEXTURE_2D, texture_id_ );

		glBegin( GL_QUADS );
		glTexCoord2f( 0.0f, 0.0f ); glVertex2f( 0.0f, 0.0f );
		glTexCoord2f( 1.0f, 0.0f ); glVertex2f( 1.0f, 0.0f );
		glTexCoord2f( 1.0f, 1.0f ); glVertex2f( 1.0f, 1.0f );
		glTexCoord2f( 0.0f, 1.0f ); glVertex2f( 0.0f, 1.0f );
		glEnd();
	}
}

GLuint LTexture::get_texture_id()
{
	return texture_id_;
}

GLuint LTexture::get_texture_width()
{
	return texture_width_;
}

GLuint LTexture::get_texture_height()
{
	return texture_height_;
}
