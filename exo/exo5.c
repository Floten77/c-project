#include <stdio.h>

int main(){
    int entier1, entier2, entier3;
    printf("Veuillez selectionner trois nombres :");
    scanf("%d %d %d",&entier1,&entier2,&entier3);
    if(entier1 >= entier2){
        if(entier1>= entier3){
            printf("Le nombre le plus grand est : %d",entier1);
        }
        else{
            printf("Le nombre le plus grand est : %d",entier3);
        }
    }
    else{
        if(entier2 >= entier3){
            printf("Le nombre le plus grand est : %d",entier2);
        }
        else{
            printf("Le nombre le plus grand est : %d",entier3);
        }
    }
    return 0;
}