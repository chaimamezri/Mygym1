
#include <stdio.h>
#include <string.h>
#include "personne.h"
#include <gtk/gtk.h>
enum

{
	CIN,
	NOM,
	PRENOM,
	JOUR,
        MOIS,
        ANNEE,
        POIDS,
        TAILLE,
        MALADIES,
	COLUMNS
};

void afficher_fiche(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    char cin[20];
    char nom[20];
    char prenom[20];
    char jour[30];
    char mois[30];
    char annee[30];
    char poids[30];
    char taille[30];
    char maladies[30];
    store=NULL;
    FILE *f;
    
    //store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    if(store==NULL)
    {


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" cin",renderer,"text",CIN,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Prenom",renderer,"text",PRENOM,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",JOUR,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Mois",renderer,"text",MOIS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Annee",renderer,"text",ANNEE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Poids",renderer,"text",POIDS,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
     
          renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Taille",renderer,"text",TAILLE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes(" Maladies",renderer,"text",MALADIES,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);








        
}


    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    f=fopen("/home/mezri/Projects/project9/src/adh.txt","r");
    if(f==NULL)
    {return;}
    else
    { f=fopen("/home/mezri/Projects/project9/src/adh.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,jour,mois,annee,poids,taille,maladies)!=EOF)
       {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter,CIN, cin, NOM, nom, PRENOM, prenom, JOUR,jour,MOIS,mois,ANNEE,annee,POIDS,poids,TAILLE,taille,MALADIES,maladies, -1);
       }
       fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }

}

void modifier(fiche p)
{
  fiche c;
  FILE*f;
  FILE *f1;
  f=fopen("adh.txt","a+");
  f1=fopen("adh1.txt","a+");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.Nom,c.prenom,c.jour,c.mois,c.annee,c.poids,c.taille,c.maladies)!=EOF)
    {
      if(strcmp(c.cin,p.cin)==0)
      {
        fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.Nom,p.prenom,p.jour,p.mois,p.annee,p.poids,p.taille,p.maladies);
      }
      else fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.Nom,c.prenom,c.jour,c.mois,c.annee,c.poids,c.taille,c.maladies);
    }
  }
  fclose(f);
  fclose(f1);
  remove("adh.txt");
  rename("adh1.txt","adh.txt");
}



void supprimer(char cin[],int n)
{
fiche p;
FILE*f;
FILE*f1;


f=fopen("adh.txt","a+");
f1=fopen("adh1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.Nom,p.prenom,p.jour,p.mois,p.annee,p.poids,p.taille,p.maladies)!=EOF)
{
if(strcmp(cin,p.cin)!=0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.Nom,p.prenom,p.jour,p.mois,p.annee,p.poids,p.taille,p.maladies);
}


}
}
fclose(f);
fclose(f1);
remove("adh.txt");
rename("adh1.txt","adh.txt");

}




enum

{

	JOUR2,
        MOIS2,
        ANNEE2,
        CIN2,
        HORAIRE,
        DUREE,
	COLUMNS2
};

void afficher_fiche2(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    
    char jour2[30];
    char mois2[30];
    char annee2[30];
    char cin2[20];
    char horaire[30];
    char duree[30];

    store=NULL;
    FILE *f;
    
    store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
    if(store==NULL)
    {


	renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("jour2",renderer,"text",JOUR2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("mois2",renderer,"text",MOIS2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("annee2",renderer,"text",ANNEE2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("cin2",renderer,"text",CIN2,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

         renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("horaire",renderer,"text",HORAIRE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer=gtk_cell_renderer_text_new();
        column=gtk_tree_view_column_new_with_attributes("duree",renderer,"text",DUREE,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        






        
}


    store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    f=fopen("/home/mezri/Projects/project9/src/disponibilité.txt","r");
    if(f==NULL)
    {return;}
    else
    { f=fopen("/home/mezri/Projects/project9/src/disponibilité.txt","a+");
        while(fscanf(f,"%s %s %s %s %s %s\n",jour2,mois2,annee2,cin2,horaire,duree)!=EOF)
       {
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store,&iter,JOUR2,jour2,MOIS2,mois2,ANNEE2,annee2,CIN2,cin2,HORAIRE,horaire,DUREE,duree,-1);
       }
       fclose(f);
    gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
    }

}





void supprimer2(char cin2[],int n)
{
fiche2 c;
FILE*f;
FILE*f1;


f=fopen("disponibilité.txt","a+");
f1=fopen("disponibilité1.txt","a+");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s\n",c.jour2,c.mois2,c.annee2,c.cin2,c.horaire,c.duree)!=EOF)
{
if(strcmp(cin2,c.cin2)!=0)
{
fprintf(f1,"%s %s %s %s %s %s\n",c.jour2,c.mois2,c.annee2,c.cin2,c.horaire,c.duree);
}


}
}
fclose(f);
fclose(f1);
remove("disponibilité.txt");
rename("disponibilité1.txt","disponibilité.txt");

}



