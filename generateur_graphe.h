
/**
 *  \file 	generateur_graphe.h
 *
 *	\brief 	Contient la déclaration des fonctions pour générer un graphe aléatoire
 *
 */

#if !defined  __GENERATEUR_GRAPHE_H__
#define __GENERATEUR_GRAPHE_H__

/*Déclarations*/

#include "structure.h"

/* Spécifications: fonction permettant de génerer les valeurs d'un domaine avec le nombre d'élements dans le domaine, les deux variables liées et
s qui contient un nombre entre 0 et 1 permettant de savoir le nombre de valeurs du domaines qui doivent etre liées
*/
var_domaine* genereDomaine(float s,int nbDomaine,int var1,int var2);

/* Spécifications: fonction permettant de génerer en graphe aléatoire en fonction du nombre de sommets qu'il doit contenir,
du nombre d'arrête qu'il doit y avoir entre tous les sommets, du nombre d'éléments dans un domaine,
et sat qui contient un nombre entre 0 et 1 permettant de savoir le nombre de valeurs du domaines qui doivent etre liées
*/
void genereGraphe(int nbSommet,int nbArrete,int nbDomaine,float sat);




#endif /* __GENERATEUR_GRAPHE_H__*/
