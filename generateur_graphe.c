
/**
 *  \file 	generateur_graphe.c
 *
 *	\brief 	Contient l'implementation des fonctions pour générer un graphe aléatoire
 *
 */


#include "generateur_graphe.h"

//Fonction permettant de génerer aléatoirement les correspondances entre deux variables liées
var_domaine* genereDomaine(float s,int nbDomaine,int var1,int var2){
	/* Spécifications: fonction permettant de génerer les valeurs d'un domaine avec le nombre d'élements dans le domaine, les deux variables liées et
	s qui contient un nombre entre 0 et 1 permettant de savoir le nombre de valeurs du domaines qui doivent etre liées
    */
    var_domaine* v= (var_domaine*) malloc(sizeof(var_domaine));
    int nbCorrespondance = 0, rnd=0, i = 0, j = 0;
    float nbRempli = 0.;
    v->var1=var1;
    v->var2=var2;

    //Création du tableau et allocation de la mémoire
    v->valeurs=(int**)  malloc(sizeof(int*)*nbDomaine);

    for(i=0; i<nbDomaine; i++){
        v->valeurs[i] = (int*)  malloc(sizeof(int)*nbDomaine);
    }

    //Initialisation des valeurs du tableau à 0
    for(i=0; i<nbDomaine; i++){
        v->valeurs[i] = (int*)  malloc(sizeof(int)*nbDomaine);

        for(j=0; j<nbDomaine; j++){
            v->valeurs[i][j] = 0;
        }

    }

    //La boucle tourne tant que l'on peut ajouter une correspondance entre deux valeurs de deux variables
    while( s >= nbRempli ){

        for(i=0; i<nbDomaine; i++){

            for(j=0; j<nbDomaine; j++){
                //Génération d'un nombre aléatoire entre 0 et 1
                rnd = rand()%2;
                //Calcul du nombre de variable à 1 , plus celle qu'on veut ajouter, sur le nombre de correspondance totale
                nbRempli = (((float)nbCorrespondance+1.)/((float)nbDomaine*(float)nbDomaine));

                //On met la case à 1 si le nombre aléatoire vaut 1, si le fait de l'ajouter donne toujours un nbRempli inferieur ou egal à s
                //et si la case est déjà à 0
                if(rnd == 1 && s >= nbRempli && v->valeurs[i][j] == 0){
                    v->valeurs[i][j] = 1;
                    nbCorrespondance++;
                }

            }

        }

        //Calcul du nombre de variable à 1 , plus celle qu'on pourra potentiellement ajouter, sur le nombre de correspondance totale
        nbRempli = (((float)nbCorrespondance+1.)/((float)nbDomaine*(float)nbDomaine));
    }

    //On retourne le tableau crée
    return v;
}


//Fonction permettant de générer aléatoirement les arretes
void genereGraphe(int nbSommet,int nbArrete,int nbDomaine,float sat)
{
    /* Spécifications: fonction permettant de génerer en graphe aléatoire en fonction du nombre de sommets qu'il doit contenir,
    du nombre d'arrête qu'il doit y avoir entre tous les sommets, du nombre d'éléments dans un domaine,
	et sat qui contient un nombre entre 0 et 1 permettant de savoir le nombre de valeurs du domaines qui doivent etre liées
    */

    int i,j,k,l,cpt_arrete=0;
    srand(time(NULL));
    nb_sommet = nbSommet;
    taille_domaine=nbDomaine;

    //Initialisation du tableau
    tab.var = (var_domaine***) malloc(sizeof(var_domaine*)*nbSommet);
    for(i=0; i<nbSommet; i++)
    {
        //On génère le tableau à double dimension
        tab.var[i] = (var_domaine**) malloc(sizeof(var_domaine)*nbSommet);
        for(j=0; j<nbSommet; j++)
        {
            //Toutes les cases du tableau sont initialisées a NULL.
            tab.var[i][j] = NULL;
        }
    }
    while(cpt_arrete < nbArrete)
    {

        for(i=0; i<nbSommet; i++)
        {

            for(j=0; j<nbSommet; j++)
            {
                //On choisit les arretes de façon aléatoire
                if(cpt_arrete < nbArrete && rand()%2==1 && tab.var[i][j] == NULL && tab.var[j][i] == NULL && i!=j)
                {
                    cpt_arrete++;
                    printf("Arretes cree entre %d et %d. Nombre d'arretes : %d\n",i,j,cpt_arrete);
                    //Création d'un lien. On crée un var_domaine. Les cases concernées
                    //recevront l'adresse du var_domaine
                    tab.var[i][j] = tab.var[j][i] = genereDomaine(sat,nbDomaine,i,j);

                }

            }
        }

    }

    printf("Nombre d'arretes crees : %d\n",cpt_arrete);
}


