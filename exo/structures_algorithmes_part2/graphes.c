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

MatIncid* LireGraphe(const char * nom){


    char chaine[100];
    int n,m,sommet_debut,sommet_fin,poids_actuel,poids_precedant=0,compteur_aretes=0;
    FILE* file = fopen(nom,"r+");
    fgets(chaine,100,file);
    sscanf(chaine,"%d %d",&n,&m);
    MatIncid* matincid = MatIncidVide(n,m);
    while(fgets(chaine,100,file) != NULL){
        sscanf(chaine,"%d %d %d",&sommet_debut,&poids_actuel,&sommet_fin);
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
            matincid->matrice[sommet_debut][compteur_aretes]=poids_actuel;
            matincid->matrice[sommet_fin][compteur_aretes]= - poids_actuel;
            poids_precedant = poids_actuel;
            compteur_aretes++;
        }

    }
    if(compteur_aretes != m){
        printf("Erreur aretes %d, %d ! \n",m,compteur_aretes);
        exit(EXIT_FAILURE);
    }
    return matincid;
}


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

MatAdja* MatIncidVersAdja(MatIncid* A){

    MatAdja* mat = AdjaVide(A->nb_sommets);
    int sommet_debut, sommet_fin;
    for(int i = 0;i<A->nb_aretes;i++){
        for(int j = 0;j<A->nb_sommets;j++){
            if(A->matrice[j][i] != 0){
                if(A->matrice[j][i] < 0){
                    sommet_fin = j;
                }
                else{
                    sommet_debut = j;
                }
            }
        }
        printf("iteration : %d ! %d %d,\n",i,sommet_debut,sommet_fin);
        mat->matrice[sommet_debut][sommet_fin] = 1;
        
    }
    return mat;
}


void Ajouter(MatIncid* A, int k, int o, int p, int b){

    if(k < 0 || k >= A->nb_aretes){
        printf("Indice renseigne ne rentre pas dans le graphe ! \n");
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i<A->nb_sommets;i++){
        if(A->matrice[i][k] != 0){
            printf("Une arete existante existe deja ! \n");
            exit(EXIT_FAILURE);
        }
    }
    A->matrice[o][k] = p;
    A->matrice[b][k] = -p;
}

int Cycle(int * Comp, int o, int b, int n){
    if(Comp[o] == Comp[b]){
        return 1;
    }
    for(int i = 0;i<n;i++){
        if(Comp[i] == Comp[o]){
            Comp[i] = b;
        }
    }
    return 0;

}

MatIncid* Kruskal(MatIncid* A){

    int* Comp = (int*) calloc(A->nb_sommets,sizeof(int));
    for(int i = 0;i<A->nb_sommets;i++){
        Comp[i] = i;
    }
    int sommet_debut,sommet_fin,poids,compteur_aretes=0;
    MatIncid* kruskal = MatIncidVide(A->nb_sommets,A->nb_sommets-1);
    for(int i = 0;i<A->nb_aretes;i++){
        for(int j = 0;j < A->nb_sommets;j++){
            if(A->matrice[j][i] != 0){
                if(A->matrice[j][i] < 0){
                    sommet_fin = j;
                }else{
                    sommet_debut = j;
                    poids = A->matrice[j][i];
                }
            }
        }
        if(!Cycle(Comp,sommet_debut,sommet_fin,kruskal->nb_sommets)){
            Ajouter(kruskal,compteur_aretes,sommet_debut,poids,sommet_fin);
            compteur_aretes++;
        }
        if(compteur_aretes >= kruskal->nb_sommets-1){
            break;
        }
    }
    return kruskal;

}

MatIncid* Prim(MatIncid* A, int s){

    MatIncid* prim = MatIncidVide(A->nb_sommets,A->nb_sommets-1);
    int poids_minimum=100000,sommet_debut,sommet_fin,compteur_aretes=0,aretes_minimum;
    int* aretes_parcourus = (int*) calloc(A->nb_aretes,sizeof(int));
    int* Comp = (int*) calloc(A->nb_sommets,sizeof(int));
    for(int i = 0;i<A->nb_sommets;i++){
        Comp[i] = i;
    }
    while(compteur_aretes < A->nb_sommets-1){
        for(int i = 0;i<A->nb_aretes;i++){
            if(aretes_parcourus[i] == 0){
                for(int j = 0;j<A->nb_sommets;j++){
                    if(Comp[j] == s){
                        if(A->matrice[j][i] == 0){
                            continue;//arete pas dans le composant connexe 
                        }
                        else{
                            if(abs(A->matrice[j][i]) < poids_minimum){
                                for(int k=0; k<A->nb_sommets;k++){
                                    if(A->matrice[k][i] != 0){
                                        if(A->matrice[k][i] < 0){
                                        sommet_fin = k;
                                        }
                                        else{
                                            sommet_debut = k;
                                            poids_minimum = A->matrice[k][i];
                                        }
                                    }
                                }
                                aretes_minimum = i;
                            }
                            break;
                        }
                    }
                }
            }
        }
        printf("%d %d \n",sommet_debut,sommet_fin);
        if(Cycle(Comp,sommet_debut,sommet_fin,A->nb_sommets)){
            aretes_parcourus[aretes_minimum] = 1; 
        }
        else{
            Ajouter(prim,compteur_aretes,sommet_debut,poids_minimum,sommet_fin);
            s=sommet_fin;
            aretes_parcourus[aretes_minimum] = 1;
            compteur_aretes++;
        }
        poids_minimum=100000;
    }
    return prim;

}