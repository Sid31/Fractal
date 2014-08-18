#include "regles.h"

//Fonction qui trace une ligne.
void ligne(SDL_Surface* surface, int Dx, int Dy, int xincr, int yincr, int x, int y,int b){
  int moitie;
  int i;

  //Calcul de la moitie
  moitie = Dx/2;
  //Parcours des x 
  for(i=0; i<Dx; i++){

      x += xincr;
      moitie += Dy;

      if(moitie > Dx){
	  moitie -= Dx;
	  y += yincr;
      }
	
	if(b == 0)
	Set_Pixel(surface, x, y, 2*1000000);
	else
	Set_Pixel(surface, y, x, 2*1000000);

  }
}

//Fonction qui initialise les variable et qui appelle la fonction ligne.
void drawLine(SDL_Surface* surface , Pixel p1, Pixel p2){
	
        Pixel p;
	int Dx,Dy;
	int xincr,yincr;
 
	//Calcul des distances entre les deux points
	Dx = abs(p2.x - p1.x);
	Dy = abs(p2.y - p1.y);

	//Choix de la direction de l'incrémentation de x
	if(p1.x < p2.x) 
		xincr = 1;
	else
		xincr = -1;


	//Choix de la direction de l'incrémentation de y
	if(p1.y < p2.y) 
		yincr = 1;
	else
		yincr = -1;

	//Départ de p1
	p = p1;

	//Tracer la ligne en fonction des distances
	if(Dx > Dy)
	  ligne(surface,Dx, Dy, xincr, yincr, p.x, p.y,0);
	else
	  ligne(surface,Dy, Dx, yincr, xincr, p.y, p.x,1);
}


//Fonction qui calcul le prochain point
Pixel prochain_point(float longueur, Pixel curseur, int angle){
  Pixel p;
  float angle_radian;
  float c;
  float b;
  int dx;
  int dy;
	 	
  //Transformation en radians
  angle_radian = (PI * angle)/180.0;
  
  //Calcul des angles
  c = cos(angle_radian);
  b = sin(angle_radian);

  dx = roundf (c*longueur);
  dy = roundf (b*longueur);
  //Calcul du prochain point
  p.x = curseur.x + dx;
  p.y = curseur.y - dy;

  return p;
}

//Fonction qui trace une ligne en fonction du prochain point à tracer et qui change la position du curseur.
void tracer(SDL_Surface* surface, float longueur, Pixel *curseur, int angle){
  Pixel p;
  
  //Calcul du prochain point
  p = prochain_point(longueur, *curseur, angle);

  //Tracer la ligne entre le point actuel et le prochain point
  drawLine(surface,*curseur, p);

  //Le curseur change de position 
  curseur->x = p.x;
  curseur->y = p.y; 
}

//Fonction qui bouge la position du curseur au prochain point par rapport au dernier angle.
void avancer(float longueur, Pixel *curseur, int angle){
  Pixel p; 

  //Calcul du prochain point
  p = prochain_point(longueur, *curseur, angle);

  //Le curseur change de position 
  curseur->x = p.x;
  curseur->y = p.y;
 
}

//Fonction qui effectue une rotation dans le sens horaire par rapport au dernier angle.
void rot_horaire (int *angle, int angle2){
  *angle -= angle2;
}

//Fonction qui effectue une rotation dans le sens trigonométrique
void rot_trigo(int *angle, int angle2){
  *angle += angle2;
}

//Fonction qui effectue une rotation de 180° par rapport au dernier angle.
void angle_plat(int *angle){
  (*angle) += 180;
}

//Fonction qui enregistre la position du curseur.
void enregistrement(Pixel curseur, Pixel* pE){
  //Enregistrement du point
  pE->x = curseur.x;
  pE->y = curseur.y;
}

//Fonction qui remet le curseur à la dernière position enregistrée.
void retour(Pixel* curseur, Pixel pE){
  //Retour au dernier point curseur
  curseur->x = pE.x;
  curseur->y = pE.y;
}

//Fonction qui va effectuer l'action associé au caractère
int action(SDL_Surface* surface, char c, float longueur, Pixel *curseur, int *angle, int angle2, Pixel* pE){
  switch(c){
  case 'a' :
    
    tracer(surface, longueur, curseur, *angle);
    return 0;
    break;

  case 'b' :
     avancer(longueur, curseur, *angle); 
     return 0;
    break;

 case '-' : 
     rot_horaire(angle, angle2);
     return 0;
    break;

  case '+' :
     rot_trigo(angle, angle2);
     return 0;  
    break;  
 
  case '*' :
    angle_plat(angle);
     return 0;
    break;   

  case '?' :
     enregistrement(*curseur, pE);
     return 0;
    break;  

  case '!' :
     retour(curseur, *pE);
     return 0;
    break;  

  default :
    printf("Erreur de caractère.");
    return 1;
    break;
  }

}
