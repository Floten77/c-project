
#ifndef GRAPHE_H
#define GRAPHE_H
typedef struct{
    int nbsommets;//Nombre de sommets contenu dans le graphe
    int** matrice;//matrice d'adjacence du graphe
}Adja;

typedef struct{

    int id_sommets; //id sommet
    int date_debut; // premier passage sur le sommet
    int date_fin; //dernier passage sur le sommet
}Sommet;
#endif

Adja* AdjaVide(int n);
void AfficheAdja (Adja* A);
Adja* LireGraphe(const char* nom);
Adja* Transpose(Adja* A);
void profondeur(Adja* A, Sommet** S, int *date, int numSommet);
Sommet** Parcours_Profondeur(Adja* A);
void Afficher_Sommets(Sommet** S, int n);
Sommet** Trier(Sommet** S, int n);
int CompFortementConnexes(Adja* A, int* Comp);
