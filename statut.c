#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int pas = 0;

//declaration des variables globales
    typedef struct Commande {
        int numero;
        int etat; 
        int nombre;
        char plat[50];
        struct Commande* suivant;
    } Commande;
//(8.)fonction de pause pour simuler le temps de preparation des commandes
    int pause(int milliseconds) {
        clock_t start_time = clock();
        while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
        return 0;
    }

//(6.)fonction de tri et d'affichage des commandes
void trier_et_afficher(Commande *tete) {
    if (tete == NULL) {
        printf("Aucune commande en cours.\n");
        return;
    }

    Commande *i, *j;//variables de parcours
    int temp_duree, temp_numero;//variables temporaires pour le tri
    char temp_plat[50];//variable temporaire pour le tri des plats

    Commande* actuelle = tete;
    while (actuelle != NULL) {
        printf("Commande #%d : %-20s | Quantité : %d unité(s)\n",actuelle->numero, actuelle->plat, actuelle->nombre);
        pause(1000);//pause pour simuler le temps de preparation
        pas = pas*actuelle->nombre ;//calcul du nombre de clients qui ont passe une commande
        actuelle = actuelle->suivant;
    }
}
//creons une liste factice
typedef struct statut{
    int numTable;
    struct statut *suivant;
}state;

//(7.)fonction de gestion du menu administrateur
int main(){

    int i;
    int choix;
    char text[50];
//debut
    printf("\nBievenue dans le menu de administrateur\n");
    //verification de l'identite de l'administrateur
    printf("Verifiez que vous etes humain\n");
    printf(" : ");
    scanf("%s",text);
    if(strcmp(text,"roboto")==0){
    printf("\nBienvenu dans votre noble restaurant cher administrateur vos objectifs budgétaires sont de 200000 FCFA pour cette soiree, quelle action voulez-vous effectuer ?\n");
    printf("  1. Consulter les commandes en cours\n");
    printf("  2. Consulter le nombre de clients\n");
    printf("  3. ajouter une commande \n");
    printf("  4. supprimer une commande\n");
    printf("  5. Calculer le chiffre d'affaires\n");
    printf("  6. vider la liste des commandes\n");
    printf("  7. Exit\n");
    printf("|--: ");//demander le choix de l'administrateur
    scanf("%d",&choix);

    if(choix == 1){
        //consulter les commandes en cours
        printf("Commandes en cours :\n");
        Commande* tete = NULL;
        Commande* cmd1 = malloc(sizeof(Commande));
        cmd1->numero = 101; cmd1->etat = 1; cmd1->nombre = 45; strcpy(cmd1->plat, "eru");
        cmd1->suivant = NULL;
        tete = cmd1;
        Commande* cmd2 = malloc(sizeof(Commande));
        cmd2->numero = 102; cmd2->etat = 1; cmd2->nombre = 20; strcpy(cmd2->plat, "ndole");
        cmd2->suivant = NULL;
        cmd1->suivant = cmd2;
        Commande* cmd3 = malloc(sizeof(Commande));
        cmd3->numero = 103; cmd3->etat = 1; cmd3->nombre = 25; strcpy(cmd3->plat, "Mbongo"); 
        cmd3->suivant = NULL;
        cmd2->suivant = cmd3;
        Commande* cmd4 = malloc(sizeof(Commande));
        cmd4->numero = 104; cmd4->etat = 1; cmd4->nombre = 5; strcpy(cmd4->plat, "Poulet DG"); 
        cmd4->suivant = NULL;
        cmd3->suivant = cmd4;
        Commande* cmd5 = malloc(sizeof(Commande));
        cmd5->numero = 105; cmd5->etat = 1; cmd5->nombre = 15; strcpy(cmd5->plat, "Bissap"); 
        cmd5->suivant = NULL;
        cmd4->suivant = cmd5;
//appel de la fonction de tri et d'affichage des commandes
        trier_et_afficher(tete);
//liberation de la memoire allouee pour les commandes
        free(cmd1);
        free(cmd2);
        free(cmd3);
        free(cmd4);
        free(cmd5);
        printf("\nCommandes en cours !\n");
    }else if(choix == 2){
        printf("Ce soir dans le \"RESTO DES INCAS\", nous avons exactement : %d clients\n",pas);//afficher le nombre de clients qui ont passe une commande
    }else if(choix == 3){
    }else if(choix == 4){
    }else{
    }

    }else if(strcasecmp(text,"quit")==0){
        printf("\n");
        system("./modo");
        printf("\n");
    }else{
        printf("bien essaye robot\n");//message d'erreur pour les robots ou les personnes qui ne sont pas l'administrateur
        printf("\n");
        system("./menu");//redirection vers le menu d'accueil
        printf("\n");
    }
}

