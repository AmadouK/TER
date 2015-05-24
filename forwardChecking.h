
/**
 *  \file 	forwardChecking.h
 *
 *	\brief 	Contient la déclaration des fonctions pour l'exécution de l'algorithme du ForwardChecking
 *
 */

#if !defined  __forwardChecking_H__
#define __forwardChecking_H__

#include "utile.h"

/* -------------------------------------------------------------------------- */

int* affectation ;

/* -------------------------------------------------------------------------- */

int** initFC();

/* -------------------------------------------------------------------------- */

void afficheFC(int** values);

/* -------------------------------------------------------------------------- */

int CF(int** values,int variable,int x);

/* -------------------------------------------------------------------------- */

int FC(int variable, int** values);

/* -------------------------------------------------------------------------- */

void affectationFC(int** values,int variable, int x);

/* -------------------------------------------------------------------------- */

void testFC();

/* -------------------------------------------------------------------------- */

#endif /* forwardChecking  */
