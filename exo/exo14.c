#include <stdio.h>
#include <stdlib.h>


int ** initialize_calendar(){

    int ** calendar = (int **) malloc(sizeof(int*)*13);
    for(int i = 1 ; i<13;i++){
        if(i == 2){
            calendar[i] = (int*) malloc(sizeof(int)*28);
            for(int j = 0;j<28;j++){
                calendar[i][j] = j+1;
            } 
        }
        else if((i % 2 == 0 && i <= 7) ||(i % 2 == 1 && i > 7)){
            calendar[i] = (int*) malloc(sizeof(int)*30);
            for(int j = 0;j<30;j++){
                calendar[i][j] = j+1;
            }
        }
        else{
            calendar[i] = (int*) malloc(sizeof(int)*31);
            for(int j = 0;j<31;j++){
                calendar[i][j] = j+1;
            }
        }
    }

    return calendar;

}

void afficher_calendar(int** calendar){

    for(int i = 1 ; i<13;i++){
        printf("%d:",i);
        if(i == 2){
            for(int j = 0;j<28;j++){
                if(j == 0){
                    printf("[%d",calendar[i][j]);
                }
                else if(j == 27){
                    printf(",%d]\n",calendar[i][j]);
                }else{
                    printf(",%d",calendar[i][j]);
                }
    
            } 
        }
        else if((i % 2 == 0 && i <= 7) ||(i % 2 == 1 && i > 7)){
            for(int j = 0;j<30;j++){
                if(j == 0){
                    printf("[%d",calendar[i][j]);
                }
                else if(j == 29){
                    printf(",%d]\n",calendar[i][j]);
                }else{
                    printf(",%d",calendar[i][j]);
                }
            }
        }
        else{
            for(int j = 0;j<31;j++){
                if(j == 0){
                    printf("[%d",calendar[i][j]);
                }
                else if(j == 30){
                    printf(",%d]\n",calendar[i][j]);
                }else{
                    printf(",%d",calendar[i][j]);
                }
            }
        }
    }

}
void free_calendar(int** calendar){
    for(int i = 0;i<13;i++){
        free(calendar[i]);
    }
    free(calendar);
}

int main(){

    int** calendar = initialize_calendar();
    afficher_calendar(calendar);
    free_calendar(calendar);
    return 0;
}