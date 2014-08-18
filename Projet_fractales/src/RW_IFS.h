#ifndef RW_IFS_H
#define RW_IFS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DRAGON 4
#define ARBRE 3
#define PIEUVRE 2
#define SIERPINSKI 1
typedef struct Fct_IFS Fct_IFS;

struct Fct_IFS
{
    float mat[2][2];
    float vect[2];
    float p;
};

/*! \fn          Fct_IFS *Lecture_IFS();
 * \author       Sid BERRAF
 * \version      1.0
 * \date          8 Novembre 2011
 * \brief         Crée les fonction des matrices du fichier IFS.txt sous forme d'un tableau de structure.
 * \return        Fonction : Retourne le tableau de structure contenant les différentes fonctions.
 */
Fct_IFS *Lecture_IFS();


/*! \fn          int Recherche_Nb_Fonctions(FILE* fichier );
 * \author       Sid BERRAF
 * \version      1.0
 * \date          7 Novembre 2011
 * \brief        Recherche dans le fichier le nombre de caractère ':' qui corespond au nombre de foncion.
 * \return        Nb_Fonctions : Retourne le nombre de fonctions.
 */
int Recherche_Nb_Fonctions(FILE* fichier );

#endif
