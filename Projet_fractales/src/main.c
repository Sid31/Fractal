#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <string.h>
#include "Mandelbrot.h"
#include "Julia.h"
#include "recup.h"
#include "Executeur.h"
#include "RW_IFS.h"
#include "Commande.h"



#define MAX(a, b) (((a)>(b))?(a):(b))
#define ABS(a) (((a)<0)?-(a):(a))

#define SQRT_3  1.732

/*! Problème -ff -li !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

int main(char argc,char **argv) {
	//fractale_Mandelbrot();
	//fractale_julia();
	//int test2=Correction_commande(argc,argv);
	//int test=Commande(argc,argv);
	//int test= Execut_Commande(argc,argv);
	//printf("%u <-- c'est du chocolat",test2);
	//printf("___%u___ <-- command correcte si 1 _",test);

int test = Correction_commande( argc, argv );
	printf("%s",argv[0] );
	printf("%s",argv[1] );
	printf("%s",argv[2] );
	printf("%s",argv[3] );
	printf("%s",argv[4] );
	printf("%s",argv[5] );
	printf("%u",argc );
	//int i =0;	//for(i=0)

//	Fct_IFS *Fonction;
//	Fonction = Lecture_IFS();
		//printf("--->>>> %d",caractereActuel);
/*

*/


	return 0;
}

