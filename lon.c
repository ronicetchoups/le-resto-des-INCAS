#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer la longueur
int calculerLongueur(struct Noeud* tete) {
    int compteur = 0;
    struct Noeud* courant = tete;
    while (courant != NULL) {
        compteur++;
        courant = courant->suivant;
    }
    return compteur;
}
