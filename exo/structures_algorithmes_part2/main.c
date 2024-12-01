#include <stdio.h>
#include "graphes.c"

int main(){
    //MatIncid* matincid = MatIncidVide(3,7);
    //AfficheMatIncid(matincid);
    MatIncid* matincid = LireGraphe("graphes2.txt");
    AfficheMatIncid(matincid);
    //MatAdja* mat = MatIncidVersAdja(matincid);
    //AfficheAdja(mat);
    //freeMatIncid(matincid);
    //freeAdja(mat);

    //MatIncid* matincid2 = MatIncidVide(5,8);
    //Ajouter(matincid2,5,1,7,4);
    //Ajouter(matincid2,6,0,6,2);
    //AfficheMatIncid(matincid2);
    //freeMatIncid(matincid2);

    printf("KRUSKAL: \n");
    MatIncid* kruskal = Kruskal(matincid);
    AfficheMatIncid(kruskal);

    freeMatIncid(kruskal);
    freeMatIncid(matincid);
    return 0;
}