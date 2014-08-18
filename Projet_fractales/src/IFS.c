#include "IFS.h"

int appel_ifs(int zoom, int img_Largeur, int img_Hauteur){

	int retour;
	SDL_Surface *ecran;

	ecran = NULL;

	retour = 0;

	//Si il y a un problème d'initialisation de la SDL, signaler l'erreur
  	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
  	  fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
   	 retour = 1;
 	}

	////////////////////////////////////////// INIT TABLEAU
	//Fct_IFS f1;
	//Fct_IFS f2;
	Fct_IFS *tableau;
    char * Fractale;
    Fractale = malloc(20 * sizeof(char));
    Fractale = "Pieuvre";
	//Pixel p;
	Complexe c;

	//dragon
	/*
	f1.mat[0][0] = 0.824074;
	f1.mat[0][1] = 0.281428;
	f1.mat[1][0] = -0.212346;
	f1.mat[1][1] = 0.864198;
	f1.vect[0] = -1.882290;
	f1.vect[1] = -0.110607;
	f1.p = 0.80;

	f2.mat[0][0] = 0.088272;
	f2.mat[0][1] = 0.520988;
	f2.mat[1][0] = -0.463889;
	f2.mat[1][1] = -0.377778;
	f2.vect[0] = 0.785360;
	f2.vect[1] = 8.095795;
	f2.p = 0.2;



	tableau[0] = f1;
	tableau[1] = f2;
	*/
	//printf("coucou1");
	 Lecture_IFS(Fractale);
	free(Fractale);
	//printf("coucou2");
	////////////////////////////////////

	ecran = SDL_SetVideoMode(img_Largeur, img_Hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	if (ecran == NULL) {
  	  fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
  	  retour = 2;
 	}

	SDL_WM_SetCaption("IFS", NULL);

	//Point de départ
	c.reel = 0;
	c.imaginaire = 0;

	//Tracer l'IFS
	ifs(ecran,img_Largeur,img_Hauteur,zoom,c,tableau);

	///actualiser(ecran);
	pause();
	atexit(SDL_Quit);

	return retour;
}

//Fonction globale qui trace la fractale
int ifs(SDL_Surface* ecran, int img_largeur, int img_hauteur, int zoom, Complexe z, Fct_IFS *tableau){

  Pixel p;
  float r;
  Fct_IFS f;
  int iteration;
  int iteration_max;

  //Nombre de point à tracer
  iteration_max = 100000;

  //Pour chaque point...
  for(iteration = 0; iteration < iteration_max; iteration++){

	//On choisit le pixel correspondant complexe
	p= point_to_pixel(zoom,z,img_largeur,img_hauteur);
	//Si le pixel sort de l'écran on ne l'affiche pas
	if(!(abs(p.x) >= img_largeur || abs(p.y) >= img_hauteur)){
		//Affichage du pixel p
		Set_Pixel(ecran, p.x, p.y, SDL_MapRGB(ecran->format,
             rand() % 128 + 128, rand() % 128 + 128, rand() % 128 + 128));
	}
	//On choisit un chiffre en tre 0 et 1
   	r = random2(0,10);

	//On choisit la fonction à appliquer pour trouver le prochain point
    	f = choisir_f(tableau,r);

	//On applique f pour trouver le prochain point
    	z = appliquer_f(z,f);
  }
  return 0;
}

//Fonction qui retourne le pixel correspondant au complexe
Pixel point_to_pixel(int zoom, Complexe z, int img_Largeur,int img_Hauteur){
	Pixel p;
	//Ici l'intervalle du complexe est [-10,10] d'où le chiffre 20
	p.x = floor(img_Largeur/20*z.reel*zoom  +img_Largeur/2);
	p.y = floor(img_Hauteur/20*z.imaginaire*zoom + img_Hauteur/2);

	return p;
}

//Fonction qui applique la fonction choisit pour calculer le prochain point à tracer
Complexe appliquer_f(Complexe z, Fct_IFS f){
  float tmp;

  //Application de la matrice de rotation et du vecteur de translation
  tmp = z.reel;
  z.reel = f.mat[0][0]*z.reel+ f.mat[0][1]*(z.imaginaire) + f.vect[0];
  z.imaginaire = f.mat[1][0]*tmp + f.mat[1][1]*(z.imaginaire) + f.vect[1];

  return z;
}

//Fonction qui choisit la fonction à appliquer pour calculer le prochain point à tracer
Fct_IFS choisir_f(Fct_IFS *tableau, float r){
  float t1;
  float t2;
  int i;

  //Initialisation du premier intervalle soit 0 et p1
  t1 = 0;
  t2 = tableau[0].p;
  i = 0;

  //Tant que r ne se trouve pas dans l'intervalle considéré
  while( !(r >= t1 && r <= t2)){
	//Passage au prochain intervalle soit pi et pi+1
    	t1 = t1 + tableau[i].p;
    	t2 = t2 + tableau[i + 1].p;
    	i = i + 1;
  }

  return tableau[i];
}

//Fonction qui renvoie un reel au hasard entre a/10 et b/10
float random2(int a, int b){
  int nb;
  float r;

  //Choix d'un entier entre a et b
  nb = (rand() % (b - a + 1)) + a;

  //Division par 10 pour avoir un réel
  r = (float)nb;
  r = r/10;
  return r;
}

