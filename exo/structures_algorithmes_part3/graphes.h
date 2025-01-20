#ifndef GRAPHE_H
#define GRAPHE_H
typedef struct{
    int nb_sommets;//Nombre de sommets contenu dans le graphe
    int nb_aretes;//nombre d'aretes dans le graphe
    int *Beta;//Représentation de Beta
    int *Alpha //Représentation des successeurs du sommet i où Alpha[0] = 0
}AdjaListe;
typedef struct{
    int nbsommets;//Nombre de sommets contenu dans le graphe
    int** matrice;//matrice d'adjacence du graphe
}MatAdja;
typedef struct{
    int nb_sommets;//Nombre de sommets contenu dans le graphe
    int nb_aretes;//nombre d'aretes dans le graphe
    int **matrice;//Représentation de la matrice d'incidence
}MatIncid;
typedef struct{
    int** matriceDjikstra;
    int dist_plus_court_chemins;
    int* chemin;
}Djikstra;
#endif

AdjaListe* AdjaListeVide(int n, int m);
void AfficheAdjaListe(AdjaListe* A);
MatAdja* LireGraphe(const char* nom);
MatAdja* AdjaVide(int n);
void AfficheAdja (MatAdja* A);
AdjaListe* AdjaVersAdjaListe(MatAdja* A);
MatIncid* AdjaVersMatIncid(MatAdja* A);
MatIncid* MatIncidVide(int n, int m);
void AfficheMatIncid(MatIncid* A);
Djikstra* algoDjikstra_with_adj(MatAdja* adja);
Djikstra* algoDjikstra_with_inc(MatIncid* matincid);
Djikstra* algoDjikstra_with_adjaliste(AdjaListe* listeadja);
int flot_max();
