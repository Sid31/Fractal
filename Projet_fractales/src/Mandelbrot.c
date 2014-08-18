#include "Mandelbrot.h"



void fractale_Mandelbrot(void){
    SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *ecran = NULL, *pixel = NULL;
	int x = 0, y = 0, i = 0, iMax = 50;
	double xMin = 0, xMax = 0, yMin = -1.2, yMax = 1.2, img_Largeur, img_Hauteur, zoom,  buffer;
	Uint32 couleur;
	struct Complexe c, z;
	zoom = 100;
	img_Largeur = 800;
	img_Hauteur = 800;
    xMin = -img_Largeur/(2*zoom);
    yMax = +img_Hauteur/(2*zoom);
	ecran = SDL_SetVideoMode(img_Largeur, img_Hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Fractale de Mandelbrot", NULL);
	for (x = 0; x < img_Largeur; x++) {
		for (y = 0; y < img_Hauteur; y++) {
			c.reel = x/zoom  + xMin;
			c.imaginaire =yMax - y/zoom;
			z.reel = 0;
			z.imaginaire = 0;
			i = 0;
			do {
				buffer = z.reel;
				z.reel = pow(z.reel, 2) - pow(z.imaginaire, 2) + c.reel;
				z.imaginaire = 2*buffer*z.imaginaire + c.imaginaire;
				i++;
			} while ((pow(z.reel, 2) + pow(z.imaginaire, 2)) < 4 && i < iMax);

			if (i == iMax)
				couleur = 0;
			else {
				couleur = i*iMax*10;
			}
			Set_Pixel(ecran, x,  y, couleur);
		}SDL_UpdateRect(ecran,0,0,0,0);
	}
	pause();
	atexit(SDL_Quit);
}
