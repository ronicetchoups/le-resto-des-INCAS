void trier_et_afficher(Commande *tete) {
    if (tete == NULL) {
        printf("Aucune commande en cours.\n");
        return;
    }

    Commande *i, *j;
    int temp_duree, temp_numero;
    char temp_plat[50];

    for (i = tete; i != NULL; i = i->suivant) {
        for (j = i->suivant; j != NULL; j = j->suivant) {
            if (i->duree > j->duree) {
                temp_duree  = i->duree;
                i->duree    = j->duree;
                j->duree    = temp_duree;

                temp_numero = i->numero;
                i->numero   = j->numero;
                j->numero   = temp_numero;

                strcpy(temp_plat, i->plat);
                strcpy(i->plat, j->plat);
                strcpy(j->plat, temp_plat);
            }
        }
    }
    printf("\n.  COMMANDES PAR DURÉE   \n");
    Commande *actuelle = tete;
    while (actuelle != NULL) {
        printf("Commande #%d : %-20s | %d min\n",
               actuelle->numero, actuelle->plat, actuelle->duree);
        actuelle = actuelle->suivant;
    }
}