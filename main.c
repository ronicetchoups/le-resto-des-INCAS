#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Commande {
    int numero;
    char plat[50];
    float prix;
    int quantite;
    struct Commande* suivant;
} Commande;

Commande* tete = NULL;

void ajouterCommande(int numero, char* plat, float prix, int quantite) {
    Commande* nouvelle = (Commande*)malloc(sizeof(Commande));
    nouvelle->numero = numero;
    strcpy(nouvelle->plat, plat);
    nouvelle->prix = prix;
    nouvelle->quantite = quantite;
    nouvelle->suivant = tete;
    tete = nouvelle;
}
