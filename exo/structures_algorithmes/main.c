#include <stdio.h>
#include "graphes.c"

int main(){

    //Adja* A = AdjaVide(8);
    //AfficheAdja(A);
    //freeAdja(A);

    Adja* Ad = LireGraphe("graphe1.txt");
    AfficheAdja(Ad);
    //Adja* adja1 = Transpose(Ad);
    //printf("Transpose : \n");
    //AfficheAdja(adja1);

    //Sommet** sommets = Parcours_Profondeur(adja1);
    //Afficher_Sommets(sommets,adja1->nbsommets);
    //Sommet** sommets_trier = Trier(sommets,adja1->nbsommets);
    //printf("Sommets tries : \n");
    //Afficher_Sommets(sommets_trier,adja1->nbsommets);

    int* comp = (int*) calloc(Ad->nbsommets,sizeof(int));
    int nbconnexe = CompFortementConnexes(Ad,comp);
    for(int i = 0;i<Ad->nbsommets;i++){
        printf("Noeud %d, connexe : %d\n",i,comp[i]);
    }
    //free(sommets);
    freeAdja(Ad);
    //free(adja1);
    return 0;
}