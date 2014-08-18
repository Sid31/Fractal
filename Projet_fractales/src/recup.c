#include "recup.h"

/* Correction_commande(int argc,char** argv){
    int i_tab;// variable de balayage de argv
    int i_verif;// variable de balayage
    argv[0]="";
    for( i_tab = 1;i_tab < argc; i_tab++){
        for(i_verif = 1; i_verif < argc;i_verif++){
            if(strcmp(argv[i_tab], argv[i_verif])==0){
                if(i_tab != i_verif)
                //Si on tombe sur une occurence
                argv[i_verif] = "";
            }
        }
    }
    return 1;
}*/
/*
int Commande( int Taille,char **Tableau ){
    int Num_case;
    for( Num_case=1;Num_case<Taille;Num_case++){
        if( Verif_commande(Tableau,Num_case,Taille)==0)
            return 0;
    }
    return 1;
}*/

/*
int Verif_commande (char **Tableau,int Num_case,int Case_max){
        int Test_commande=0 ;
        Test_commande = Verif_commande_avec_paramaitre(Tableau,Num_case,Case_max);
        if (Test_commande==1)
            return 1;
        else
        Test_commande = Verif_commande_sans_paramaitre(Tableau,Num_case);
        if (Test_commande==1)
            return 1;
        else
        Test_commande = Verif_commande_h(Tableau,Num_case,Case_max);
        if (Test_commande==1)
            return 1;
        else
            return 0;
}*/
/*
int test_entier(char* Commande_num){
    int valeur_num = atoi(Commande_num);
    if ((valeur_num==0)&&(valeur_num<=1000))
    //limite fixé pour evité les débordemant de mémoire
        return 0;
    else
        return 1;
}*/
/*
int Verif_commande_avec_paramaitre(char **Tableau,int Num_case,int Case_max){
    int a;
    if (((strcmp(Tableau[Num_case],"-w")==0)||
        (strcmp(Tableau[Num_case],"-jre")==0) ||
        (strcmp(Tableau[Num_case],"--width")==0) ||
        (strcmp(Tableau[Num_case],"--height")==0) ||
        (strcmp(Tableau[Num_case],"-jim")==0) ||
        (strcmp(Tableau[Num_case],"-z")==0) )&&(Num_case+1<Case_max))
        a = test_entier(Tableau[Num_case+1]);
            if(a==1){
                Num_case++;
                return 1;
            }
            else
                return 0;
}
*/

int Verif_commande_sans_paramaitre(char **Tableau,int Num_case){
    if (
        (strcmp(Tableau[Num_case],"")==0) ||
        (strcmp(Tableau[Num_case],"--help")==0) ||
        (strcmp(Tableau[Num_case],"-j")==0) ||
        (strcmp(Tableau[Num_case],"-m")==0) ||
        (strcmp(Tableau[Num_case],"-i")==0) ||
        (strcmp(Tableau[Num_case],"-l")==0) ||
        (strcmp(Tableau[Num_case],"-f")==0) ||
        (strcmp(Tableau[Num_case],"-li")==0) ||
        (strcmp(Tableau[Num_case],"-lt")==0) ||
        (strcmp(Tableau[Num_case],"-lf")==0) ||
        (strcmp(Tableau[Num_case],"-ff")==0) )
            return 1;
    else
            return 0;
}

int Verif_commande_h (char **Tableau,int Num_case,int Case_max){
    int a;
    if (strcmp(Tableau[Num_case],"-h")==0){
        if(Num_case+1<Case_max){
            a = test_entier(Tableau[Num_case+1]);
            if(a==1)
            Num_case++;
        }
        return 1;
    }
    else
        return 0;
}
