#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

        typedef struct {
        char cin[20];
        char nom[20];
        char prenom[20];
        float montant;
        }client;


int main()
{

    client cli[20]; //struct
    client cli1;
    client tri[20];

    int choix;
    int menu=0;
    int retour;

        char recherch[20];
        int i;
        bool rech = false;

  start:
    printf("\n");
    printf("\t\t\t\t\tBIEN VENU SUR NOTRE APPLICATION BANCAIRES\n");

    printf("\n\t\t\t01-Entrer un seule comte bancaire.\n\t\t\t02-Entrer plusieure comptes bancaires.\n\t\t\t03-Quitter l’Application.");
   // printf("\n\t\t\t03-Operation.\n\t\t\t04-Affichege de listes de clients.");
   //printf("\n\t\t\t05-Fidelisation.\n\t\t\t06-Quitter l application.\n");
    scanf("\t\t\t%d",&choix);
   system("cls");

  switch (choix){

      case 1:{//entrer les information d'un seule client.
          printf("\n\tEntrer les information du clien:\n");
          printf("\t Nom et prenom:\t");
          scanf("%s%s",&cli1.nom,&cli1.prenom);
          printf("\t CIN:\t");
          scanf("%s",&cli1.cin);
          printf("\t Montant:\t");
          scanf("%f",&cli1.montant);
          system("cls");
          int operation;
          float mnt;
          op:
          printf("\n\tChoisir une operation:\n 01-Un retrait.\n 02-Un depot.\n 03-Verifier votre compte.\n");
          scanf("%d",&operation);
//RETIRER UN MONTANT DU COMPTE.
          switch (operation){
              case 1:{//retrait
                printf("\n Entrer le montant de Retrait.\t");
                scanf("%f",&mnt);
         if (mnt<cli1.montant){
         printf("\n Votre operation a ete bien effectuer.\n\t\tVotre montant et %.2fdh\n",cli1.montant-mnt);
         }//if
         else if (mnt>cli1.montant){
                printf("\n\tVotre sold et insufisant");
        } //else if
        while(retour=1||2){
        printf("\n\n\t\tCliquer sur:\n\t\t01 Pour Retourner au Menu Principale.\n\t\t02 Pour Retourner au Menu Des Operations");
        scanf("%d",&retour);
        if (retour==1){
            system("cls");
            goto start;
        }
        else if (retour==2){
            system("cls");
            goto op;
        }
         }
              break;}//case 1
//DEPOSER UN MONTANT AU COMPTE.
              case 2:{//depo
                printf("\n Entrer le montant a Deposer.\t");
                scanf("%f",&mnt);
                printf("\n\n Votre operation a ete bien effectuer.\n\t\tVotre montant et %.2fdh\n",cli1.montant+mnt);
       while(retour=1||2){
        printf("\n\n\t\tCliquer sur:\n\t\t01 Pour Retourner au Menu Principale.\n\t\t02 Pour Retourner au Menu Des Operations");
        scanf("%d",&retour);
        if (retour==1){
            system("cls");
            goto start;
        }
        else if (retour==2){
            system("cls");
            goto op;
        }
         }
               break;}//case 2


             case 3:{//check account
                printf("\n %s %s %s %.2fdh",cli1.cin,cli1.nom,cli1.prenom,cli1.montant);
        while(retour=1||2){
        printf("\n\n\t\tCliquer sur:\n\t\t01 Pour Retourner au Menu Principale.\n\t\t02 Pour Retourner au Menu Des Operations");
        scanf("%d",&retour);
        if (retour==1){
            system("cls");
            goto start;
        }
        else if (retour==2){
            system("cls");
            goto op;
        }
         }

              break;}//case 3
              }//operation switch
      break;}//case 1



      case 2:{//entrer les information de plusieur client.
          int i,nbr;
          printf("\n Entrer le nombre de client.\t");
          scanf("%d",&nbr);
          for (i=0;i<nbr;i++){
           printf("\n\tEntrer les information du clien %i:\n",i+1);
              printf("\t Nom et prenom:\t");
              scanf("%s%s",&cli[i].nom,&cli[i].prenom);
              printf("\t CIN:\t");
              scanf("%s",&cli[i].cin);
              printf("\t Montant:\t");
              scanf("%f",&cli[i].montant);
          }//for-la boucle des nombre de compte.
          system("cls");

//listes des operation et d'affichage.
           int op;
           start2:
              printf("\n 01 effectuer un Retrait.");
              printf("\n 02 effectuer un Depot.");
              printf("\n 03 Afficher La Liste Des Clients.");
              printf("\n 04 Effectuer un Recherche Par CIN.");
              printf("\n 05 Fidelisation.");
              printf("\n 06 Retourner au Menu Principale\n");
              scanf("%d",&op);
              system("cls");

        switch(op){
                int j;
                char cinR[20];
                float mnt,montant;
                int found=0;

            case 1:{
                do {
            printf("entrer le cin pour un Retrait:\t");
            scanf(" %s",&cinR);
          for(int j=0 ; j< nbr ;j++){
            if (strcmp(cli[j].cin,cinR) == 0){

              printf(" CIN  de %s \n",cli[j].nom);

              printf("entrer un monant a retirer de ce compte\t");
              scanf("%f",&mnt);
                if(cli[j].montant>mnt){
              cli[j].montant= cli[j].montant - mnt ;
              printf("votre montant et:%.2f",cli[j].montant);
                found=1;
              break;
              }
              else {printf("\n\tVotre Sold et Insufisant.");}
              }

            }
            if (found==0){
                printf("CIN incorrect\n");
            }
        }
        while(found==0);

printf("\n01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);

if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }


           goto start2;}//CASE 1 DE RETRAIT

            case 2:{
            printf(" \nEntrer le cin pour un Depot:\t");
            scanf(" %s",&cinR);

            int found2 = 0;
            for (j=0;j<nbr;j++){
                if (strcmp(cli[j].cin,cinR)==0){
                   printf("\n %s \t %s %s \t %.2fdh\n",cli[j].cin,cli[j].nom,cli[j].prenom,cli[j].montant);
                   found2 = 1;
                   printf("\n Entrer le Montant a Ajouter dans le Compte.\t");
                   scanf("%f",&mnt);
                      cli[j].montant +=  mnt;
                      printf("\n Votre solde et %.2f\n",cli[j].montant);
                  }//if
                   }//for
                   if (found2 == 0){
                       printf("\n CIN incorrect.\n");
                       }//if LE CIN N4EXISTE PAS.

 printf("\n01 Menu principale\n02 Listes des operations\n");
 scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }
            }// CASE 2 DEPOT
            case 3:{
                  int affich;

              printf("\n\t\t\t\tPour Afficher la Liste des Clients:\n");
              printf("\n\t01-Par Ordre Ascendant.\n\t02-Par OrdreDescendant.");
              printf("\n\t03-Par Ordre Ascendant a Un Chifre introduit.");
              printf("\n\t04-Par Ordre Descendant a Un Chifre introduit.\n");
              scanf("%d",&affich);
              system ("cls");

        switch(affich){
            case 1:{
                int i,j;
                printf("\n\t\t La Listes des Clien Par Ordre Ascendant:\n");
            for (i = 0; i < nbr; i++)
		        {
              for (j = i + 1; j < nbr; j++)
                {
                if (cli[i].montant > cli[j].montant)
                            {
                strcpy (tri[0].nom, cli[i].nom);
                strcpy (tri[0].cin, cli[i].cin);
                tri[0].montant = cli[i].montant;

                strcpy (cli[i].nom, cli[j].nom);
                strcpy (cli[i].cin, cli[j].cin);
                cli[i].montant = cli[j].montant;

                strcpy (cli[j].nom, tri[0].nom);
                strcpy (cli[j].cin, tri[0].cin);
                cli[j].montant = tri[0].montant;
                }
                }
                }
                for (i = 0; i < nbr; i++)
                {
            printf ("\t\t\t CIN: %s ", cli[i].cin);
            printf ("\tNom Prenom: %s %s\t ", cli[i].nom,cli[i].prenom);
            printf ("\t%.2fdh\n ",cli[i].montant);
            } //BOUCLE D'AFFICHAGE.
 printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
 scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }

            }//AFFICHAGE ASCENDANT

            case 2:{
                int i,j;
                printf("\n\t\t La Listes des Clien Par Ordre Descendant:\n");
            for (i = 0; i < nbr; i++)
		        {
              for (j = i + 1; j < nbr; j++)
                {
                if (cli[i].montant < cli[j].montant)
                            {
                strcpy (tri[0].nom, cli[i].nom);
                strcpy (tri[0].cin, cli[i].cin);
                tri[0].montant = cli[i].montant;

                strcpy (cli[i].nom, cli[j].nom);
                strcpy (cli[i].cin, cli[j].cin);
                cli[i].montant = cli[j].montant;

                strcpy (cli[j].nom, tri[0].nom);
                strcpy (cli[j].cin, tri[0].cin);
                cli[j].montant = tri[0].montant;
                }
                }
                }
                for (i = 0; i < nbr; i++)
                {
            printf ("\t\t\t CIN: %s ", cli[i].cin);
            printf ("\tNom Prenom: %s %s ", cli[i].nom,cli[i].prenom);
            printf ("\t%.2fdh\n ",cli[i].montant);
                }//BOUCLE D'AFFICHAGE.

printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }
            }//CASE  AFFICHEFE DESCENDANT

            case 3:{
               float mont;

                for (i = 0; i < nbr; i++)
		        {
              for (j = i + 1; j < nbr; j++)
                {
                if (cli[i].montant > cli[j].montant)
                            {
                strcpy (tri[0].nom, cli[i].nom);
                strcpy (tri[0].cin, cli[i].cin);
                tri[0].montant = cli[i].montant;

                strcpy (cli[i].nom, cli[j].nom);
                strcpy (cli[i].cin, cli[j].cin);
                cli[i].montant = cli[j].montant;

                strcpy (cli[j].nom, tri[0].nom);
                strcpy (cli[j].cin, tri[0].cin);
                cli[j].montant = tri[0].montant;
                }
                }
                }

                printf("\n\t\t\tEntrer un Montant Pour un Triage:\t");
                scanf("%f",&mont);
                 for(i=0;i<nbr;i++){
                     if(cli[i].montant>=mont){
                    printf("\n\t\tLes Montant Superieure sons:\n");
                    printf("\n\t\t %s\t%s %s\t %.2f",cli[i].cin,cli[i].nom,cli[i].prenom,cli[i].montant);
                    }
                  }//for
printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;

            }//CASE  AFFICHAGE SUPERIEURE ASCENDANT

            case 4:{
                float mont;

                for (i = 0; i < nbr; i++)
		        {
              for (j = i + 1; j < nbr; j++)
                {
                if (cli[i].montant < cli[j].montant)
                            {
                strcpy (tri[0].nom, cli[i].nom);
                strcpy (tri[0].cin, cli[i].cin);
                tri[0].montant = cli[i].montant;

                strcpy (cli[i].nom, cli[j].nom);
                strcpy (cli[i].cin, cli[j].cin);
                cli[i].montant = cli[j].montant;

                strcpy (cli[j].nom, tri[0].nom);
                strcpy (cli[j].cin, tri[0].cin);
                cli[j].montant = tri[0].montant;
                }
                }
                }

                printf("\n\t\t\tEntrer un Montant Pour un Triage:\t");
                scanf("%f",&mont);
                 for(i=0;i<nbr;i++){
                     if(cli[i].montant>=mont){
                    printf("\n\t\tLes Montant Superieure sons:\n");
                    printf("\n\t\t %s\t%s %s\t %.2f",cli[i].cin,cli[i].nom,cli[i].prenom,cli[i].montant);
                    }
                  }//for
printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }
            }
        }//AFFICHAGE SUPERIEUR DESCENDANT
       }//SWITCH D'AFFICHAGE.

       }//CASE 3 D'AFFICHAGE
            case 4:{
                printf("\n\t Entrer le CIN de Client\t");
                scanf("%s",recherch);

                for (i=0;i<nbr;i++){
                if (strcmp(cli[i].cin,recherch)==0){
                   printf("\n %s \t %s %s \t %.2fdh\n",cli[i].cin,cli[i].nom,cli[i].prenom,cli[i].montant);
                   rech=true;
                  break;
                 }//if
                }//FOR
                if (rech==false){
                    printf("\n\tCIN Introuvable.\n");
                    }
printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;   }
               } //RECHERCHE PAR CIN
            case 5:{
                int i,j;
                for (i = 0; i < nbr; i++)//MONTANT SUPERIEUR
		        {
              for (j = i + 1; j < nbr; j++)
                {
                if (cli[i].montant < cli[j].montant)
                            {
                strcpy (tri[0].nom, cli[i].nom);
                strcpy (tri[0].cin, cli[i].cin);
                tri[0].montant = cli[i].montant;

                strcpy (cli[i].nom, cli[j].nom);
                strcpy (cli[i].cin, cli[j].cin);
                cli[i].montant = cli[j].montant;

                strcpy (cli[j].nom, tri[0].nom);
                strcpy (cli[j].cin, tri[0].cin);
                cli[j].montant = tri[0].montant;
                }
                }
                }
                    for (i = 0; i < 3; i++){
                    cli[i].montant = cli[i].montant + cli[i].montant * 0.013;
                    }
                    for (i = 0; i < 3; i++){

                    printf ("\n\t\t\tCIN: %s ", cli[i].cin);
                    printf ("\tNom et Prenom: %s %s\t ", cli[i].nom,cli[i].prenom);
                    printf ("\tMontat: %.2f\n ", cli[i].montant);
                    }
printf("\n\n\t01 Menu principale\n02 Listes des operations\n");
scanf("%d",&retour);
if (retour==1){
 system("cls");
 goto start;
            }
else if (retour==2){
 system("cls");
 goto start2;
            }
            }//CASE 5 FEDILISATION

           case 6:{
               system("cls");
               goto start;
           }
        }//switch de plusieur comptes
     }//case 2 entrer plusieurs comptes
     case 3:{
         return 0;
     }//Quitter l’application

   }//switch principale des choix.

    return 0;
}
