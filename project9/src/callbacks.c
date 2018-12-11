#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <stdio.h>
#include "login.c"
#include "personne.c"



void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{int n=150,check = -1;
     char b[70]="Bienvenue dans l'espace ";
     char c[50]="mot de passe ou login incorrect";
     GtkWidget *input1;
     GtkWidget *input2;
     GtkWidget *output1;
     GtkWidget *output2;
     GtkWidget *window2med;
     GtkWidget *window1med;



     window2med=create_window2med();
     input1=lookup_widget(objet_graphique, "entry1med");
     input2=lookup_widget(objet_graphique, "entry2med");
     output1=lookup_widget(objet_graphique, "label4med");
     window1med=lookup_widget(objet_graphique,"window1med");
     char nom[20];
     strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
     char pass[20];
     strcpy(pass,gtk_entry_get_text(GTK_ENTRY(input2)));
     check = check_user(nom,pass,n);
     if (check==0){
      gtk_widget_hide(window1med);
     strcat(b,nom);
     gtk_widget_show(window2med);
     output2=lookup_widget(window2med, "label5med");
     gtk_label_set_text(GTK_LABEL(output2),b);
     }else{
     gtk_label_set_text(GTK_LABEL(output1),c);
     }

}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1med;
GtkWidget *window2med;
GtkWidget *window3med;
window3med=create_window3med();
window2med=lookup_widget(objet_graphique,"window2med");
gtk_widget_hide(window2med);
gtk_widget_show(window3med);
treeview1med=lookup_widget(window3med,"treeview1med");
afficher_fiche(treeview1med);







}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2med;
GtkWidget *window3med;
window2med=create_window2med();
window3med=lookup_widget(objet_graphique,"window3med");
gtk_widget_hide(window3med);
gtk_widget_show(window2med);

}


void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
                             
{

  char cin[50];
  fiche p;
  FILE*f;
  GtkWidget *input;
  GtkWidget *window3med;
  GtkWidget *window5med;
  GtkWidget *output1;
  GtkWidget *output2;
  GtkWidget *output3;
  GtkWidget *output4;
  GtkWidget *output5;
  GtkWidget *output6;
  GtkWidget *output7;
  GtkWidget *output8;
  GtkWidget *output9;
 



  input=lookup_widget(objet_graphique,"entry8med");
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  window5med=create_window5med();
  window3med=lookup_widget(objet_graphique,"window3med");
  gtk_widget_hide(window3med);
  gtk_widget_show(window5med);
  output1=lookup_widget(window5med,"entry16med");
  output2=lookup_widget(window5med,"entry10med");
  output3=lookup_widget(window5med,"entry11med");
  output4=lookup_widget(window5med,"spinbutton4med");
  output5=lookup_widget(window5med,"spinbutton5med");
  output6=lookup_widget(window5med,"spinbutton6med");
  output7=lookup_widget(window5med,"entry12med");
  output8=lookup_widget(window5med,"entry13med");
  output9=lookup_widget(window5med,"entry14med");
  f=fopen("adh.txt","a+");
  if(f!=NULL)
  {
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",p.cin,p.Nom,p.prenom,p.jour,p.mois,p.annee,p.poids,p.taille,p.maladies)!=EOF)
    {
      if(strcmp(cin,p.cin)==0)
      {
        gtk_entry_set_text(GTK_ENTRY(output1),p.cin);
        gtk_entry_set_text(GTK_ENTRY(output2),p.Nom);
        gtk_entry_set_text(GTK_ENTRY(output3),p.prenom);
        gtk_entry_set_text(GTK_ENTRY(output4),p.jour);
        gtk_entry_set_text(GTK_ENTRY(output5),p.mois);
        gtk_entry_set_text(GTK_ENTRY(output6),p.annee);
        gtk_entry_set_text(GTK_ENTRY(output7),p.poids);
        gtk_entry_set_text(GTK_ENTRY(output8),p.taille);
        gtk_entry_set_text(GTK_ENTRY(output9),p.maladies);
      }
    }
    fclose(f);
  }


}




void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *treeview1med;
  GtkWidget *window3med;
  GtkWidget *output;
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label22med");
  window3med=(objet_graphique,"window3med");
  int n=9;
  char cin[9];
  input=lookup_widget(objet_graphique,"entry9med");
  strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input)));
  supprimer(cin,n);
  treeview1med=lookup_widget(objet_graphique,"treeview1med");
  afficher_fiche(treeview1med);
  gtk_label_set_text(GTK_LABEL(output),c);
}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window4med;
GtkWidget *window3med;
window4med=create_window4med();
window3med=lookup_widget(objet_graphique,"window3med");
gtk_widget_hide(window3med);
gtk_widget_show(window4med);
}


void
on_button11_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE*f;
char cin[30]; char nom[30]; char prenom[30];char poids[30];char jour[30];char mois [30];char annee[30];char taille[30];char maladies[30];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;

input1=lookup_widget(objet_graphique,"entry15med");
input2=lookup_widget(objet_graphique,"entry3med");
input3=lookup_widget(objet_graphique,"entry4med");
input4=lookup_widget(objet_graphique,"entry5med");
input5=lookup_widget(objet_graphique,"entry6med");
input6=lookup_widget(objet_graphique,"entry7med");
input7=lookup_widget(objet_graphique,"spinbutton1med");
input8=lookup_widget(objet_graphique,"spinbutton2med");
input9=lookup_widget(objet_graphique,"spinbutton3med");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(poids,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(taille,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(maladies,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(jour,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(mois,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(input9)));


f=fopen("/home/mezri/Projects/project9/src/adh.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s %s %s %s\n",cin,nom,prenom,jour,mois,annee,poids,taille,maladies);
fclose(f);
}

}


void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button14_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *treeview1med;
GtkWidget *window4med;
GtkWidget *window3med;
window4med=lookup_widget(objet_graphique,"window4med");
gtk_widget_destroy(window4med);
window3med=lookup_widget(objet_graphique,"window3med");
window3med=create_window3med();
gtk_widget_show(window3med);
treeview1med=lookup_widget(window3med,"treeview1med");
afficher_fiche(treeview1med);


}


