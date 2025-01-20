#include <stdio.h>
#include <stdlib.h>
#include "graphes.h"

AdjaListe* AdjaListeVide(int n, int m);
void AfficheAdjaListe(AdjaListe* A);
MatAdja* LireGraphe(const char* nom);

MatAdja* AdjaVide(int n){
    MatAdja* adja = (MatAdja*) malloc(sizeof(MatAdja));
    adja->nbsommets = n;
    adja->matrice = (int**) malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        adja->matrice[i] = (int*) calloc(n,sizeof(int));
    }
    return adja;
}

void AfficheAdja(MatAdja* A){
    for(int i = 0;i<A->nbsommets;i++){
        for(int j = 0;j<A->nbsommets;j++){
            if(j == 0){
                printf("[%d",A->matrice[i][j]);
            }
            else if (j == A->nbsommets-1){
                printf(",%d]\n",A->matrice[i][j]);
            }else{
                printf(",%d",A->matrice[i][j]);
            }
        }
    }

}

void freeAdja(MatAdja* A){

    for(int i = 0;i<A->nbsommets;i++){
        free(A->matrice[i]);
    }
    free(A->matrice);
    free(A);
}

AdjaListe* AdjaVersAdjaListe(MatAdja* A);
MatIncid* AdjaVersMatIncid(MatAdja* A);

MatIncid* MatIncidVide(int n, int m){

    MatIncid* matincid = (MatIncid*) malloc(sizeof(MatIncid));
    matincid->nb_sommets = n;
    matincid->nb_aretes = m;
    matincid->matrice = (int**) malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        matincid->matrice[i] = (int*) calloc(m,sizeof(int));
    }

    return matincid;

}

void AfficheMatIncid(MatIncid* A){

    for(int i = 0;i<A->nb_sommets;i++){
        for(int j = 0;j<A->nb_aretes;j++){
            if(j == 0){
                printf("[%d",A->matrice[i][j]);
            }
            else if(j == A->nb_aretes-1){
                printf(",%d]\n",A->matrice[i][j]);
            }
            else{
                printf(",%d",A->matrice[i][j]);
            }
        }
    }
}
void freeMatIncid(MatIncid* A){
    
    for(int i = 0;i<A->nb_sommets;i++){
        free(A->matrice[i]);
    }
    free(A->matrice);
    free(A);
}
Djikstra* algoDjikstra_with_adj(MatAdja* adja);
Djikstra* algoDjikstra_with_inc(MatIncid* matincid);
Djikstra* algoDjikstra_with_adjaliste(AdjaListe* listeadja);
int flot_max();