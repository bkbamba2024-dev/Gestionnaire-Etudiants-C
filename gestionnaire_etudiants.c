#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nom[30];
    char prenom[30];
    int age;
    char niveau[10];
    char filiere[30];
    float moyenne;
} etudiant;

void afficherMenu();
void ajouterEtudiant(etudiant etudiants[],int *n);
void afficherEtudiants(etudiant etudiants[],int n);
void rechercherEtudiant(etudiant etudiants[],int n);
void modifierEtudiant(etudiant etudiants[],int n);
void supprimerEtudiant(etudiant etudiants[],int *n);
void afficherMeilleurEtudiant(etudiant etudiants[],int n);
float afficher_Moyennegenerale(etudiant etudiants[],int n);

int main()
{
   etudiant etudiants[MAX];
   int n=0;
   int choix;

   do
   {
      afficherMenu();
      printf("Quel est votre choix ? ");
      scanf("%d", &choix);

      switch(choix)
      {
      case 1:
          ajouterEtudiant(etudiants, &n);
          break;

      case 2:
          afficherEtudiants(etudiants,n);
          break;

      case 3:
          rechercherEtudiant(etudiants,n);
          break;

      case 4:
          modifierEtudiant(etudiants, n);
          break;

      case 5:
          supprimerEtudiant(etudiants, &n);
          break;

      case 6:
          afficherMeilleurEtudiant( etudiants, n);
          break;

      case 7:
          printf("La Moyenne générale de la classe est : %.2f\n",afficher_Moyennegenerale(etudiants, n));
          break;

      case 8:
          printf("Merci d'avoir utilise le gestionnaire des etudiants.\n");
          break;

      default :
          printf("Choix invalide !\n");
          break;
      }


   }while (choix != 8);


   return 0;
}

void afficherMenu()
{
   printf("\n======================================================\n");
    printf("     GESTIONNAIRE DES ETUDIANTS \n");
    printf("=======================================================\n");
    printf("1. Ajouter un etudiant\n");
    printf("2. Afficher tous les etudiants\n");
    printf("3. Rechercher un etudiant\n");
    printf("4. Modifier un etudiant\n");
    printf("5. Supprimer un etudiant\n");
    printf("6. Afficher l'etudiant ayant la meilleure moyenne\n");
    printf("7. Afficher la moyenne générale\n");
    printf("8. Quitter\n");
    printf("=======================================================\n");
}

void ajouterEtudiant(etudiant etudiants[],int *n)
{
        if (*n >= MAX)
    {
        printf("La liste des etudiants est pleine !\n");
        return;
    }

        printf("Entrez le nom de l'etudiant : \n");
        scanf("%s",etudiants[*n].nom);

        printf("Entrez le prenom de l'etudiant : \n");
        scanf("%s",etudiants[*n].prenom);

        printf("Quel est l'age de %s %s : \n",etudiants[*n].nom,etudiants[*n].prenom);
        scanf("%d",&etudiants[*n].age);

        printf("L'etudiant %s %s est a quel niveau ? (Ex Bac+2): \n",etudiants[*n].nom,etudiants[*n].prenom);
        scanf("%s",etudiants[*n].niveau);

        printf("%s %s fait quoi comme filiere ? \n",etudiants[*n].nom,etudiants[*n].prenom);
        scanf("%s",etudiants[*n].filiere);

        printf("Quelle est la moyenne de %s %s  ? \n",etudiants[*n].nom,etudiants[*n].prenom);
        scanf("%f",&etudiants[*n].moyenne);

        printf("\n %s %s a bien ete ajoute \n",etudiants[*n].nom,etudiants[*n].prenom);

        (*n)++;

}

void afficherEtudiants(etudiant etudiants[],int n)
{
    if (n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return;
    }

    printf("\nNombre d'etudiant : %d\n", n);

    for(int i=0;i<n;i++)
    {
       printf("\n----- ETUDIANT %d -----\n", i + 1);
       printf("Nom : %s\n", etudiants[i].nom);
       printf("Prenom : %s\n", etudiants[i].prenom);
       printf("Age : %d\n", etudiants[i].age);
       printf("Niveau : %s\n", etudiants[i].niveau);
       printf("Filiere : %s\n",etudiants[i].filiere);
       printf("Moyenne : %.2f\n",etudiants[i].moyenne);

    }
}

