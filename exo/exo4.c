#include <stdio.h>

int main(){

    int nombre;

    printf("Veuillez choisir un nombre : ");
    scanf("%d",&nombre);
    if(nombre % 2 == 0){
        printf("Est pair ! ");
    }
    else{
        printf("Est impair ! ");
    }
    return 0;
}