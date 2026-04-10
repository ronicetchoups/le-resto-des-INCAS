#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int pas = 0;

//declaration des variables globales
    typedef struct Commande {
        int numero;
        int prix; 
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
    Commande* actuelle = tete;
    if (tete == NULL) {
        printf("Aucune commande en cours.\n");
    }
    Commande *i, *j;//variables de parcours
    int temp_duree, temp_numero;//variables temporaires pour le tri
    char temp_plat[50];//variable temporaire pour le tri des plats
    while (actuelle != NULL) {
        printf("Commande #%d : %s | Quantité : %d unité(s)\n",actuelle->numero, actuelle->plat, actuelle->nombre);
        pause(1000);//pause pour simuler le temps de preparation
        actuelle = actuelle->suivant;
    }
}
//(9.)fonction pour calculer le nombre de clients qui ont passe une commande
void nbre_clients(Commande *tete) {
    Commande* actuelle = tete;
    while (actuelle != NULL) {
        pas = pas+actuelle->nombre ;//calcul du nombre de clients qui ont passe une commande
        actuelle = actuelle->suivant;
    }
}
//(10.)calcul du chiffre d'affaires de la soiree
int chiffre_affaires(Commande *tete) {
    int chiffre = 0;
    Commande* actuelle = tete;
    while (actuelle != NULL) {
        chiffre += actuelle->nombre * actuelle->prix; //prix par plats multiplié par le nombre de plats commandés pour chaque commande
        actuelle = actuelle->suivant;
    }
    return chiffre;
}

//(15.)suppression de la première commande de la liste
void supprimer_premiere(Commande **tete) {
    if (*tete == NULL) {
        printf("La liste des commandes est déjà vide.\n");
        return;
    }
    Commande* temp = *tete;
    *tete = (*tete)->suivant;//mise a jour de la tete de la liste
    free(temp);//liberation de la memoire allouee pour la premiere commande
    printf("La première commande a été supprimée.\n");
}

//(11.)fonction pour ajouter une commande au debut de la liste
void ajout_debut(Commande **tete) {//passage de la tete par reference pour modifier la liste
            int numcom, quantite;
            char nomplat[50];
            printf("Veuillez entrer les details de la nouvelle commande :\n");
            printf("Numero de la commande : ");
            scanf("%d",&numcom);
            printf("Nom du plat : ");
            scanf("%s",nomplat);
            printf("Quantité : ");
            scanf("%d",&quantite);
            //creation d'une nouvelle commande
            Commande* new_cmd = malloc(sizeof(Commande));
            new_cmd->numero = numcom; new_cmd->prix = 1; new_cmd->nombre = quantite; strcpy(new_cmd->plat, nomplat);
            new_cmd->suivant = *tete;//ajout de la nouvelle commande au debut de la liste
            *tete = new_cmd;//mise a jour de la tete de la liste
            printf("Nouvelle commande ajoutee au debut de la liste : Commande #%d : %s | Quantité : %d unité(s)\n",new_cmd->numero, new_cmd->plat, new_cmd->nombre);
}

//(12.)fonction pour ajouter une commande a la fin de la liste
void ajout_fin(Commande **tete) {//passage de la tete par reference pour modifier la liste
                printf("Veuillez entrer les details de la nouvelle commande :\n");
                int numcom, quantite;
                char nomplat[50];
                printf("Numero de la commande : ");
                scanf("%d",&numcom);
                printf("Nom du plat : ");
                scanf("%s",nomplat);
                printf("Quantité : ");
                scanf("%d",&quantite);
                //creation d'une nouvelle commande
                Commande* new_cmd = malloc(sizeof(Commande));
                new_cmd->numero = numcom;
                new_cmd->prix = 1;
                new_cmd->nombre = quantite;
                strcpy(new_cmd->plat, nomplat);
                new_cmd->suivant = NULL;
                if (*tete == NULL) {
                    *tete = new_cmd;//si la liste est vide, la nouvelle commande devient la tete de la liste
                    return;
                }
                new_cmd->numero = numcom; new_cmd->prix = 1; new_cmd->nombre = quantite; strcpy(new_cmd->plat, nomplat);
                new_cmd->suivant = NULL;//ajout de la nouvelle commande a la fin de la liste
                //parcours de la liste pour trouver le dernier element
                Commande* actuelle = *tete;
                while (actuelle->suivant != NULL) {
                    actuelle = actuelle->suivant;
                }
                actuelle->suivant = new_cmd;//ajout de la nouvelle commande a la fin de la liste
                printf("Nouvelle commande ajoutee a la fin de la liste : Commande #%d : %s | Quantité : %d unité(s)\n",new_cmd->numero, new_cmd->plat, new_cmd->nombre);
}

