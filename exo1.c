#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "fr-FR");
    printf("Hello world ! \n");
    int entier1,entier2;
    printf("Veuillez donner un chiffre : ");
    scanf("%d",&entier1);
    printf("Veuillez donner un deuxième chiffre : ");
    scanf("%d",&entier2);

    printf("Voici les nombres que vous avez selectionne : %d , %d",entier1,entier2);
    return 0;
}