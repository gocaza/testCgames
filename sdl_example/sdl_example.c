#include <stdio.h>
#include <SDL2/SDL.h>  //to initialize

int main(int argc, char **argv)
{
	//printf("give me a bottle of rum!\n");
	//attempt to initialize graphics system
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("error initializing SDL: %s\n", SDL_GetError());
	}

	printf("Initialization successfull\n");

	//clean up resources before exiting
	SDL_Quit();
	return 0;
}
