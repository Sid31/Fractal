#include "Affichage.h"


void Set_Pixel(SDL_Surface *ecran,int x, int y, Uint32 coul)
{
  *((Uint32*)(ecran->pixels) + x + y * ecran->w) = coul;
}



void pause() {
	int fin = 0;
	SDL_Event event;

	while (!fin) {
		SDL_WaitEvent(&event);
		if (event.type == SDL_QUIT)
				fin = 1;
	}
}

SDL_Surface *Init_SDL(void){
    int a;
    a = SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *ecran = NULL;
	SDL_WM_SetCaption("Fractale de Julia", NULL);
    return ecran;
	}
