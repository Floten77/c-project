#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void ask_user_int(){
    int entier1,entier2;
    printf("Veuillez donner un chiffre : ");
    scanf("%d",&entier1);
    printf("Veuillez donner un deuxième chiffre : ");
    scanf("%d",&entier2);
    printf("Voici les nombres que vous avez selectionne : %d , %d",entier1,entier2);
    
}

void ask_user_float(){
    float float1,float2;
    printf("Veuillez donner un chiffre : ");
    scanf("%f",&float1);
    printf("Veuillez donner un deuxième chiffre : ");
    scanf("%f",&float2);
    printf("Voici les nombres que vous avez selectionne : %.2f , %.2f",float1,float2); //round with format print, two numbers after comma

}
int main(){
    setlocale(LC_ALL, "fr-FR");
    printf("Hello world ! \n");
    ask_user_float();
    return 0;
}