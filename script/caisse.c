#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Liste des billets et pièces disponibles
const double valeurs[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.5, 0.2, 0.1, 0.05};
int stock[] =         {10,   10,   10,  10,  10, 10, 10, 10, 10,10,10,  10,  10,  10,  10}; // Exemple de stock initial

// Fonction qui affiche le stock actuel
void afficher_stock() {
    printf("\nStock actuel :\n");
    for (int i = 0; i < sizeof(valeurs)/sizeof(valeurs[0]); i++) {
        printf("Rs%.2f : %d\n", valeurs[i], stock[i]);
    }
}

// Fonction qui calcule et rend la monnaie
void calcule_monnaie(double monnaie) {
    printf("\nMonnaie à rendre : Rs%.2f\n", monnaie);
    for (int i = 0; i < sizeof(valeurs)/sizeof(valeurs[0]); i++) {
int count = 0;
        while (monnaie >= valeurs[i] && stock[i] > 0) {
            monnaie -= valeurs[i];
            stock[i]--;
            count++;
        }
        if (count > 0) {
            printf("Rs%.2f x %d\n", valeurs[i], count);
        }
    }
    if (monnaie > 0.01) {
        printf("Impossible de rendre toute la monnaie. Il manque Rs%.2f\n", monnaie);
    }
}

int main() {
    srand(time(NULL));
    double montant_a_payer = (rand() % 10000) / 100.0; // Génère un montant entre 0 et 100
    printf("Montant à payer : Rs%.2f\n", montant_a_payer);

    double montant_donne = 0;
do {
        printf("Entrez le montant donné par le client : Rs");
        scanf("%lf", &montant_donne);
        if (montant_donne < montant_a_payer) {
            printf("Montant insuffisant. Veuillez saisir une valeur >= Rs%.2f\n", montant_a_payer);
        }
    } while (montant_donne < montant_a_payer);

    double monnaie = montant_donne - montant_a_payer;

    calcule_monnaie(monnaie);
    afficher_stock();

    // Gestion si plus de monnaie possible
    if (monnaie > 0.01) {
        int choix;
        printf("\n1. Fermer la caisse\n2. Remplir la caisse et continuer\nVotre choix : ");
        scanf("%d", &choix);
        if (choix == 2) {
            for (int i = 0; i < sizeof(stock)/sizeof(stock[0]); i++) stock[i] = 10;
printf("Caisse remplie !\n");
        } else {
            printf("Fermeture de la caisse.\n");
            return 0;
        }
    }

    return 0;
}