//(13.)fonction pour vider la liste des commandes
void vider_liste(Commande *tete) {
    Commande* actuelle = tete;
    while (actuelle != NULL) {
        Commande* temp = actuelle;
        actuelle = actuelle->suivant;
        free(temp);//liberation de la memoire allouee pour chaque commande
    }
    pause(3000);//pause pour simuler le temps de vidage de la liste
    tete = NULL;//mise a jour de la tete de la liste
    printf("La liste des commandes a ete videe...j'espere que vous savez ce que vous faites\n");
}

//(7.)fonction de gestion du menu administrateur
int main(){
//declaration des variables
    int i;
    int choix;
    char text[50];
Commande* tete = NULL;

// création de la liste des commandes
Commande* cmd1 = malloc(sizeof(Commande));
cmd1->numero = 101; cmd1->prix = 15000; cmd1->nombre = 45; strcpy(cmd1->plat, "eru");
cmd1->suivant = NULL;
tete = cmd1;
Commande* cmd2 = malloc(sizeof(Commande));
cmd2->numero = 102; cmd2->prix = 1000; cmd2->nombre = 20; strcpy(cmd2->plat, "ndole");
cmd2->suivant = NULL;
cmd1->suivant = cmd2;
Commande* cmd3 = malloc(sizeof(Commande));
cmd3->numero = 103; cmd3->prix = 2000; cmd3->nombre = 25; strcpy(cmd3->plat, "Mbongo"); 
cmd3->suivant = NULL;
cmd2->suivant = cmd3;
Commande* cmd4 = malloc(sizeof(Commande));
cmd4->numero = 104; cmd4->prix = 5000; cmd4->nombre = 5; strcpy(cmd4->plat, "Poulet DG"); 
cmd4->suivant = NULL;
cmd3->suivant = cmd4;
Commande* cmd5 = malloc(sizeof(Commande));
cmd5->numero = 105; cmd5->prix = 1500; cmd5->nombre = 15; strcpy(cmd5->plat, "Bissap"); 
cmd5->suivant = NULL;
cmd4->suivant = cmd5;
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
        //traitement du choix de l'administrateur
        if(choix == 1){
            //consulter les commandes en cours
            printf("Commandes en cours :\n");
            Commande* cmd1 = malloc(sizeof(Commande));
            cmd1->numero = 101; cmd1->prix = 15000; cmd1->nombre = 45; strcpy(cmd1->plat, "eru");
            cmd1->suivant = NULL;
            tete = cmd1;
            Commande* cmd2 = malloc(sizeof(Commande));
            cmd2->numero = 102; cmd2->prix = 1; cmd2->nombre = 20; strcpy(cmd2->plat, "ndole");
            cmd2->suivant = NULL;
            cmd1->suivant = cmd2;
            Commande* cmd3 = malloc(sizeof(Commande));
            cmd3->numero = 103; cmd3->prix = 1; cmd3->nombre = 25; strcpy(cmd3->plat, "Mbongo"); 
            cmd3->suivant = NULL;
            cmd2->suivant = cmd3;
            Commande* cmd4 = malloc(sizeof(Commande));
            cmd4->numero = 104; cmd4->prix = 1; cmd4->nombre = 5; strcpy(cmd4->plat, "Poulet DG"); 
            cmd4->suivant = NULL;
            cmd3->suivant = cmd4;
            Commande* cmd5 = malloc(sizeof(Commande));
            cmd5->numero = 105; cmd5->prix = 1; cmd5->nombre = 15; strcpy(cmd5->plat, "Bissap"); 
            cmd5->suivant = NULL;
            cmd4->suivant = cmd5;
    //appel de la fonction de tri et d'affichage des commandes
            trier_et_afficher(tete);
    //liberation de la memoire allouee pour les commandes
            printf("\nCommandes en cours !\n");
        }else if(choix == 2){
            //permet de consulter le nombre de clients qui ont passe une commande
            Commande* cmd1 = malloc(sizeof(Commande));
            cmd1->numero = 101; cmd1->prix = 15000; cmd1->nombre = 45; strcpy(cmd1->plat, "eru");
            cmd1->suivant = NULL;
            tete = cmd1;
            Commande* cmd2 = malloc(sizeof(Commande));
            cmd2->numero = 102; cmd2->prix = 1; cmd2->nombre = 20; strcpy(cmd2->plat, "ndole");
            cmd2->suivant = NULL;
            cmd1->suivant = cmd2;
            Commande* cmd3 = malloc(sizeof(Commande));
            cmd3->numero = 103; cmd3->prix = 1; cmd3->nombre = 25; strcpy(cmd3->plat, "Mbongo"); 
            cmd3->suivant = NULL;
            cmd2->suivant = cmd3;
            Commande* cmd4 = malloc(sizeof(Commande));
            cmd4->numero = 104; cmd4->prix = 1; cmd4->nombre = 5; strcpy(cmd4->plat, "Poulet DG"); 
            cmd4->suivant = NULL;
            cmd3->suivant = cmd4;
            Commande* cmd5 = malloc(sizeof(Commande));
            cmd5->numero = 105; cmd5->prix = 1; cmd5->nombre = 15; strcpy(cmd5->plat, "Bissap"); 
            cmd5->suivant = NULL;
            cmd4->suivant = cmd5;
            nbre_clients(tete);//appel de la fonction pour calculer le nombre de clients qui ont passe une commande
            printf("Ce soir dans le \"RESTO DES INCAS\", nous avons exactement : %d clients\n",pas);//afficher le nombre de clients qui ont passe une commande
        }else if(choix == 3){
            printf("voulez-vous ajouter une commande au debut de la liste ou a la fin de la liste ?\n");
            printf("  1. Ajouter au debut de la liste\n");
            printf("  2. Ajouter a la fin de la liste\n");
            printf("|--: ");//demander le choix de l'administrateur
            scanf("%d",&choix);
            if(choix == 1){
                ajout_debut(&tete);
                printf("Commande ajoutee au debut de la liste !\n");
                printf("\n");
                printf("Voici la liste des commandes apres l'ajout :\n");
                trier_et_afficher(tete);//afficher la liste des commandes apres l'ajout
            }else if(choix == 2){
                ajout_fin(&tete);
                printf("Commande ajoutee a la fin de la liste !\n");
                printf("\n");
                printf("Voici la liste des commandes apres l'ajout :\n");
                trier_et_afficher(tete);//afficher la liste des commandes apres l'ajout
            }
        }else if(choix == 4){
            printf("Voulez-vous supprimer la première commande ?\n");
            printf("  1. oui\n");
            printf("  2. non\n");
            printf("|--: ");//demander le choix de l'administrateur
            scanf("%d",&choix);
            if(choix == 1){
                printf("vous ne pouvez pas faire ca...vous n'avez pas encore assez d'argent pour prendre des decisions aussi idiotes\n");//message de l'assistant pour l'administrateur
                printf("serieusement...vous voulez vraiment supprimer la première commande ?\n");
                printf("  1. oui\n");
                printf("  2. non\n");
                printf("|--: ");//demander le choix de l'administrateur
                scanf("%d",&choix);
                if(choix == 1){
                    supprimer_premiere(&tete);//appel de la fonction pour supprimer la première commande
                    printf("Première commande supprimée le/la pere/mere !\n");
                    printf("\n");
                    printf("Voici la liste des commandes apres la suppression :\n");
                    trier_et_afficher(tete);//afficher la liste des commandes apres la suppression
                }else if(choix == 2){
                    printf("humm...\n");//message de confirmation pour l'administrateur
                }
            }else if(choix == 2){
                printf("Tres bon choix...je vous ai a l'oeil\n");//message de l'assistant pour l'administrateur
            }
        }else if(choix == 5){
            int fric = chiffre_affaires(tete);//appel de la fonction pour calculer le chiffre d'affaires de la soiree
        printf("Le chiffre d'affaires de ce soir est de :  %d FCFA c'est pas joli-joli tout ca\n",fric);//affichage du chiffre d'affaires de la soiree
        }else if(choix == 6){
            printf("Non mais oh....quelle inconscience !!!\n");//message de l'assistant pour l'administrateur
            printf("serieusement...vous voulez vraiment vider la liste des commandes ?\n");
            printf("  1. oui\n");
            printf("  2. non\n");
            printf("|--: ");//demander le choix de l'administrateur
            scanf("%d",&choix);
            if(choix == 1){
                Commande* tete = NULL;
                printf("ok richard waterson...je vais vider la liste des commandes pour vous...mais je ne suis pas sur que ce soit une bonne idee\n");//message de l'assistant pour l'administrateur
                vider_liste(tete);//appel de la fonction pour vider la liste des commandes
            }else if(choix == 2){
                printf("Hum l'enfant ci meme...\n");//message de l'assistant pour l'administrateur
            }
        }else{
            return 0;
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