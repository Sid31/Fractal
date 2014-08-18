#ifndef EXECUTEUR_H
#define EXECUTEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recup.h"



//! doxygen a faire

int Execut_Commande( int Case_max,char **Commande);
void Traitement_commande(char **Commande,int Num_commande, int Case_max);
int Traitement_commande_sans_parametre(char **Commande, int Num_commande);
int Traitement_commande_sans_parametre_dessin(char **Commande, int Num_commande);
int Traitement_commande_sans_parametre_autre(char **Commande, int Num_commande);
int Traitement_commande_avec_parametre(char **Commande, int Num_commande, int Case_max);
int Verif_commande_h(char **Commande,int Num_commande, int Case_max);
int Traitement_commande_h(char **Commande,int Num_commande, int Case_max);
int Verif_commande_sans_paramaitre_commande_sans_parametre(char **Commande, int Num_commande);
int Verif_commande_avec_paramaitre(char **Commande, int Num_commande, int Case_max);/*
int Julia(void);
int Mandelbrot(void);
int Ifs(void);
int L_system(void);
int Flamme(void);
int Specification_L_System(void);
int Specification_transformation(void);
int Specification_fonction_affines_IFS(void);
int Specification_flamme(void);
int Largeur(char **Commande, int Num_commande, int Case_max);
int Hauteur(char **Commande, int Num_commande, int Case_max);
int Zoom(char **Commande, int Num_commande, int Case_max);
int Partie_reel_julia(char **Commande, int Num_commande, int Case_max);
int Partie_imaginaire_julia(char **Commande, int Num_commande, int Case_max);
int Execute_help(void);
*/
#endif
