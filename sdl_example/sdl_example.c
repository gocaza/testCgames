#include <stdio.h>
#include <SDL2/SDL.h>  //to initialize
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>



int main(int argc, char **argv)
{
	//printf("give me a bottle of rum!\n");
	//attempt to initialize graphics system
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}

	//create a window and display
	SDL_Window * win = SDL_CreateWindow("My Window test",
	                                    SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										640, 480, 0);

	if (!win)
	{
		printf("error creating window> %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}


	//create a renderer, which sets up the graphics hardware
	//accelerated -> using HW resources and not emulated in SW
	//presentvsync - makes drawing smoother
	uint32_t render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);
	if (!rend)
	{
		printf("error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	//load the image into memory using SDL library function
	SDL_Surface * surface = IMG_Load("figures/hello.png");
	if (!surface)
	{
		printf("error loading surface\n");
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(rend);
		SDL_Quit();
		return 1;
	}

	//create a texture that corresponds to image data loaded into the graphics hardware as memory
	//a surface is in main memory while texture is on vram memory that the graphics card controls
	//load the image data into the graphics hardware's memory
	SDL_Texture * tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface); //frees up memory used by surface
	if (!tex)
	{
		printf("error creating texture %s\n", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(rend),
		SDL_Quit();
		return 1 ;
	}

	/* Select the color for drawing. It is set to black here. */
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	//clear the window
	SDL_RenderClear(rend);

	//draw the image to the window, this takes the texture data and copy to our window
	SDL_RenderCopy(rend, tex,NULL, NULL);


	/* Up until now everything was drawn behind the scenes.
	   This will show the new, red contents of the window. */
	SDL_RenderPresent(rend);


	//wait a few seconds
	SDL_Delay(5000);

	//clean up resources before exiting
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
