
/**
 *  \file 	generateur_graphe.h
 *
 *	\brief 	Contient la déclaration des fonctions pour générer un graphe aléatoire
 *
 */

#if !defined  __GENERATEUR_GRAPHE_H__
#define __GENERATEUR_GRAPHE_H__

#include "structure.h"



/* -------------------------------------------------------------------------- */

var_domaine* genereDomaine(float s,int nbDomaine,int var1,int var2);

/* -------------------------------------------------------------------------- */

void genereGraphe(int nbSommet,int nbArrete,int nbDomaine,float sat);

/* -------------------------------------------------------------------------- */



#endif /* __GENERATEUR_GRAPHE_H__*/
