#include "Executeur.h"
#include "recup.h"
#include "Julia.h"
#include "Mandelbrot.h"

int Execut_Commande(int Case_max,char **Commande){
    int Num_commande;
    int test = Correction_commande( Case_max, Commande);
    for(Num_commande = 1;Num_commande < Case_max;Num_commande++){
            Traitement_commande(Commande,Num_commande,Case_max);
    }
    return 1;
}

void Traitement_commande(char **Commande,int Num_commande,int Case_max){
    int Test_commande = 0;
    Test_commande=Verif_commande_sans_paramaitre(Commande,Num_commande);
    if (Test_commande == 1)
            Traitement_commande_sans_parametre(Commande,Num_commande);
    Test_commande=Verif_commande_avec_paramaitre(Commande,Num_commande,Case_max);
    if (Test_commande == 1)
            Traitement_commande_avec_parametre(Commande,Num_commande,Case_max);
        Test_commande=Verif_commande_h(Commande,Num_commande,Case_max);
    if (Test_commande == 1){
            Traitement_commande_h(Commande,Num_commande,Case_max);}
}

int Traitement_commande_sans_parametre(char **Commande,int Num_commande){
    int Test_commande = 0; // permet de verifié si la commande a été déja traité dans l'un des deux traitement
    Test_commande = Traitement_commande_sans_parametre_dessin(Commande,Num_commande);
    if (Test_commande == 1)
        return 1;
    else
        Test_commande = Traitement_commande_sans_parametre_autre(Commande,Num_commande);
    return Test_commande;
}
 int Traitement_commande_sans_parametre_dessin(char **Commande,int Num_commande){
     int Pas_erreur;
    if (strcmp(Commande[Num_commande],"-j") == 0){
        Pas_erreur = Julia();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-m") == 0){
        Pas_erreur = Mandelbrot();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-i") == 0){
        Pas_erreur = Ifs();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-l") == 0){
        Pas_erreur = L_system();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-f") == 0){
        Pas_erreur = Flamme();
        return Pas_erreur ;
    }
 }

int Traitement_commande_sans_parametre_autre(char **Commande, int Num_commande){printf("hauteur");
    int Pas_erreur;
    if (strcmp(Commande[Num_commande],"--help") == 0){
            Pas_erreur = Execute_help();
            return Pas_erreur;printf("hauteur");
        }
    if (strcmp(Commande[Num_commande],"-li") == 0){
        Pas_erreur = Specification_L_System();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-lt") == 0){
        Pas_erreur = Specification_transformation();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-lf") == 0){
        Pas_erreur = Specification_fonction_affines_IFS();
        return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-ff") == 0){
        Pas_erreur = Specification_flamme();
        return Pas_erreur;
    }

}

//!////////////////////////////////////////////////////////////////////////////////////
/*int Traitement_commande_avec_parametre(char **Commande,int Num_commande,int Case_max){
    int Pas_erreur = 0;//verificateur d'erreur lor de l'éxecution d'une sous focnction
    if (strcmp(Commande[Num_commande],"--width") == 0){
               Pas_erreur = Largeur(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"--height") == 0){
                Pas_erreur = Hauteur(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande], "-w") == 0){
                Pas_erreur = Largeur(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-z") == 0){
                Pas_erreur = Zoom(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-jre") == 0){
                Pas_erreur = Partie_reel_julia(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[Num_commande],"-jim") == 0){
                Pas_erreur = Partie_imaginaire_julia(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
}*/
int Traitement_commande_h(char **Commande,int Num_commande,int Case_max){
     int a;
     int Pas_erreur=0;
    if (strcmp(Commande[Num_commande],"-h")==0){
        if(Num_commande+1<Case_max){
            a = test_entier(Commande[Num_commande+1]);
        }
            if(a==1)
                Pas_erreur = Hauteur(Commande,Num_commande,Case_max);
            else
                Pas_erreur = Execute_help();
            return Pas_erreur;

    }
    else
        return Pas_erreur;
}

/*!////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Julia(void){printf("Julia");return 1;}
int Mandelbrot(void){printf("Mandelbrot");return 1;}
int Ifs(void){printf("Ifs");return 1;}
int L_system(void){printf("L_system");return 1;}
int Flamme(void){printf("Flamme");return 1;}
int Specification_L_System(void){printf("Specification_L_System");return 1;}
int Specification_transformation(void){printf("Specification_transformation");return 1;}
int Specification_fonction_affines_IFS(void){printf("Specification_fonction_affines_IFS");return 1;}
int Specification_flamme(void){printf("Specification_flamme");return 1;}
int Largeur(char **Commande, int Num_commande, int Case_max){printf("Largeur");return 1;}
int Hauteur(char **Commande, int Num_commande, int Case_max){printf("hauteur");return 1;}
int Zoom(char **Commande, int Num_commande, int Case_max){printf("Zoom");return 1;}
int Partie_reel_julia(char **Commande, int Num_commande, int Case_max){printf("Partie_reel_julia");return 1;}
int Partie_imaginaire_julia(char **Commande, int Num_commande, int Case_max){printf("Partie_imaginaire_julia");return 1;}
int Execute_help(void){printf("help");return 1;}
*/
