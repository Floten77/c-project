#ifndef GRAPHE_H
#define GRAPHE_H
typedef struct{
    int nb_sommets;//Nombre de sommets contenu dans le graphe
    int nb_aretes;//nombre d'aretes dans le graphe
    int **matrice;//Représentation de la matrice d'incidence
}MatIncid;

typedef struct{
    int nbsommets;//Nombre de sommets contenu dans le graphe
    int** matrice;//matrice d'adjacence du graphe
}MatAdja;
#endif



MatIncid* MatIncidVide(int n, int m);
void AfficheMatIncid(MatIncid* A);
MatIncid* LireGraphe(const char * nom);
MatAdja* MatIncidVersAdja(MatIncid* A);
MatAdja* AdjaVide(int n);
void AfficheAdja (MatAdja* A);
void Ajouter(MatIncid* A, int k, int o, int p, int b);
int Cycle(int * Comp, int o, int b, int n);
MatIncid* Kruskal(MatIncid* A);
MatIncid* Prim(MatIncid* A, int s);