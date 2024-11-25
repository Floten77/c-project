#include <stdio.h>

int main(){


    char letter;
    printf("Veuillez choisir une lettre de l'alphabet ou bien un chiffre : ");
    scanf("%c",&letter);
    printf("charactère : %c, code = %d, hexa = %X ",letter,letter,letter);
    return 0;
}