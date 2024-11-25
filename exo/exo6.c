#include <stdio.h>

int main(){

    int nb_input = 1;
    int lowest_number = 0;
    int great_number = 0;
    printf("Veuillez renseignez un a un la suite de nombre : \n");
    while (nb_input != 0){
        printf("Nombre :");
        scanf("%d",&nb_input);
        if(nb_input < lowest_number ){
            lowest_number = nb_input;
        }
        if(nb_input > great_number){
            great_number = nb_input;
        }
        printf("Fini ou stop ? pour continuer taper '1' ,pour stopper taper '0'\n1");
        scanf("%d", &nb_input);
        if(nb_input == 0){
            if(lowest_number > 0){
                lowest_number = 0;
            }
            if(great_number < 0){
                great_number = 0;
            }
        }
    }
    printf("Sur la serie d'entier , plus grand nombre = %d, plus petit nombre = %d",great_number,lowest_number);
    return 0;
}