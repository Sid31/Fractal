#include "RW_IFS.h"

// Lecture de IFS et écriture dans le tableau de structure
Fct_IFS *Lecture_IFS(char * Fractale){
    FILE* IFS; // Pointeur sur fichier
    int Nb_Fonctions;// Variable du nombre de fonction dans le fichier IFS.txt
    int i; // variable de compteur pour Fonction
    IFS = fopen("/home/eisti/Desktop/Projet_fractales/doc/IFS.txt", "r+");
     //Nb_fonction reçoit le nombre de fonction
    Nb_Fonctions= Recherche_Nb_Fonctions(IFS);
    Fct_IFS Fonction[Nb_Fonctions];// Tableau de structure de type Fct_IFS de taille Nb_Fonction
    // On recherche le début de la fractale
    Recherche_Fractal(Fractale,FILE *IFS)
    fseek(IFS, 0, SEEK_SET);
    if (IFS != NULL){
        // balayage de toute les cases du tableau
        for(i = 0;i < Nb_Fonctions; i++ ){
            fseek(IFS, 12, SEEK_CUR); // On commance apres Fonction**
            fscanf(IFS  , "%f %f %f %f %f %f %f ", &Fonction[i].mat[0][0], &Fonction[i].mat[0][1], &Fonction[i].mat[1][0],
            &Fonction[i].mat[1][1],&Fonction[i].vect[0],&Fonction[i].vect[1],&Fonction[i].p);
        }
    }
    else
        //Problème de lecture du fichier
        printf("Impossible de lire le fichier");
        //Fermeture du fichier
        fclose(IFS);
        //retourné Fonction
    return  Fonction;
}

// Recherche du nombre de fonction dans le fichier
int Recherche_Nb_Fonctions(FILE *fichier ){
    int Nb_Fonctions = 0;
    int caractereActuel;
    //caractereActuel reçoit le caractère suivant
    caractereActuel = fgetc(fichier);
    while (caractereActuel != '/'){ // On continue tant que fgetc n'a pas retourné '/' (fin de fichier)
	 caractereActuel = fgetc(fichier); // On lit le caractère suivant
  	   //On compte le nombre de fonction
  	   if(caractereActuel == ':')
            Nb_Fonctions++;
	}
	return Nb_Fonctions;
}

