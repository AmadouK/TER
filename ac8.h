
#if !defined  __AC8_H__
#define __AC8_H__

#include "utile.h"
#include "structure.h"
#include "generateur_graphe.h"
/* -------------------------------------------------------------------------- */

void AC8();

/* -------------------------------------------------------------------------- */

void initialisation();

/* -------------------------------------------------------------------------- */

int whitoutap(int x, int y, int valeur);

/* -------------------------------------------------------------------------- */

void ajouter_liste(int x);

/* -------------------------------------------------------------------------- */

void diminuer_domaine(int x,int valeur);

/* -------------------------------------------------------------------------- */

int sortir_liste();

/* -------------------------------------------------------------------------- */

void propagation(int x);

/* -------------------------------------------------------------------------- */

#endif /* __AC8_H__  */
