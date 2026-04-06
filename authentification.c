#include<stdio.h>
#include<stdlib.h>

int x,Table,Command;
char y;


void registerCommand(int numCommand,int numTable){
    if(numCommand != 0 && numTable != 0){
            printf("Parfait...Votre commande a bien ete enregistree, veuillez patientez un moment votre commande sera prete dans environs...laissez nous deviner : ...");
    }else{
        printf("erreur");
        system("./edo");
    }
}

typedef struct{
    char nom[20];
    int prix;
    char description[150];
    int duree;
}Menu;

Menu plats[5] = {
    {"Eru", 10000, "Plat de Legumes mijotes a la viande de boeuf", 70},
    {"Ndole", 4500, "Plat aux feuilles de ndole avec son lit de serviette de boeuf et accompagne de plantain", 60},
    {"Koki", 7500, "Haricot écrasé vapeur accompagne de plaintains et ou de baton de manioc", 300},
    {"Poulet DG", 300, "Poulet rotis avec plantain", 35},
    {"Bissap", 1800, "Jus de plant de bissap importe de la region nordique camerounaise", 15}
};

int size = sizeof(plats)/sizeof(plats[0]);

int main(){
    printf("Authentifiez vous svp\n");
    printf("1. client\n");
    printf("2. Administrateur\n");
    printf("Entrer le chiffre correspondant svp : ");
    scanf(" %d",&x);
    if (x==1){
        printf("Bienvenue dans le menu dans le menu client cher utilisateur, veuillez choisir un option svp : \n");
        printf("A- Menu du jour\n");
        printf("B- Commander\n");
        printf("C- Exit\n");
        printf("effectuer une action(sans espace svp) : ");
        scanf(" %c",&y);
            if (y=='A'||y=='a'){
                printf("=========BIENVENUE CHEZ LES INCAS, LE RESTAURANT QUI VOUS PLONGE DANS LA CULTURE DES PEUPLES ANCIENS PAR SES METS=======\n");
                for (int i = 0; i < size; i++){
                    printf("%d. %s - %d FCFA \n",i+1,plats[i].nom, plats[i].prix);
                    printf("  %s - %d minutes\n",plats[i].description,plats[i].duree);
                }
                
            }else if(y=='B'||y=='b'){
                printf("Pour quelle table svp : ");
                scanf("%d",&Table);
                if(Table != 0){
                    printf("Veuillez saisir le numero de votre commande :");
                    scanf("%d",&Command);
                    if(Command != 0){
                    registerCommand(Command,Table);
                    }else{
                        printf("erreur\n");
                        system("./edo");
                    }
                }else{
                        printf("erreur\n");
                        system("./edo");
                }
            }else if(y=='c'||y=='C'){
                printf("Termine\n");
            }else{
                printf("choix inavalide\n");
                system("./edo");
            }
    }else{
        return 0;
    }
}