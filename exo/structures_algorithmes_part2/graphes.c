#include <stdio.h>
#include <stdlib.h>
#include "graphes.h"

MatIncid* MatIncidVide(int n, int m);
void AfficheMatIncid(MatIncid* A);
MatIncid* LireGraphe(const char * nom);
MatAdja* MatIncidVersAdja(MatIncid* A);
MatAdja* AdjaVide(int n);
void AfficheAdja (MatAdja* A);
void Ajouter(MatIncid* A, int k, int o, int p, int b);
int Cycle(int * Comp, int o, int b, int n);
MatIncid* Kruskal(MatIncid* A);
MatIncid* Prim(MatIncid* A, int s);


MatIncid* MatIncidVide(int n, int m){

    MatIncid* matincid = (MatIncid*) malloc(sizeof(MatIncid));
    matincid->nb_sommets = n;
    matincid->nb_aretes = m;
    matincid->Matrice = (int**) malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        matincid->Matrice[i] = (int*) calloc(m,sizeof(int));
    }

    return matincid;

}

void AfficheMatIncid(MatIncid* A){

    for(int i = 0;i<A->nb_sommets;i++){
        for(int j = 0;j<A->nb_aretes;j++){
            if(j == 0){
                printf("[%d",A->Matrice[i][j]);
            }
            else if(j == A->nb_aretes-1){
                printf(",%d]\n",A->Matrice[i][j]);
            }
            else{
                printf(",%d",A->Matrice[i][j]);
            }
        }
    }
}

MatIncid* LireGraphe(const char * nom){


    char chaine[100];
    int n,m,sommet_debut,sommet_fin,poids_actuel,poids_precedant=0,compteur_aretes=0;
    FILE* file = fopen("graphes2.txt","r+");
    fgets(chaine,100,file);
    sscanf(chaine,"%d %d",&n,&m);
    MatIncid* matincid = MatIncidVide(n,m);
    while(fgets(chaine,100,file) != NULL){
        sscanf(chaine,"%d %d %d",&sommet_debut,&poids_actuel,&sommet_fin);
        compteur_aretes++;
        if(poids_actuel < poids_precedant ){
            printf("ERREUR : le graphe n est pas bien ordonne, les aretes ne sont pas bien classes\n");
            exit(EXIT_FAILURE);
        }
        else if(compteur_aretes > m){
            printf("Il y a trop d aretes renseignes dans le fichier pour construire le graphe ! \n");
            exit(EXIT_FAILURE);
        }
        else if((sommet_debut < 0 || sommet_debut > n-1) ||(sommet_fin < 0 || sommet_fin > n-1)){
            printf("Un sommet n est pas bien renseignes et depasse la norme id sommet ! \n");
            exit(EXIT_FAILURE);
        }
        else{
            matincid->Matrice[sommet_debut][compteur_aretes]=poids_actuel;
            matincid->Matrice[sommet_fin][compteur_aretes]= - poids_actuel;
            poids_precedant = poids_actuel;
        }

    }
    if(compteur_aretes != m){
        printf("Erreur aretes %d, %d ! \n",m,compteur_aretes);
        exit(EXIT_FAILURE);
    }
    return matincid;
}