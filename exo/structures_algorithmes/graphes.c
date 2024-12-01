#include "graphes.h"
#include <stdio.h>
#include <stdlib.h>
Adja* AdjaVide(int n);
void AfficheAdja (Adja* A);
void freeAdja(Adja* A);
Adja* LireGraphe(const char* nom);
Adja* Transpose(Adja* A);
void profondeur(Adja* A, Sommet** S, int *date, int numSommet);
Sommet** Parcours_Profondeur(Adja* A);
void Afficher_Sommets(Sommet** S, int n);
Sommet** Trier(Sommet** S, int n);
int CompFortementConnexes(Adja* A, int* Comp);

Adja* AdjaVide(int n){
    Adja* adja = (Adja*) malloc(sizeof(Adja));
    adja->nbsommets = n;
    adja->matrice = (int**) malloc(sizeof(int*)*n);
    for(int i = 0;i<n;i++){
        adja->matrice[i] = (int*) calloc(n,sizeof(int));
    }
    return adja;
}

void AfficheAdja(Adja* A){
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

void freeAdja(Adja* A){

    for(int i = 0;i<A->nbsommets;i++){
        free(A->matrice[i]);
    }
    free(A->matrice);
    free(A);
}

Adja* LireGraphe(const char* nom){
    int nbsommets,debut_arc,fin_arc;
    FILE* file = fopen("graphe1.txt","r");
    char chaine[10]="";
    fgets(chaine,10,file);
    sscanf(chaine,"%d",&nbsommets);
    Adja* A = AdjaVide(nbsommets);
    while(fgets(chaine,10,file)  != NULL){
        sscanf(chaine,"%d %d",&debut_arc, &fin_arc);
        A->matrice[debut_arc][fin_arc] = 1 ;
    }
    fclose(file);
    return A;
}

Adja* Transpose(Adja* A){
    Adja* a = AdjaVide(A->nbsommets);
    for(int i = 0;i<A->nbsommets;i++){
        for(int j = 0;j<A->nbsommets;j++){
            if(A->matrice[i][j] == 1){
                a->matrice[j][i] = 1;
            }
        }
    }
    return a;
}

void profondeur(Adja* A, Sommet** S, int *date, int numSommet){

    (*date)++;
    S[numSommet]->date_debut = *date;
    for(int i = 0 ;i<A->nbsommets;i++){
        if(A->matrice[numSommet][i] == 1 && S[i]->date_debut == 0){
            profondeur(A,S,date,i);
        }
    }
    (*date)++;
    S[numSommet]->date_fin = *date;
}

Sommet** Parcours_Profondeur(Adja* A){
    int date = 0;
    Sommet** sommets = (Sommet**) malloc(sizeof(Sommet*)* A->nbsommets);
    for(int i = 0;i<A->nbsommets;i++){
        sommets[i] = (Sommet*) malloc(sizeof(Sommet));
        sommets[i]->id_sommets = i;
        sommets[i]->date_debut = 0;
        sommets[i]->date_fin = 0;
    }

    for(int j = 0;j<A->nbsommets;j++){
        if(sommets[j]->date_debut == 0){
            profondeur(A,sommets,&date,j);
        }
    }
    return sommets;

}

void Afficher_Sommets(Sommet** S, int n){

    for(int i=0;i<n;i++){
        printf("Sommet %d : date_debut = %d, date_fin = %d\n",S[i]->id_sommets,S[i]->date_debut,S[i]->date_fin);
    }
}

void free_sommets(Sommet** S, int n){
    for(int i = 0;i<n;i++){
        free(S[i]);
    }
    free(S);
}

Sommet** Trier(Sommet** S, int n){

    int max_date_fin = 0;
    Sommet* sommet_max;
    int pos;
    for(int i =0;i<n;i++){
        for(int j = i;j<n;j++){
            if(S[j]->date_fin > max_date_fin){
                max_date_fin = S[j]->date_fin;
                sommet_max = S[j];
                pos = j;
            }
        }
        S[pos] = S[i];
        S[i] = sommet_max;
        max_date_fin = 0;
    }
    return S;
}

int CompFortementConnexes(Adja* A, int* Comp){
    int date = 0,connexe = 0;
    Sommet** sommets_not_sorted = Parcours_Profondeur(A);
    Sommet** sommets_sorted = Trier(sommets_not_sorted,A->nbsommets);
    Adja* a_transpose = Transpose(A);
    Sommet** sommet_not_initialized = (Sommet**) malloc(sizeof(Sommet*)*A->nbsommets);
    for(int h = 0;h<A->nbsommets;h++){
        sommet_not_initialized[h] = (Sommet*) malloc(sizeof(Sommet));
        sommet_not_initialized[h]->date_debut = 0;
        sommet_not_initialized[h]->date_fin = 0;
        sommet_not_initialized[h]->id_sommets = h;
    }
    for(int i = 0;i<A->nbsommets;i++){
        if(Comp[sommets_sorted[i]->id_sommets] == 0){
            profondeur(a_transpose,sommet_not_initialized,&date,sommets_sorted[i]->id_sommets);
            Afficher_Sommets(sommet_not_initialized,A->nbsommets);
            connexe++;
            for(int j = 0; j<A->nbsommets;j++){
                if(sommet_not_initialized[j]->date_debut != 0 && Comp[sommet_not_initialized[j]->id_sommets] == 0){
                    Comp[sommet_not_initialized[j]->id_sommets] = connexe;
                }
            }
        }
    }
    return connexe;

}