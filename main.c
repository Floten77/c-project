#include <stdio.h>

int main(){

    printf("Hello world ! \n");
    int tab[10];

    for(int i = 0; i< 10; i++){
        tab[i] = i;
        printf("%d\n", tab[i]);
    }
}