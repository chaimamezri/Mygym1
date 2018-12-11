#include <gtk/gtk.h>

typedef struct
{
char cin[20];
char Nom[20];
char prenom[20];
char poids[30];
char maladies[30];
char taille[30];
char jour[30];
char mois[30];
char annee[30];


}fiche;

void ajouter_fiche(fiche p);
void afficher_fiche(GtkWidget *liste);
void modifier(fiche p);
void supprimer(char cin[],int n);



typedef struct
{
char jour2[30];
char mois2[30];
char annee2[30];
char cin2[20];
char horaire[30];
char duree[30];

}fiche2;
void afficher_fiche2(GtkWidget *liste);

void supprimer2(char cin2[],int n);











