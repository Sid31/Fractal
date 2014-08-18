#ifndef IFS_H
#define IFS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <SDL/SDL.h>
#include "regles.h"
#include "Affichage.h"
#include "RW_IFS.h"


/*! \file         IFS.h
 * \author        Noel Stéphanie
 * \version       1.0
 * \brief         Fichier qui contient les algorithmes pour tracer des IFS
 *
 */

int appel_ifs(int zoom, int img_Largeur, int img_Hauteur);

/*! \fn          int ifs(SDL_Surface* ecran, int img_largeur, int img_hauteur, int zoom, Complexe z, Fct_IFS *tableau)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction globale qui trace la fractale
 * \param        ecran : pointeur qui représente l'écran
 * \param        img_largeur : largeur de l'ecran
 * \param        int img_hauteur : largeur de l'ecran
 * \param        zoom : coefficient du zoom
 * \param        z : variable de la fonction
 * \param        tableau : pointeur vers tableau des fonctions de l'IFS
 * \return       un entier qui représente la réussite ou pas de la fonction
 *
 */

int ifs(SDL_Surface* ecran, int img_largeur, int img_hauteur, int zoom, Complexe z, Fct_IFS *tableau);

/*! \fn          Pixel point_to_pixel(int zoom, Complexe z, int img_Largeur,int img_Hauteur)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui retourne le pixel correspondant au complexe
 * \param        img_largeur : largeur de l'ecran
 * \param        int img_hauteur : largeur de l'ecran
 * \param        zoom : coefficient du zoom
 * \param        z : variable de la fonction
 * \return       le pixel correspondant
 *
 */

Pixel point_to_pixel(int zoom, Complexe z, int img_Largeur,int img_Hauteur);

/*! \fn          Complexe appliquer_f(Complexe z, Fct_IFS f)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui applique la fonction choisit pour calculer le prochain point à tracer
 * \param        f : fonction de l'IFS
 * \param        z : variable de la fonction
 * \return       la nouvelle valeur de z
 *
 */

Complexe appliquer_f(Complexe z, Fct_IFS f);

/*! \fn          Fct_IFS choisir_f(Fct_IFS *tableau, float r)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui choisit la fonction à appliquer pour calculer le prochain point à tracer
 * \param        tableau : pointeur vers tableau des fonctions de l'IFS
 * \param        r : reel au hasard entre 0 et 1
 * \return       la fonction choisit
 *
 */

Fct_IFS choisir_f(Fct_IFS *tableau, float r);

/*! \fn          float random2(int a, int b)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui renvoie un reel au hasard entre a/10 et b/10
 * \param        a : entier de début de l'intervalle
 * \param        b : entier de fin de l'intervalle
 * \return       la fonction choisit
 *
 */

float random2(int a, int b);

#endif
