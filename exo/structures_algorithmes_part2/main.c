#include <stdio.h>
#include "graphes.c"

int main(){
    //MatIncid* matincid = MatIncidVide(3,7);
    //AfficheMatIncid(matincid);
    MatIncid* matincid = LireGraphe("graphes2.txt");
    AfficheMatIncid(matincid);
    return 0;
}