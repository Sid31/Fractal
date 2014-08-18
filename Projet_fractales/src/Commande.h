#ifndef COMMANDE_H
#define COMMANDE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR 1
int Correction_commande(int Taille,char** Tableau);
int Commande( int Taille,char **Tableau );
int Verif_commande_avec_paramaitre(char **Tableau,int *Num_case,int Case_max);
int test_entier(char* Commande_num);
int Traitement_commande_avec_parametre(char **Commande,int *Num_commande,int Case_max);
#endif



int Julia(void);
int Mandelbrot(void);
int Ifs(void);
int L_system(void);
int Flamme(void);
int Specification_L_System(void);
int Specification_transformation(void);
int Specification_fonction_affines_IFS(void);
int Specification_flamme(void);
int Largeur(char **Commande, int *Num_commande, int Case_max);
int Hauteur(char **Commande, int *Num_commande, int Case_max);
int Zoom(char **Commande, int *Num_commande, int Case_max);
int Partie_reel_julia(char **Commande, int *Num_commande, int Case_max);
int Partie_imaginaire_julia(char **Commande, int *Num_commande, int Case_max);
int Execute_help(void);
