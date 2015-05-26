
#if !defined  __AC8_H__
#define __AC8_H__

/*Déclarations*/

#include "utile.h"
#include "structure.h"
#include "generateur_graphe.h"

/* Spécifications: fonction permettant l'exécution de l'algorithme AC8 */
void AC8();

/* Spécifications: fonction permettant l'intialisation du statut et fait la première propagation */
void initialisation();

/* Spécifications: fonction permettant d'eliminer valeur du domaine de y s'il n a pas de lien dans le domaine de x*/
int whitoutap(int x, int y, int valeur);

/* Spécifications: fonction pour ajouter une variable x dans la liste d'attente*/
void ajouter_liste(int x);

/* Spécifications: fonction permettant d'enlever valeur du domaine de la variable x*/
void diminuer_domaine(int x,int valeur);

/* Spécifications: fonction permettant d'enlever un élément de la liste*/
int sortir_liste();

/* Spécifications: fonction permettant d'enleve une valeur du domaine d'une variable en lien 
avec x si elle n a pas de lien dans le domaine de x */
void propagation(int x);

#endif /* __AC8_H__  */
