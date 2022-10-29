// tp.comp.l3.03@gmail.com
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void writeToFile(FILE *file, char *chaine)
{
    /** Créer et Ouvrir un nouveau fichier test.txt en mode
   Ecriture (w)**/
    file = fopen("etudiant.txt", "w");
    /**en cas d’erreur **/
    if (file == NULL)
    {
        printf("Erreur");
    }

    printf("Entrer une chaine: ");
    /** Lire la chaine de taille max 100 à partir de l’écran**/
    fgets(chaine, 100, stdin);
    /** Ecrire la chaine saisie dans le fichier test.txt **/
    fprintf(file, "%s", chaine);
    /** Fermer le Fichier test.txt **/
    fclose(file);
}
void openAFileAndReadIt(FILE *file, char *chaine)
{
    /**Lecture d'un fichier Ligne par Ligne et Affichage sur
Ecran **/
    /** Ouvrir le Fichier existant test.txt en mode Lecture (r) **/
    file = fopen("etudiant.txt", "r");
    if (file == NULL)
    {
        printf("Erreur");
        return 0;
    }

    /** Copier le contenu de chaque ligne du fichier
Texte.txt dans la variable chaine
(100 caractères Max) **/
    while (fgets(chaine, 100, file) != NULL)
    {
        /** Affichage sur Ecran de la ligne copiée
        dans la variable chaine **/
        puts(chaine);
        /**
        ou bien
        fprintf(stdout,"%s",chaine);
        ou bien
        printf("%s",chaine);
        **/
    }
    /** Fermer le Fchier test.txt**/
    fclose(file);
}
void readFileAndShowItInTerminal(FILE *file, char *chaine, char c)
{
    /**Lecture d'un fichier Carectere par Caractere et
Affichage sur Ecran **/
    /** Ouvrir le Fichier existant test.txt en mode Lecture
    (r) **/
    file = fopen("etudiant.txt", "r");
    if (file == NULL)
    {
        printf("Erreur");
        return 0;
    }
    /** Copier chaque caractère du fichier Texte.txt dans
    la variable c **/
    while ((c = fgetc(file)) != EOF)
    {
        /**Affichage sur Ecran caracère par caractère **/
        putc(c, stdout);
        /**
        Ou bien putchar(c);
        Ou bien
        fprintf(stdout,"%c",c);
        ou bien
        printf("%c",c);
        **/
    }
    /** Fermer le Fchier test.txt**/
    fclose(file);
}
int main(void)
{

    FILE *file;
    /** Déclaration d'une variable file de type FILE **/
    char chaine[100] = {0}; // variable chaine de caractère
    char c;

    // writeToFile(file, chaine);
    openAFileAndReadIt(file, chaine);
    readFileAndShowItInTerminal(file, chaine, c);
    return 0;
}
