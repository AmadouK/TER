/**
 *  \file 	rfl.h
 *
 *	\brief 	Contient la déclaration des fonctions pour l'exécution de l'algorithme du RFL
 *
 */

#if !defined  __rfl_H__
#define __rfl_H__

/*Déclarations*/

#include "utile.h"
#include "ac8.h"

/* Variabble globale permettant de garder les valeurs des variables affectées */
int* affectation ;

/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme RFL */
void initRFL();

/* Spécifications: fonction permettant de récupérer le domaine de chaque variable */
int **getDomaine();

/* Spécifications: fonction permettant d'afficher les variables dans le tableau du RFL*/
void afficheRFL(int** values);

/*Spécifications : Fonction permettant d'executer l'algorithme du RFL sur une variable*/
int RFL(int variable);

 /*Spécifications : Fonction permettant de modifier la structure pour simuler l'affectation de la variable à x*/
void affectationRFL(int variable, int x);

/*Spécifications : Fonction permettant de remettre l'état de la structure en cas de backtrack*/
void backtrack_RFL(tab_variable copie);

/* Spécifications: fonction permettant de créer une copie de la structure en cas de Backtrack */
tab_variable createCopie();

/*Spécifications : Fonction permettant de démarrer l'algoriithme RFL sur tout la structure*/
void testRFL();

#endif /* __rfl_H__ */