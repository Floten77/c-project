#include <stdio.h>


int nb_recursive (int a,int b){


    if(b == 0){
        printf("b == 0 , %d\n",a);
        return 0;
    }
    if(b % 2 != 0){
        return nb_recursive(a,b-1) + a;
    }
        printf("%d * %d + %d\n",2*a,b/2,a);
        return nb_recursive(2*a,b/2);
}


// Fonction récursive pour effectuer la multiplication et afficher les étapes
int multiply_recursive(int a, int b) {
    if (b == 0) { // Condition de base
        printf("= %d * %d + 252\n", a, b);
        return 0;
    }

    if (b % 2 == 1) { // Si b est impair
        printf("= %d * %d + %d\n", a, b - 1, a); // Affichage avant l'appel récursif
        return multiply_recursive(a, b - 1) + a;
    } else { // Si b est pair
        printf("= %d * %d + ...\n", 2 * a, b / 2); // Affichage avant l'appel récursif
        return multiply_recursive(2 * a, b / 2);
    }
}

int main(){
    multiply_recursive(36,7);
    return 0;
}