void
on_button15_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

  fiche p;
  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*input6;
  GtkWidget*input7;
  GtkWidget*input8;
  GtkWidget*input9;
  GtkWidget*output;

  FILE*f;
  char c[]="modification terminee";
  output=lookup_widget(objet_graphique,"label38med");
  
  input1=lookup_widget(objet_graphique,"entry16med");
  input2=lookup_widget(objet_graphique,"entry10med");
  input3=lookup_widget(objet_graphique,"entry11med");
  input7=lookup_widget(objet_graphique,"spinbutton4med");
  input8=lookup_widget(objet_graphique,"spinbutton5med");
  input9=lookup_widget(objet_graphique,"spinbutton6med");
  input4=lookup_widget(objet_graphique,"entry12med");
  input5=lookup_widget(objet_graphique,"entry13med");
  input6=lookup_widget(objet_graphique,"entry14med");
 
  strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
  strcpy(p.jour,gtk_entry_get_text(GTK_ENTRY(input7)));
  strcpy(p.mois,gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(p.annee,gtk_entry_get_text(GTK_ENTRY(input9)));

  strcpy(p.poids,gtk_entry_get_text(GTK_ENTRY(input4)));
  strcpy(p.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
  strcpy(p.maladies,gtk_entry_get_text(GTK_ENTRY(input6)));
  
  
  modifier(p);
  gtk_label_set_text(GTK_LABEL(output),c);



}






void
on_button16_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1med;
GtkWidget *window5med;
GtkWidget *window3med;
window5med=lookup_widget(objet_graphique,"window5med");
gtk_widget_destroy(window5med);
window3med=lookup_widget(objet_graphique,"window3med");
window3med=create_window3med();
gtk_widget_show(window3med);
treeview1med=lookup_widget(window3med,"treeview1med");
afficher_fiche(treeview1med);



}


void
on_button17_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
                                       
GtkWidget *window2med;
GtkWidget *window6med;
window6med=create_window6med();
window2med=lookup_widget(objet_graphique,"window2med");
gtk_widget_hide(window2med);
gtk_widget_show(window6med);


}


void
on_button18_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
FILE*f;
char jour[30];char mois[30];char annee[30]; char cin[30]; char horaire[30];char duree[30];
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;

input1=lookup_widget(objet_graphique,"spinbutton7med");
input2=lookup_widget(objet_graphique,"spinbutton8med");
input3=lookup_widget(objet_graphique,"spinbutton9med");
input4=lookup_widget(objet_graphique,"entry19med");
input5=lookup_widget(objet_graphique,"entry17med");
input6=lookup_widget(objet_graphique,"entry18med");

strcpy(jour,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mois,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(annee,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(horaire,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(duree,gtk_entry_get_text(GTK_ENTRY(input6)));



f=fopen("/home/mezri/Projects/project9/src/disponibilité.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",jour,mois,annee,cin,horaire,duree);
fclose(f);
}
}



void
on_button19_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button20_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  
}



void
on_button21_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
                                        
GtkWidget *treeview2med;
GtkWidget *window6med;
GtkWidget *window7med;
window6med=lookup_widget(objet_graphique,"window6med");
gtk_widget_destroy(window6med);
window7med=lookup_widget(objet_graphique,"window7med");
window7med=create_window7med();
gtk_widget_show(window7med);
treeview2med=lookup_widget(window7med,"treeview2med");
afficher_fiche2(treeview2med);



}






void
on_button24_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button25_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *input;
  GtkWidget *treeview2med;
  GtkWidget *window7med;
  GtkWidget *output;
  char c[]="suppression";
  output=lookup_widget(objet_graphique,"label57med");
  window7med=lookup_widget(objet_graphique,"window7med");
  int n=9;
  char cin2[9];
  input=lookup_widget(objet_graphique,"entry21med");
  strcpy(cin2,gtk_entry_get_text(GTK_ENTRY(input)));
  supprimer2(cin2,n);
  treeview2med=lookup_widget(window7med,"treeview2med");
  afficher_fiche2(treeview2med);
  gtk_label_set_text(GTK_LABEL(output),c);
}



void
on_button23_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window6med;
GtkWidget *window7med;
window6med=create_window6med();
window7med=lookup_widget(objet_graphique,"window7med");
gtk_widget_hide(window7med);
gtk_widget_show(window6med);
}




void
on_button22_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2med;
GtkWidget *window7med;
window2med=create_window2med();
window7med=lookup_widget(objet_graphique,"window7med");
gtk_widget_hide(window7med);
gtk_widget_show(window2med);

}
void
on_button26_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2med;
GtkWidget *window8med;
window8med=create_window8med();
window2med=lookup_widget(objet_graphique,"window2med");
gtk_widget_hide(window2med);
gtk_widget_show(window8med);

}

void
on_button27_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window2med;
GtkWidget *window8med;
window2med=create_window2med();
window8med=lookup_widget(objet_graphique,"window8med");
gtk_widget_hide(window8med);
gtk_widget_show(window2med);

}




void
on_button28_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}

