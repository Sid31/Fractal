#ifndef REGLES_H
#define REGLES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Affichage.h"
#include <SDL/SDL.h>

/*! \file           regles.h
 * \author        Noel Stéphanie
 * \version       1.0
 * \brief           Biblothèque sur les régles du L-system
 *
 */
#define PI (3.141592653589793)

struct Pixel{
  int x;
  int y;
};

typedef struct Pixel Pixel;

/*! \fn          void ligne(SDL_Surface* surface, int Dx, int Dy, int xincr, int yincr, int x,int y,int b)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui trace une ligne.
 * \param        surface : pointeur qui représente l'écran
 * \param        Dx : distance entre les abscisses des deux points
 * \param        Dy : distance entre les ordonnées des deux points
 * \param        xincr : incrémentation de x positive ou négative
 * \param        yincr : incrémentation de y positive ou négative
 * \param        x : coordoonnee x du pixel traité
 * \param        y : coordoonnee y du pixel traité
 * \param        b : booleen qui donne l'ordre entre x et y
 * \return       Rien
 */

void ligne(SDL_Surface* surface, int Dx, int Dy, int xincr, int yincr, int x,int y,int b);

/*! \fn          void drawLine(SDL_Surface* surface , Pixel p1, Pixel p2)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui initialise les variable et qui appelle la fonction ligne
 * \param        surface : Pointeur qui représente l'écran
 * \param        p1 : premier pixel
 * \param        p2 : deuxième pixel 
 * \return       Rien
 */

void drawLine(SDL_Surface* surface , Pixel p1, Pixel p2);

/*! \fn          Pixel prochain_point(float longueur, Pixel curseur, int angle)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui calcul le prochain point
 * \param        longueur : longueur des segments
 * \param        curseur : pixel à partir du quel on trace
 * \param        angle : angle entre l'horizontal et le segment à tracer
 * \return       le prochain point à partir du quel on va tracer
 */

Pixel prochain_point(float longueur, Pixel curseur, int angle);

/*! \fn          void tracer(SDL_Surface* surface, float longueur, Pixel *curseur, int angle)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui trace une ligne en fonction du prochain point à tracer et qui change la position du curseur
 * \param        surface : Pointeur qui représente l'écran
 * \param        longueur : longueur des segments
 * \param        curseur : pointeur vers le pixel à partir du quel on trace
 * \param        angle : angle entre l'horizontal et le segment à tracer
 * \return       rien
 */

void tracer(SDL_Surface* surface, float longueur, Pixel *curseur, int angle);

/*! \fn          void avancer(float longueur, Pixel *curseur, int angle)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui bouge la position du curseur au prochain point par rapport au dernier angle
 * \param        longueur : longueur des segments
 * \param        curseur : pointeur vers le pixel à partir du quel on trace
 * \param        angle : angle entre l'horizontal et le segment à tracer
 * \return       rien
 */

void avancer(float longueur, Pixel *curseur, int angle);

/*! \fn          void rot_horaire(int *angle, int angle2)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui effectue une rotation dans le sens horaire par rapport au dernier angle
 * \param        angle : pointeur vers l'angle entre l'horizontal et le segment à tracer
 * \param        angle2 : angle correspondant à la fractale
 * \return       rien
 */

void rot_horaire(int *angle, int angle2);

/*! \fn          void rot_trigo(int *angle, int angle2)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui effectue une rotation dans le sens trigonométrique
 * \param        angle : pointeur vers l'angle entre l'horizontal et le segment à tracer
 * \param        angle2 : angle correspondant à la fractale
 * \return       rien
 */

void rot_trigo(int *angle, int angle2);

/*! \fn          void angle_plat(int *angle)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui effectue une rotation de 180° par rapport au dernier angle
 * \param        angle : pointeur vers l'angle entre l'horizontal et le segment à tracer
 * \return       rien
 */

void angle_plat(int *angle);

/*! \fn          void enregistrement(Pixel curseur, Pixel pE)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui enregistre la position du curseur
 * \param        curseur : pixel à partir du quel on trace
 * \param        pE : pixel enregistré
 * \return       rien
 */

void enregistrement(Pixel curseur, Pixel* pE);

/*! \fn          void retour(Pixel curseur, Pixel pE)
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui remet le curseur à la dernière position enregistrée
 * \param        curseur : pixel à partir du quel on trace
 * \param        pE : pixel enregistré
 * \return       rien
 */

void retour(Pixel* curseur, Pixel pE);

/*! \fn          int action(SDL_Surface* surface, char c, float longueur, Pixel *curseur, int *angle, int angle2, Pixel pE);
 * \author       Noel Stéphanie
 * \version      1.0
 * \date         28 Octobre 2011
 * \brief        Fonction qui va effectuer l'action associé au caractère
 * \param        surface : Pointeur qui représente l'écran
 * \param        c : caractère à traité
 * \param        longueur : longueur des segments
 * \param        curseur : pixel à partir du quel on trace
 * \param        angle : pointeur vers l'angle entre l'horizontal et le segment à tracer
 * \param        angle2 : angle correspondant à la fractale
 * \param        pE : pixel enregistré
 * \return       rien
 */
int action(SDL_Surface* surface, char c, float longueur, Pixel *curseur, int *angle, int angle2, Pixel* pE);

#endif
