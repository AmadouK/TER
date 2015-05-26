/**
 *  \file 	rfl.h
 *
 *	\brief 	Contient la d�claration des fonctions pour l'ex�cution de l'algorithme du RFL
 *
 */

#if !defined  __rfl_H__
#define __rfl_H__

/*D�clarations*/

#include "utile.h"
#include "ac8.h"

/* Variabble globale permettant de garder les valeurs des variables affect�es */
int* affectation ;

/* Sp�cifications: fonction permettant d'initialiser les variables permettant d'ex�cuter l'algorithme RFL */
void initRFL();

/* Sp�cifications: fonction permettant de r�cup�rer le domaine de chaque variable */
int **getDomaine();

/* Sp�cifications: fonction permettant d'afficher les variables dans le tableau du RFL*/
void afficheRFL(int** values);

/*Sp�cifications : Fonction permettant d'executer l'algorithme du RFL sur une variable*/
int RFL(int variable);

 /*Sp�cifications : Fonction permettant de modifier la structure pour simuler l'affectation de la variable � x*/
void affectationRFL(int variable, int x);

/*Sp�cifications : Fonction permettant de remettre l'�tat de la structure en cas de backtrack*/
void backtrack_RFL(tab_variable copie);

/* Sp�cifications: fonction permettant de cr�er une copie de la structure en cas de Backtrack */
tab_variable createCopie();

/*Sp�cifications : Fonction permettant de d�marrer l'algoriithme RFL sur tout la structure*/
void testRFL();

#endif /* __rfl_H__ */