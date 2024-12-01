#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

    srand(time(NULL));
    int t = 1;
    int *tab = (int*) malloc(sizeof(int)*t);
    for(int i = 0;i<t;i++){
        if(i < t/2){
            tab[i] = 0;
        }
        else{
            tab[i] = rand()% 100;
        }
    }

    for(int i = 0;i<t;i++){
        printf("Tableau element %d : %d\n",i,tab[i]);
    }
    free(tab);
    return 0;
}
