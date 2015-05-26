
#if !defined  __AC8_H__
#define __AC8_H__

/*D�clarations*/

#include "utile.h"
#include "structure.h"
#include "generateur_graphe.h"

/* Sp�cifications: fonction permettant l'ex�cution de l'algorithme AC8 */
void AC8();

/* Sp�cifications: fonction permettant l'intialisation du statut et fait la premi�re propagation */
void initialisation();

/* Sp�cifications: fonction permettant d'eliminer valeur du domaine de y s'il n a pas de lien dans le domaine de x*/
int whitoutap(int x, int y, int valeur);

/* Sp�cifications: fonction pour ajouter une variable x dans la liste d'attente*/
void ajouter_liste(int x);

/* Sp�cifications: fonction permettant d'enlever valeur du domaine de la variable x*/
void diminuer_domaine(int x,int valeur);

/* Sp�cifications: fonction permettant d'enlever un �l�ment de la liste*/
int sortir_liste();

/* Sp�cifications: fonction permettant d'enleve une valeur du domaine d'une variable en lien 
avec x si elle n a pas de lien dans le domaine de x */
void propagation(int x);

#endif /* __AC8_H__  */
