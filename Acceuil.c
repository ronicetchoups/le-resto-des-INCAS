#include<stdio.h>
#include<stdlib.h>



int x,Table,Command,numCommand,num,te,number;
char y;

//structure du menu
typedef struct{
    char nom[20];
    int prix;
    char description[150];
    int duree;
}Menu;

//commandes
        typedef struct Commande {
            int numero;
            int etat; 
            struct Commande* suivant;
        } Commande;
//ajouter commandes(1. fonction d'ajout de commande a la liste)
        Commande* ajouter(Commande* tete, int numero, int etat) {
            Commande* nouveau = malloc(sizeof(Commande));//allocation dynamique de memoire pour une nouvelle commande
            nouveau->numero = numero;
            nouveau->etat = etat;
            nouveau->suivant = tete;
            return nouveau;
        };
//(2. fonction d'affichage de la liste des commandes)
    void afficher(Commande* tete){
    while (tete != NULL) {
        if (tete->etat == 0){
            printf("cette Commande %d est deja PRETE\n", tete->numero);
            te = 0;
        }else{
            printf(" cette Commande %d n'est PAS prete\n", tete->numero);
            te = 1;
        }
        tete = tete->suivant;
    }
}
//(3. fonction de gestion du statut de la commande)
        void state_command() {
            Commande* liste = NULL;//initialiser la liste des commandes
            int numero, etat;
            //ajouter des commandes
            while (1) {
                printf("cher cuisinier, veuillez entrer le Numero de la commande (-1 pour arreter): ");
                scanf("%d", &numero);
                number = numero;
                if (numero == -1) break;//condition d'arret
                printf("Etat (0 = prete, 1 = pas prete): ");
                scanf("%d", &etat);
            liste = ajouter(liste, numero, etat);//ajouter la commande a la liste
            }
            printf("\nEtat des commandes:\n");
            afficher(liste);
        }
//menu
Menu plats[5] = {
    {"Eru", 10000, "Plat de Legumes mijotes a la viande de boeuf", 70},
    {"Ndole", 4500, "Plat aux feuilles de ndole avec son lit de serviette de boeuf et accompagne de plantain", 60},
    {"Koki", 7500, "Haricot écrasé vapeur accompagne de plaintains et ou de baton de manioc", 300},
    {"Poulet DG", 300, "Poulet rotis avec plantain", 35},
    {"Bissap", 1800, "Jus de plant de bissap importe de la region nordique camerounaise", 15}
};

//enregistrer la commande(4. fonction d'enregistrement de la commande)
void registerCommand(int numCommand,int numTable){
    if(numCommand != 0 && numTable != 0){
            printf("Parfait...Votre commande a bien ete enregistree, veuillez patientez un moment votre commande sera prete dans environs...laissez nous deviner : ...\n");//message de confirmation de l'enregistrement de la commande
            printf("... %d minutes\n",plats[numCommand-1].duree);//afficher le temps de preparation de la commande
            printf("Merci d'avoir choisi notre restaurant, nous esperons que vous passerez un bon moment chez nous\n");
    }else{
        printf("erreur");
        system("./modo");
    }
}

//(14.)fonction pour verifier le statut d'une commande
void state(){
            printf("Entrez le numero de votre commande : \n");
            scanf("%d",&numCommand);
            if(numCommand != 0 && numCommand == number){
                if(te== 0){
                    printf("votre commande est deja prete\n");
                }else{
                    printf("votre commande n'est pas encore prete\n");
                }
            }else{
                printf("votre commande n'existe pas\n");
            }
}

int size = sizeof(plats)/sizeof(plats[0]);//taille du menu

//main

//fonction principale du programme(5)
int main(){
    //authentification
    printf("Authentifiez vous svp\n");
    printf("1. client\n");
    printf("2. Administrateur\n");
    printf("Entrer le chiffre correspondant svp : ");
    scanf(" %d",&x);
    //menu client
    if (x==1){
        printf("Bienvenue dans le menu dans le menu client cher utilisateur, veuillez choisir un option svp : \n");//afficher les options du menu client
        printf("A- Menu du jour\n");
        printf("B- Commander\n");
        printf("C- Statut de votre commande\n");
        printf("D- Exit\n");
        printf("effectuer une action(sans espace svp) : ");//demander le choix de l'utilisateur
        scanf(" %c",&y);
        //menu du jour
            if (y=='a'||y=='A'){
                printf("=========BIENVENUE CHEZ LES INCAS, LE RESTAURANT QUI VOUS PLONGE DANS LA CULTURE DES PEUPLES ANCIENS PAR SES METS=======\n");//afficher le menu du jour
                //afficher les plats
                for (int i = 0; i < size; i++){
                    printf("%d. %s - %d FCFA \n",i+1,plats[i].nom, plats[i].prix);
                    printf("  %s - %d minutes\n",plats[i].description,plats[i].duree);
                }
                printf("\nLe menu est constitue de %d plats...pour commander, veuillez choisir l'option B dans le menu precedent\n",size);//message d'orientation pour commander
                system("./modo");//redirection vers le menu precedent
        //commander
            }else if(y=='b'||y=='B'){
                printf("Pour quelle table svp : ");//demander le numero de la table
                scanf("%d",&Table);
                //enregistrer la commande
                if(Table != 0){
                    printf("Veuillez saisir le numero de votre commande :");//demander le numero de la commande
                    scanf("%d",&Command);
                    if(Command != 0){
                    registerCommand(Command,Table);//enregistrer la commande
                    //redirection vers le menu de statut de la commande
                    }else{
                        printf("erreur\n");
                        system("./modo");
                    }
                }
            //statut de la commande
            }else if(y=='c'||y=='C'){
                state();//verifier le statut de la commande
            }else if(y=='d'||y=='D'){
                printf("Merci d'avoir choisi notre restaurant, nous esperons que vous passerez un bon moment chez nous\n");//message de remerciement pour le client
                system("./menu");//redirection vers le menu d'accueil
            //exit
            }else{
                printf("choix inavalide\n");
                system("./modo");//redirection vers le menu precedent
            }
    //menu administrateur
    }else if(x==2){
        system("./menu");//redirection vers le menu de l'administrateur
        printf("\n");
        printf("La fonctionnalite qui vous permet de changer le statut d'une commande\n");
        printf("[y/n] : ");//demander le choix de l'administrateur
        scanf(" %c",&y);
        if(y=='y'||y=='Y'){
            state_command();//changer le statut d'une commande
        }else if(y=='n'||y=='N'){
            printf("ok...je vous laisse dans votre menu\n");//message de confirmation pour l'administrateur
            system("./menu");//redirection vers le menu de l'administrateur
        }
    }else{
        printf("choix inavalide\n");
    }
}