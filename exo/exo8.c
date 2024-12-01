#include <stdio.h>

int main(){

    int nb_input1, nb_input2,nb1,nb2,reste;
    int quotient = 1;
    printf("Veuillez choisir un nombre : ");
    scanf("%d %d",&nb_input1,&nb_input2);

    if(nb_input1 < 0 || nb_input2 < 0){
        printf("Presence d un nombre negatif");
    }
    else{
        if(nb_input1 > nb_input2){
            nb1 = nb_input1;
            nb2 = nb_input2;
        }
        else{
            nb1 = nb_input2;
            nb2 = nb_input1;
        }
        while(nb2 * quotient < nb1){
            quotient ++;
        }
        quotient --;
        reste = nb1 - nb2*quotient;
        printf("Nombre donner en parametre qui sont %d et %d, voici la division entre %d/%d , quotient = %d, reste = %d",nb_input1,nb_input2,nb1,nb2,quotient,reste);
    }
    return 0;
}