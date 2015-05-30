#include "heuristique.h"

int h_min_domaine(int** values){	
/* Spécifications: fonction permettant de choisir la variable avec le domaine le plus petit domaine dans un algorithme*/
	int i,j,min = 1000 ,compteur = 0,sommet = -1;

	for (i=0;i<nb_sommet;i++){

		if(var_affectee[i] == 0){
			compteur = 0;

			for (j=0;j<taille_domaine;j++){

				if (values[i][j])
					compteur++;

			}

			if(compteur < min){
				min = compteur;
				sommet = i;
			}

		}

	}
	//afficheFC(values);
	return sommet;

}


int h_first_fail(int **values){	
/* Spécifications: fonction permettant de choisir la variable avec le domaine le plus petit domaine dans un algorithme*/
	int i,j,nb_lien = 0,sommet = -1,nb_domaine = 0;
	float min = 1000. ;
	 
	for (i=0;i<nb_sommet;i++){

		if(var_affectee[i] == 0){
			nb_lien = 0;
			//calculer le nombre de lien avec les variables non affectées
			for (j=0;j<nb_sommet;j++){

				if (tab.var[i][j] && var_affectee[j] == 0)
					nb_lien++;

			}
			nb_domaine = 0;
			//calculer le nombre de valeurs qu'on peut affecter à une variable
			for (j=0;j<taille_domaine;j++){

				if (values[i][j])
					nb_domaine++;

			}
			if(nb_domaine == 0){
				min = 0;
				sommet = i;
			}else if(nb_lien == 0 && min == 1000.){
				sommet = i;
			}else if( min > ((float)nb_domaine/(float)nb_lien) ){
				min = ((float)nb_domaine/(float)nb_lien);
				sommet = i;
			}

		}

		

	}
	//afficheFC(values);
	return sommet;

}


void h_affiche_var_affectee(){
	int i ;
	printf("Affichage du tableau des affectations: \n");
	for(i=0;i<nb_sommet;i++){
		printf("%d",i);
	}
	printf("\n");
	for(i=0;i<nb_sommet;i++){
		printf("%d",var_affectee[i]);
	}
	printf("\n");
}