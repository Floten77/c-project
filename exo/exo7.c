#include <stdio.h>

int main(){

    int number;
    printf("Veuillez choisir le nombre : \n");
    scanf("%d",&number);
    if(number == 0){
        printf("Diviseur est 0");
    }
    else if(number == 1) {
        printf("Diviseur est 1");
    }
    else{
        for(int i = 2;i<=number;i++){
            if(number % i == 0){
                printf("%d est divisible par %d  \n",number,i);
            }
        }
    }
}