#include "Commande.h"
#include "Affichage.h"

int Correction_commande(int Taille,char** Tableau ){
    int Num_case;// variable de balayage du Tableau
    int i_verif;// variable de balayage
    Tableau[0]="";
    for( Num_case = 1;Num_case < Taille; Num_case++){
        for(i_verif = 1; i_verif < Taille;i_verif++){
            if(strcmp(Tableau[Num_case], Tableau[i_verif])==OK){
                if(Num_case != i_verif)
                //Si on tombe sur une occurence
                Tableau[i_verif] = "";
            }
        }
        Commande(Taille,Tableau);
    }
    return OK;
}
int Commande( int Taille,char **Tableau ){
    int *Num_case;
    for( *Num_case=1;*Num_case<Taille;*Num_case= *Num_case+1){
        if( Verif_commande(Tableau,Num_case,Taille)==OK)
            return OK;
    }
    return ERROR;
}
int Verif_commande (char **Tableau,int *Num_case,int Case_max){
        int Test_commande=1 ;
        Test_commande = Verif_commande_avec_paramaitre(Tableau,Num_case,Case_max);
        if (Test_commande==OK){
            Traitement_commande_avec_parametre(Tableau, Num_case, Case_max);
            return OK;
        }
        else
        Test_commande = Verif_commande_sans_paramaitre(Tableau,Num_case);
        if (Test_commande==OK)
            return OK;
        else
        Test_commande = Verif_commande_h(Tableau,Num_case,Case_max);
        if (Test_commande==OK)
            return OK;
        else
            return 1;
}

int Verif_commande_avec_paramaitre(char **Tableau,int *Num_case,int Case_max){
    int a;
    if (((strcmp(Tableau[*Num_case],"-w")==OK)||
        (strcmp(Tableau[*Num_case],"-jre")==OK) ||
        (strcmp(Tableau[*Num_case],"--width")==OK) ||
        (strcmp(Tableau[*Num_case],"--height")==OK) ||
        (strcmp(Tableau[*Num_case],"-jim")==OK) ||
        (strcmp(Tableau[*Num_case],"-z")==OK) )&&(*Num_case+1<Case_max))
        a = test_entier(Tableau[*Num_case+1]);
            if(a==OK){
                return OK;
            }
            else
                return 1;
}
int test_entier(char* Commande_num){

    int valeur_num = atoi(Commande_num);
    if ((valeur_num!=0)&&(valeur_num<=1000))
    //limite fixé pour evité les débordemant de mémoire
        return OK;
    else
        return 1;
}

int Traitement_commande_avec_parametre(char **Commande,int *Num_commande,int Case_max){printf("tata : %s ////\n",Commande[*Num_commande]);
    int Pas_erreur = 1;//verificateur d'erreur lor de l'éxecution d'une sous focnction
    /* Vérification de la commande*/

    if (strcmp(Commande[*Num_commande],"--height") == OK){printf("toto2\n");
                Pas_erreur = Hauteur(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[*Num_commande], "-w") == OK){printf("toto3\n");
                Pas_erreur = Largeur(Commande,Num_commande,Case_max);
                *Num_commande = *Num_commande + 1;
                return Pas_erreur;
    }
    if (strcmp(Commande[*Num_commande],"-z") == OK){printf("toto4\n");
                Pas_erreur = Zoom(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[*Num_commande],"-jre") == OK){printf("toto5\n");
                Pas_erreur = Partie_reel_julia(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[*Num_commande],"-jim") == OK){printf("toto6\n");
                Pas_erreur = Partie_imaginaire_julia(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    if (strcmp(Commande[*Num_commande],"--width") == OK){printf("toto1\n");
               Pas_erreur = Largeur(Commande,Num_commande,Case_max);
                return Pas_erreur;
    }
    else
        return 1;
}


int Julia(void){printf("Julia");return OK;}
int Mandelbrot(void){printf("Mandelbrot");return OK;}
int Ifs(void){printf("Ifs");return OK;}
int L_system(void){printf("L_system");return OK;}
int Flamme(void){printf("Flamme");return OK;}
int Specification_L_System(void){printf("Specification_L_System");return OK;}
int Specification_transformation(void){printf("Specification_transformation");return OK;}
int Specification_fonction_affines_IFS(void){printf("Specification_fonction_affines_IFS");return OK;}
int Specification_flamme(void){printf("Specification_flamme");return OK;}
int Largeur(char **Commande, int *Num_commande, int Case_max){printf("Largeur");return OK;}
int Hauteur(char **Commande, int *Num_commande, int Case_max){printf("hauteur");return OK;}
int Zoom(char **Commande, int *Num_commande, int Case_max){printf("Zoom");return OK;}
int Partie_reel_julia(char **Commande, int *Num_commande, int Case_max){printf("Partie_reel_julia");return OK;}
int Partie_imaginaire_julia(char **Commande, int *Num_commande, int Case_max){printf("Partie_imaginaire_julia");return OK;}
int Execute_help(void){printf("help");return OK;}
