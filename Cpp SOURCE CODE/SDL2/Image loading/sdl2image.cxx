#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Function for loading an image to SDL_Texture
static SDL_Texture *loadImage(SDL_Renderer *renderer, const char *path)
{
	SDL_Surface *img = IMG_Load(path);
	if (img == NULL)
	{
		fprintf(stderr, "IMG_Load Error: %s\n", IMG_GetError());
		return NULL;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, img);
	SDL_FreeSurface(img);
	if (texture == NULL)
	{
		fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
		return NULL;
	}
	return texture;
}

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Window *window = SDL_CreateWindow("Hello SDL2-image", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
	{
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		return 1;
	}
	// Better scaling quality
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	SDL_Texture *imageTexture = loadImage(renderer, "cxxdroid.png");
	if (imageTexture == NULL)
	{
		fprintf(stderr, "Couldn't load image\n");
		return 1;
	}
	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);
	SDL_Rect dest;
	// Our image is square, so set dest accordingly
	if (h > w)
	{
		dest.x = 0;
		dest.w = w;
		dest.y = (h - w) / 2;
		dest.h = w;
	}
	else
	{
		dest.x = (w - h) / 2;
		dest.w = h;
		dest.y = 0;
		dest.h = h;
	}
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, imageTexture, NULL, &dest);
	SDL_RenderPresent(renderer);
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}