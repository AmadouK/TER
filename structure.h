
/**
 *  \file 	structure.h
 *
 *	\brief 	Contient les déclaration de la structure représentant ..
 *
 */

#if !defined  __STRUCTURE_H__
#define __STRUCTURE_H__

/*Déclarations*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>



/***************************************************************************//**
**                                  Les stuctures                             **
*******************************************************************************/
//Structure représentant le tableau des variables
typedef struct tab_variable{
    //Triple pointeur. Double pointeur pour créer le tableau
    //et un pointeur supplémentaire pour avoir l'adresse du var_domaine
    struct var_domaine*** var;
} tab_variable;

//Structure représentant le tableau à créer s'il y a un arc entre deux variables
typedef struct var_domaine{
    int var1;
    int var2;
    int** valeurs;
} var_domaine;

/***************************************************************************//**
**                                  Variables globale                         **
*******************************************************************************/

// liens entre variables
tab_variable tab;

//nombre de variables
int nb_sommet;

// la taille de notre domaine
int taille_domaine;

// Tableau permettant de savoir si une variable est dans la liste. Nécessaire pour le fonctionnement de l'AC8
int* statut;

// la liste permettant d'executer l'AC8
int* liste;


#endif /* __STRUCTURE_H__ */


