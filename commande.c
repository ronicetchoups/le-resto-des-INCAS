#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Commande {
    char nom[50];
    int quantite;
    struct Commande* suivant;
} Commande;

// Ajouter au début
Commande* ajouterDebut(Commande* tete, char nom[], int qte) {
    Commande* nouveau = (Commande*)malloc(sizeof(Commande));
    strcpy(nouveau->nom, nom);
    nouveau->quantite = qte;
    nouveau->suivant = tete;
    return nouveau;
}

// Ajouter à la fin
Commande* ajouterFin(Commande* tete, char nom[], int qte) {
    Commande* nouveau = (Commande*)malloc(sizeof(Commande));
    strcpy(nouveau->nom, nom);
    nouveau->quantite = qte;
    nouveau->suivant = NULL;

    if (tete == NULL) return nouveau;

    Commande* temp = tete;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveau;

    return tete;
}

// Afficher la commande la plus demandée
void plusDemandee(Commande* tete) {
    if (tete == NULL) return;

    Commande* max = tete;
    Commande* temp = tete;

    while (temp != NULL) {
        if (temp->quantite > max->quantite) {
            max = temp;
        }
        temp = temp->suivant;
    }

    printf("Commande la plus demandee: %s (%d)\n", max->nom, max->quantite);
}