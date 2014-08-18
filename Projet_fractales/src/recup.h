#ifndef RECUP_H
#define RECUP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! doxygen a faire
//int Correction_commande(int argc,char** argv);
int test_entier(char* comande_num);
int Verif_commande (char **Tableau,int Num_case,int Case_max);
//int Commande( int Taille,char **Tableau );
int Verif_commande_avec_paramaitre(char **Tableau,int Num_case,int Case_max);
int Verif_commande_sans_paramaitre(char **Tableau,int Num_case);
int Verif_commande_h (char **Tableau,int Num_case,int Case_max);
#endif
