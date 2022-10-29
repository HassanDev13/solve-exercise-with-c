//tp.comp.l3.03@gmail.com

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mot_De_La_Phrase
{
    char Mon_mot[20];
    struct Mot_De_La_Phrase *Adresse_Mot_suivant;
} Mot;

int CharIsSeperator(char chaine)
{
    if (chaine == ' ' || chaine == ',' || chaine == ';' || chaine == '.' || chaine == '!' || chaine == '?' || chaine == '-')
    {
        return 1;
    }

    return 0;
}
Mot *Inserer_a_la_fin(Mot *les_mots_de_laphrase, char *mot)
{
    // si la liste chainee est vdie
    if (les_mots_de_laphrase == NULL)
    {
        // cration de la liste / reservation de memoire pour le 1er element
        les_mots_de_laphrase = malloc(sizeof(Mot));
        // c'est le 1er et dernier element (donc le prochain element est NULL)
        les_mots_de_laphrase->Adresse_Mot_suivant = NULL;
        // copier le mot
        strcpy(les_mots_de_laphrase->Mon_mot, mot);
        // retourner l'addresse du 1er element
        return les_mots_de_laphrase;
    }
    // si la liste chainée n'est pas vide affecter le 1er élément a un pointeur temporaire
    Mot *dernier_mot = les_mots_de_laphrase;
    // tanque le pointeur suivant n'est pas NULL c a d on n’est pas arrivé au dernier
    while (dernier_mot->Adresse_Mot_suivant != NULL)
    {
        // passer a l'element suivant
        dernier_mot = dernier_mot->Adresse_Mot_suivant;
    }
    // créer un nouvel élément a la fin de la liste
    dernier_mot->Adresse_Mot_suivant = malloc(sizeof(Mot));
    // copier le mot
    strcpy(dernier_mot->Adresse_Mot_suivant->Mon_mot, mot);
    // c'est le 1er et dernier element (donc le prochain element est NULL)
    dernier_mot->Adresse_Mot_suivant->Adresse_Mot_suivant = NULL;
    // retourner l'addresse du 1er element
    return les_mots_de_laphrase;
}

Mot *Inserer_au_debut(Mot *les_mots_de_laphrase, char *mot)
{
    // creer un nouvel element
    Mot *premier_mot = malloc(sizeof(Mot));
    // copier la chaine de caractere
    strcpy(premier_mot->Mon_mot, mot);
    // affecter le pointeur du suivant au debut de la liste principale
    premier_mot->Adresse_Mot_suivant = les_mots_de_laphrase;
    // retourner l'@ du 1er element
    return premier_mot;
}

void printNumberOfNodes(Mot *les_mots_de_laphrase){
 

    /* Initialize count variable  */
 
    int count=0;
 
    /* Traverse the linked list and maintain the count */
 
    while(les_mots_de_laphrase != NULL){
 
       les_mots_de_laphrase = les_mots_de_laphrase->Adresse_Mot_suivant;
 
        /* Increment count variable. */
        count++;
 
    }
 
     /* Print the total count. */
 
    printf("Total no. of nodes is %d \n",count);
 
}
Mot * prepareTheWords(Mot *les_mots_de_laphrase, char *mot)
{
    char tmps[50];
    int j = 0 ;
    for (int i = 0; i <= strlen(mot); i++)
    {   
       
        if (CharIsSeperator(mot[i]) || i == strlen(mot) )
        {
            
            les_mots_de_laphrase = Inserer_a_la_fin(les_mots_de_laphrase, tmps);
            j = 0 ;
            tmps[j] = '/0';
        }
        else
        {
        
            tmps[j] = mot[i];
            j++ ;
        }
    }
    return les_mots_de_laphrase;
}

void print(Mot *head) {
    Mot *current_node = head;
   	while ( current_node != NULL) {
        printf("%s \n", current_node->Mon_mot);
        current_node = current_node->Adresse_Mot_suivant;
    }
}
int main(void)
{
    
   // printf("DONE %d ",CharIsSeperator('!'));
    Mot* listMot = NULL ;

    char phrase[20] = "RBYT,AZE,ZER,EZ";
    listMot =  prepareTheWords(listMot, phrase);
   // listMot = Inserer_a_la_fin(listMot , "Hello");
    printNumberOfNodes(listMot);

    print(listMot);
    return 0;

}
