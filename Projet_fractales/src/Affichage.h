#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>

/*! \file            Affichage.h
 * \author        Sid BERRAF
 * \version       1.0
 * \brief           Biblothèque sur les fonctions du traitement et de déssin avec la SDL pour les Fractales.
 *
 */

/*! \fn             void Set_Pixel(SDL_Surface *ecran,int x, int y, Uint32 coul)
 * \author       Sid BERRAF
 * \version      1.0
 * \date          18 Octobre 2011
 * \brief         Poser un pixel a (x,y), de couleur coul.
 * \param        ecran,surface où va etre posé le pixel.
 * \param        x et y, les coordonnées du pixel sur l'image.
 * \param        coul, la couleur du pixel déposé.
 * \return        rien.
 *
 */
 void Set_Pixel(SDL_Surface *ecran,int x, int y, Uint32 coul);

/*! \fn          void pause();
 * \author       Sid BERRAF
 * \version      1.0
 * \date          18 Octobre 2011
 * \brief         Fair une pause et attendre l'évenement fermeture de la fenetre pour fermer laœ fenetre.
 * \param        ecran,surface où va etre posé le pixel.
 * \param        x et y, les coordonnées du pixel sur l'image.
 * \param        coul, la couleur du pixel déposé.
 * \return        rien.
 *
 */
void pause();

struct Complexe {
	double reel;
	double imaginaire;
};
typedef struct Complexe Complexe;
SDL_Surface *Init_SDL(void);
#endif
