#include <stdio.h>
#include <stdlib.h>

typedef struct Commande {
    int numero;
    int etat; 
    struct Commande* suivant;
} Commande;

Commande* ajouter(Commande* tete, int numero, int etat) {
    Commande* nouveau = malloc(sizeof(Commande));
    nouveau->numero = numero;
    nouveau->etat = etat;
    nouveau->suivant = tete;
    return nouveau;
}

void afficher(Commande* tete) {
    while (tete != NULL) {
        if (tete->etat == 0)
            printf("cette Commande %d est deja PRETE\n", tete->numero);
        else
            printf(" cette Commande %d n'est PAS prete\n", tete->numero);

        tete = tete->suivant;
    }
}

int main() {
    Commande* liste = NULL;
    int numero, etat;

    while (1) {
        printf("cher cuisinier, veuillez entrer le Numero de la commande (-1 pour arreter): ");
        scanf("%d", &numero);

        if (numero == -1) break;

        printf("Etat (0 = prete, 1 = pas prete): ");
        scanf("%d", &etat);

        liste = ajouter(liste, numero, etat);
    }

    printf("\nEtat des commandes:\n");
    afficher(liste);

    return 0;
}