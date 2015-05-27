#if !defined  __HEURISTIQUE_H__
#define __HEURISTIQUE_H__

/*Déclarations*/

#include "forwardChecking.h"
#include "rfl.h"

/* Variable globale permettant de garder une trace dans l'ordre des variables chosies*/
int* var_affectee;

/* Spécifications: fonction permettant de choisir la variable avec le domaine le plus petit domaine dans un algorithme*/
int h_min_domaine(int** values);

/* Spécifications: fonction permettant de choisir la variable avec le domaine le plus grand domaine dans un algorithme*/
int h_max_contrainte();

/* Spécifications: fonction permettant de choisir la variable selon un calcul en fonction du nombre de variable dans le
domaine et la hauteur de l'arbre*/
int h_first_fail(int** values);

void h_affiche_var_affectee();

#endif /* __HEURISTIQUE_H__ */
