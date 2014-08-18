#include "noyau.h"



int Verif_commande(int argc, char **argv){
    int i;
    char **commande;
    commande = malloc(argc*sizeof(argv));
    *commande = malloc(argc*sizeof(*argv));
    for(i=1;i<=argc;i++){
      if(!strcmp(argv[i],"-j"))
          commande[1]= argv[1];
          printf("%s\n"commande[1]);





    }
    free(commande);
    return (0);
}
