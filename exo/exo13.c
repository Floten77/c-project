#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** initialiser_matrice(){
    int** matrice = (int**) malloc(sizeof(int*)*5);
    srand(time(NULL));
    for(int i = 0;i<5;i++){
        matrice[i] = (int*) malloc(sizeof(int)*5);
    }

    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            matrice[i][j] = rand() % 100;
        }
    }
    return matrice;

}

void afficher_matrice(int** matrice){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(j == 0){
                printf("[%d",matrice[i][j]);
            }
            else if(j == 4){
                printf(",%d]\n",matrice[i][j]);
            }
            else{
                printf(",%d",matrice[i][j]);
            }
        }
    }
}

void free_matrice(int** matrice){
    for(int i = 0;i<5;i++){
        free(matrice[i]);
    }
    free(matrice);
}
int main(){


    int** matrice = initialiser_matrice();
    afficher_matrice(matrice);
    free_matrice(matrice);
    return 0;
}