void rechercherEtudiant(etudiant etudiants[],int n)
{
       if (n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom de l'etudiant : ");
    scanf("%s", nom);

    for(int i=0;i<n;i++)
    {
        if (strcmp(nom, etudiants[i].nom) == 0)
        {
            printf("\n----- ETUDIANT TROUVE -----\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Age : %d\n", etudiants[i].age);
            printf("Niveau : %s\n", etudiants[i].niveau);
            printf("Filiere : %s\n",etudiants[i].filiere);
            printf("Moyenne : %.2f\n",etudiants[i].moyenne);

            trouve = 1;
            break;

        }
    }

    if (trouve==0)
    {
        printf("Aucun etudiant trouve.\n");
    }
}

void modifierEtudiant(etudiant etudiants[],int n)
{
    if (n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom de l'etudiant : ");
    scanf("%s", nom);

    for(int i=0;i<n;i++)
    {
        if (strcmp(nom, etudiants[i].nom) == 0)
        {
            printf("\n----- ETUDIANT A MODIFIER -----\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Age : %d\n", etudiants[i].age);
            printf("Niveau : %s\n", etudiants[i].niveau);
            printf("Filiere : %s\n",etudiants[i].filiere);
            printf("Moyenne : %.2f\n",etudiants[i].moyenne);

            printf("Entrez le nouveau nom : ");
            scanf("%s", etudiants[i].nom);

            printf("Entrez le nouveau prenom : ");
            scanf("%s", etudiants[i].prenom);

            printf("Entrez le nouveau age : ");
            scanf("%d", &etudiants[i].age);

            printf("Entrez le niveau actuel : ");
            scanf("%s", etudiants[i].niveau);

            printf("Entrez la nouvelle filiere : ");
            scanf("%s", etudiants[i].filiere);

            printf("Entrez la nouvelle moyenne : ");
            scanf("%f", &etudiants[i].moyenne);

            printf("\n Etudiant modifie avec succes !\n");

            trouve = 1;
            break;

        }
    }

    if (trouve==0)
    {
        printf("Aucun etudiant trouve.\n");
    }

}

void supprimerEtudiant(etudiant etudiants[],int *n)
{
    if (*n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return;
    }

    char nom[30];
    int trouve = 0;

    printf("Entrez le nom de l'etudiant a supprimer : ");
    scanf("%s", nom);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(nom, etudiants[i].nom) == 0)
        {
            printf("\n----- ETUDIANT A SUPPRIMER -----\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Age : %d\n", etudiants[i].age);
            printf("Niveau : %s\n", etudiants[i].niveau);
            printf("Filiere : %s\n",etudiants[i].filiere);
            printf("Moyenne : %.2f\n",etudiants[i].moyenne);

            for (int j = i; j < *n - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }

            (*n)--;

            printf("Etudiant supprime avec succes !\n");

            trouve = 1;
            break;

        }
    }

    if (trouve==0)
    {
        printf("Aucun etudiant trouve.\n");
    }

}

void afficherMeilleurEtudiant(etudiant etudiants[],int n)
{
    if (n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return;
    }

    int indiceMax = 0;
    float Max = etudiants[0].moyenne;;
    for (int i = 0; i < n; i++)
    {
        if (Max<etudiants[i].moyenne)
        {
            Max = etudiants[i].moyenne;
            indiceMax = i;
        }

    }
    printf("\n----- ETUDIANT Avec la Meilleur Moyenne -----\n");
    printf("Nom : %s\n", etudiants[indiceMax].nom);
    printf("Prenom : %s\n", etudiants[indiceMax].prenom);
    printf("Age : %d\n", etudiants[indiceMax].age);
    printf("Niveau : %s\n", etudiants[indiceMax].niveau);
    printf("Filiere : %s\n",etudiants[indiceMax].filiere);
    printf("Moyenne : %.2f\n",etudiants[indiceMax].moyenne);
}

float afficher_Moyennegenerale(etudiant etudiants[],int n)
{
    float Sum=0,Moy;

    if (n == 0)
    {
        printf("Aucun etudiant sur la liste.\n");
        return 0.0;
    }

    for (int i = 0; i < n; i++)
    {
        Sum = Sum+etudiants[i].moyenne;
    }

    Moy = Sum/n;

    return Moy;

}
