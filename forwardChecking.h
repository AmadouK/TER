
/**
 *  \file 	forwardChecking.h
 *
 *	\brief 	Contient la déclaration des fonctions pour l'exécution de l'algorithme du ForwardChecking
 *
 */

#if !defined  __forwardChecking_H__
#define __forwardChecking_H__

/*Déclarations*/
#include "utile.h"
#include "heuristique.h"

long nbAffectation ;

long nbAffectationHeuristique ;
/* Variabble globale permettant de garder les valeurs des variables affectées */
int* affectation ;

/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme du foward checking */
int** initFC();

/* Spécifications: fonction permettant d'afficher les variables dans le tableau du foward checking*/
void afficheFC(int** values);

/* Spécifications: fonction qui va verifier que l'initialisation d'une variable à x n'empèche
pas d'avoir des valeurs dans les autres variables*/
int CF(int** values,int variable,int x);

/* Spécifications: fonction récursive qui va executer l'algorithme du foward checking sur avec
les valeurs values sur une variable.*/
int FC(int variable, int** values);

/* Spécifications: fonction récursive qui va affecter une valeur x a une variable pendant le
foward checking. */
void affectationFC(int** values,int variable, int x);

/* Spécifications: fonction qui permet de tester l'algorithme du foward checking*/
void testFC();

/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme du foward checking */
int** initFC_heuristique();

/* Spécifications: fonction récursive qui va executer l'algorithme du foward checking sur avec
les valeurs values sur une variable.*/
int FC_heuristique(int variable, int** values,int choixHeuristique);

/* Spécifications: fonction récursive qui va affecter une valeur x a une variable pendant le
foward checking. */
void affectationFC_heuristique(int** values,int variable, int x);

/* Spécifications: fonction qui va verifier que l'initialisation d'une variable à x n'empèche
pas d'avoir des valeurs dans les autres variables*/
int CF_heuristique(int** values,int variable,int x);

#endif /* forwardChecking  */
