#include <stdio.h>


void ask_numbers(int* entier1, int* entier2){

    printf("Veuillez choisir un nombre : ");
    scanf("%d",entier1);
    printf("Veuillez choisir un deuxieme nombre :");
    scanf("%d",entier2);
}

void switch_numbers(int* entier1, int* entier2){

    int entier_intermediary = *entier1;
    *entier1 = *entier2;
    *entier2 = entier_intermediary;
}
int main(){
    int entier1,entier2;

    ask_numbers(&entier1,&entier2);
    printf("Voici les variables initialisees, entier1 : %d, entier2: %d", entier1,entier2);
    switch_numbers(&entier1,&entier2);
    printf("Voici les variables après passage de la fonction switch, entier1 : %d, entier2: %d", entier1,entier2);
    return 0;
}