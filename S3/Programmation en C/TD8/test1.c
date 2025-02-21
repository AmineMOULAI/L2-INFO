#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//declarer un enregistrement qui contien numero de compte et un solde,cette structure representer dans le fichier binaire
typedef struct{
	int numcompt;
	int solde;
} compte;

//fonction pour creer le fichier binaire (f1)
void creationfichB(const char*fichB){
	FILE*f1=fopen(fichB,"wb");
	if (f1==NULL){
		printf("erreur de la creation du fichier binaire.\n");
		return;
	}
	int n;
	printf("entrer le nombre de compte a cree:");
	scanf("%d",&n);
	compte c;
	int i;
	for ( i=0 ; i<n ; i++) {
		printf("entrer le num de compte et le solde pour %d:",i+1);
		scanf("%d %d",&c.numcompt,&c.solde);
		fwrite(&c, sizeof(compte), 1, f1);
	}
	fclose(f1);
	printf("fichier binaire'%s'creer avec succes.\n",fichB);
}

//fonction pour creer le fichier texte (f2)
void creationfichT(const char*fichT){
	FILE*f2=fopen(fichT,"w");
	if (f2==NULL){
		printf("erreur de la creation de fichier texte.\n");
		return;
	}
	int n;
	printf("entrer le nombre de mise a jour a ajouter ");
	scanf("%d",&n);
	int numC,montant;
	int i;
	for (i=0;i<n;i++){
		printf("entrer le num de compte et le montant pour la mise a jour %d :",i+1);
		scanf("%d %d",&numC,&montant);
		fprintf(f2, "%d %d\n" , numC, montant);
	}
	fclose(f2);
	printf("fichier texte '%s'creer avec succes.\n ",fichT);
}

//fonction pour afficher le contenu du fichier binaire
void affichagefichB(const char *fichB) {
	FILE *f1 = fopen(fichB, "rb");
	if (f1 == NULL) {
		printf("Erreur d'ouverture du fichier binaire.\n");
		return;
	}
	compte c;
	printf("\nContenu du fichier binaire '%s':\n", fichB);
	while (fread(&c, sizeof(compte), 1, f1) == 1) {
		printf("Numéro de compte: %d, Solde: %d\n", c.numcompt, c.solde);
	}
	fclose(f1);
}

//fonction pour appliquer les mise a jour des soldes
void miseajour(const char *fichB, const char *fichT) {
    // Ouvrir le fichier binaire en mode lecture/écriture
    FILE *f1 = fopen(fichB, "rb+");
    if (f1 == NULL) {
        printf("Erreur d'ouverture du fichier binaire.\n");
        return;
    }
    // Ouvrir le fichier texte en mode lecture
    FILE *f2 = fopen(fichT, "r");
    if (f2 == NULL) {
        printf("Erreur d'ouverture du fichier texte.\n");
        fclose(f1); // Fermer le fichier binaire déjà ouvert
        return;
    }

    int numC;     // Numéro de compte lu depuis f2
    int montant;  // Montant à ajouter ou soustraire au solde

    // Lire chaque ligne du fichier texte
    while (fscanf(f2, "%d %d", &numC, &montant) == 2) {
        compte c;
        rewind(f1); // Revenir au début du fichier binaire

        int trouve = 0; // Indiquer si le compte a été trouvé
        while (fread(&c, sizeof(compte), 1, f1) == 1) {
            if (c.numcompt == numC) {
                c.solde += montant;
                // Revenir en arrière pour réécrire l'enregistrement mis à jour
                if (fseek(f1, -((long)sizeof(compte)), SEEK_CUR) != 0) {
                    printf("Erreur lors de la mise à jour du compte %d.\n", numC);
                } else {
                    fwrite(&c, sizeof(compte), 1, f1);
                    printf("Compte %d mis à jour avec succès.\n", numC);
                }
                trouve = 1;
                break;
            }
        }
        // Si le compte n'a pas été trouvé, afficher un message d'erreur
        if (!trouve) {
            printf("Compte %d non trouvé dans le fichier binaire.\n", numC);
        }
    }

    // Fermeture des fichiers
    fclose(f1);
    fclose(f2);
    printf("Mise à jour terminée.\n");
}

int main() {
//Exemple noms des fichiers existe deja, vous pouveez utiliser des fichier qui existe deja avec des nom different c pas forcement compte et ajout
    const char *fichB = "comptes"; // Fichier binaire contenant les comptes
    const char *fichT = "ajout";   // Fichier texte contenant les mises à jour
 
int choix;
do {
	printf("\nMenu:\n");
	printf("1. Creer le fichier binaire (f1)\n");
	printf("2. Creer le fichier texte (f2)\n");
	printf("3. Appliquer les mises à jour\n");
	printf("4. Afficher le contenu du fichier binaire\n");
	printf("5. Quitter\n");
	printf("Entrer votre choix :");
	scanf("%d", &choix );
	switch (choix){
		case 1: creationfichB(fichB); 
		break;
		
		case 2: creationfichT(fichT);
		break;
		
		case 3: miseajour(fichB,fichT);
		break;
		
		case 4: affichagefichB(fichB);
		break;
		
		case 5: printf("Au revoir !\n");
		break;
		
		default:
			printf("Choix invalide. Réessayez.\n");
			
  	}
} while ( choix != 5 );
    
    return 0 ; 
}
