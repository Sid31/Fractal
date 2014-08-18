#include "Julia.h"

void fractale_julia(void){
	int x = 0, y = 0, i = 0, iMax = 50;
	double xMin, xMax, yMin, yMax, img_Largeur, img_Hauteur, zoom,  buffer;
	Uint32 couleur;
	struct Complexe c, z;
    xMin = -img_Largeur/(2*zoom);
	xMax = img_Largeur/(2*zoom);
	yMin =  -img_Hauteur/(2*zoom);
	yMax =  img_Hauteur/(2*zoom);


	zoom = 200;
	img_Largeur = 600;
	img_Hauteur = 600;

	c.reel = -0.0519;
	c.imaginaire = 0.688;

    SDL_Surface *ecran = Init_SDL();
     ecran = SDL_SetVideoMode(img_Largeur, img_Hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


	for (x = 0; x < img_Largeur; x++) {
		for (y = 0; y < img_Hauteur; y++) {
			z.reel = x/zoom  + xMin;
			z.imaginaire = y/zoom  + yMin;
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
				couleur = i*iMax*100;
			}
			Set_Pixel(ecran, x,  y, couleur);

		}
		SDL_UpdateRect(ecran,0,0,0,0);
	}


pause();
atexit(SDL_Quit);
}

