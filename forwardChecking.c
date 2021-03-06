
/**
 *  \file 	forwardChecking.c
 *
 *	\brief 	Contient l'implementation des fonctions permettant d'exécuter l'algorithme du ForwardChecking
 *
 */

#include "forwardChecking.h"



int** initFC(){
	/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme du foward checking */
	int** values;
	int i=0,j=0,k=0,l=0,trouve=0,lien=0;

	affectation = (int*) malloc(sizeof(int)*nb_sommet);

    values = (int**) malloc(sizeof(int*)*nb_sommet);
	for(i=0;i<nb_sommet;i++)
		values[i] = (int*) malloc(sizeof(int)*taille_domaine);

    for (j=0; j<nb_sommet; j++){

        for (k=0; k<taille_domaine; k++){

            for (i=0; i<nb_sommet; i++){

                if (tab.var[j][i]!=NULL){
					lien = 1;
                    // printf("VAriable %d  \n",i);
                    if (tab.var[j][i]->var1==j){

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[j][i]->valeurs[k][l])
                                trouve=1;

                        }

                    }else{

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[j][i]->valeurs[l][k]){
                                trouve=1;
                            }

                        }

                    }

                }

            }

            if (lien == 1 && trouve==1){
				values[j][k] = 1;
                trouve = 0;
				lien = 0;
			}else if(lien == 0){
				values[j][k] = 1;
            }else{
				values[j][k] = 0;
			}

        }

    }
	return values;
}

int** initFC_heuristique(){
	/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme du foward checking */
	int** values;
	int i=0,j=0,k=0,l=0,trouve=0,lien=0;

	var_affectee = (int*) malloc(sizeof(int)*nb_sommet);
	for(i=0;i<nb_sommet;i++)
		var_affectee[i] = 0;

	affectation = (int*) malloc(sizeof(int)*nb_sommet);

    values = (int**) malloc(sizeof(int*)*nb_sommet);
	for(i=0;i<nb_sommet;i++)
		values[i] = (int*) malloc(sizeof(int)*taille_domaine);

    for (j=0; j<nb_sommet; j++){

        for (k=0; k<taille_domaine; k++){

            for (i=0; i<nb_sommet; i++){

                if (tab.var[j][i]!=NULL){
					lien = 1;
                    // printf("VAriable %d  \n",i);
                    if (tab.var[j][i]->var1==j){

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[j][i]->valeurs[k][l])
                                trouve=1;

                        }

                    }else{

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[j][i]->valeurs[l][k]){
                                trouve=1;
                            }

                        }

                    }

                }

            }

            if (lien == 1 && trouve==1){
				values[j][k] = 1;
                trouve = 0;
				lien = 0;
			}else if(lien == 0){
				values[j][k] = 1;
            }else{
				values[j][k] = 0;
			}

        }

    }
	return values;
}

void afficheFC(int** values){
	/* Spécifications: fonction permettant d'afficher les variables dans le tableau du foward checking*/
	int i,j;
	for(i=0;i<nb_sommet;i++){
		for(j=0;j<taille_domaine;j++){
			printf("%d ",values[i][j]);
		}
		printf("\n");
	}
}



int CF(int** values,int variable,int x){
	/* Spécifications: fonction qui va verifier que l'initialisation d'une variable à x n'empèche
	pas d'avoir des valeurs dans les autres variables*/
	int ok = 0, lien_var = 0, i = 0, j = 0;

	for(i = variable+1; i< nb_sommet; i++){
		
		if(tab.var[variable][i] != NULL){
			lien_var = 1;

			for(j = 0; j < taille_domaine; j++){

				if(tab.var[variable][i]->var1 == variable){

					if(tab.var[variable][i]->valeurs[x][j] == 1 && values[i][j] == 1)
						ok = 1;				

				}else{

					if(tab.var[variable][i]->valeurs[j][x] == 1 && values[i][j] == 1)
						ok = 1;

				}

			}


		}

		if(ok == 0 && lien_var == 1){
			return 0;
		}else{
			ok = 0;
			lien_var = 0;
		}
	}

	return 1;

}


void affectationFC(int** values,int variable, int x){
	/* Spécifications: fonction récursive qui va affecter une valeur x a une variable pendant le
	foward checking. */
	int i = 0, j = 0, trouve  = 0;
	for(i=0; i<taille_domaine; i++){

		if(x != i){
			values[variable][i] = 0;
		}

	}
	for(i = variable+1; i< nb_sommet; i++){

		if(tab.var[variable][i] != NULL){

			for(j = 0; j < taille_domaine; j++){

				if(tab.var[variable][i]->var1 == variable){

					if(tab.var[variable][i]->valeurs[x][j] == 0 && values[i][j] == 1)
						values[i][j] = 0;
	
				}else{

					if(tab.var[variable][i]->valeurs[j][x] == 0 && values[i][j] == 1)
						values[i][j] = 0;

				}

			}
			

		}

	}

}

int FC(int variable, int** values){
	/* Spécifications: fonction récursive qui va executer l'algorithme du foward checking sur avec
	les valeurs values sur une variable.*/
	int** copie = (int**) malloc(sizeof(int*)*nb_sommet);
	int i,j,k,ok=0;

	for(i=0;i<nb_sommet;i++)
		copie[i] = (int*) malloc(sizeof(int)*taille_domaine);


	for(i=0;i<nb_sommet;i++)
		for(j=0;j<taille_domaine;j++)
			copie[i][j] = values[i][j];

	for(i=0;i<taille_domaine;i++){

		if(values[variable][i] == 1){

			if( CF(values,variable,i) ){
				nbAffectation++;
				/*if(nbAffectation==1000){
					printf("Trop d'affectation\n");
					exit(EXIT_FAILURE);
				}*/
				affectation[variable] = i;
				affectationFC(values,variable,i);
				//printf("Affectation de la variable %d a la valeur %d\n",variable,i);
				//afficheFC(values);
				ok = 1;

				if(variable+1 < nb_sommet){
					ok  = FC(variable+1,values);
				}

				if(ok == 1){

					for(i=0;i<nb_sommet;i++)
						free(copie[i]);
						
					free(copie);
					return 1;
				}else{
					//printf("L'affectation de la variable %d a la valeur %d ne marche pas, backtrack\n",variable,affectation[variable]);
					affectation[variable] = NULL;

					for(k=0;k<nb_sommet;k++)
						for(j=0;j<taille_domaine;j++)
							values[k][j] = copie[k][j];
					
						//afficheFC(values);
				}

			}else{
				//printf("Impossible d'affecter la variable %d a la valeur %d\n",variable,i);
			}

		}

	}
	//printf("L'affectation de la variable %d a la valeur %d ne marche pas, backtrack\n",variable,affectation[variable]);
	affectation[variable] = NULL;

	for(i=0;i<nb_sommet;i++)
			for(j=0;j<taille_domaine;j++)
				values[i][j] = copie[i][j];
	//afficheFC(values);
	for(i=0;i<nb_sommet;i++)
			free(copie[i]);
			
	free(copie);
	return 0;
}



int CF_heuristique(int** values,int variable,int x){
	/* Spécifications: fonction qui va verifier que l'initialisation d'une variable à x n'empèche
	pas d'avoir des valeurs dans les autres variables*/
	int ok = 0, lien_var = 0, i = 0, j = 0;

	for(i = 0; i< nb_sommet; i++){
		
		if(var_affectee[i] == 0 && variable != i){

			if(tab.var[variable][i] != NULL){
				lien_var = 1;

				for(j = 0; j < taille_domaine; j++){

					if(tab.var[variable][i]->var1 == variable){

						if(tab.var[variable][i]->valeurs[x][j] == 1 && values[i][j] == 1)
							ok = 1;				

					}else{

						if(tab.var[variable][i]->valeurs[j][x] == 1 && values[i][j] == 1)
							ok = 1;

					}

				}


			}

			if(ok == 0 && lien_var == 1){
				return 0;
			}else{
				ok = 0;
				lien_var = 0;
			}

		}

	}

	return 1;

}

void affectationFC_heuristique(int** values,int variable, int x){
	/* Spécifications: fonction récursive qui va affecter une valeur x a une variable pendant le
	foward checking. */
	int i = 0, j = 0, trouve  = 0;
	for(i=0; i<taille_domaine; i++){

		if(x != i){
			values[variable][i] = 0;
		}

	}

	var_affectee[variable] = 1;

	for(i = 0; i< nb_sommet; i++){

		if(var_affectee[i] == 0 && i != variable){

			if(tab.var[variable][i] != NULL){

				for(j = 0; j < taille_domaine; j++){

					if(tab.var[variable][i]->var1 == variable){

						if(tab.var[variable][i]->valeurs[x][j] == 0 && values[i][j] == 1)
							values[i][j] = 0;
	
					}else{

						if(tab.var[variable][i]->valeurs[j][x] == 0 && values[i][j] == 1)
							values[i][j] = 0;

					}

				}
			

			}

		}

	}

}

int FC_heuristique(int variable, int** values,int choixHeuristique){
	/* Spécifications: fonction récursive qui va executer l'algorithme du foward checking sur avec
	les valeurs values sur une variable.*/
	int** copie = (int**) malloc(sizeof(int*)*nb_sommet);
	int i,j,k,nextVar,ok=0;

	for(i=0;i<nb_sommet;i++)
		copie[i] = (int*) malloc(sizeof(int)*taille_domaine);


	for(i=0;i<nb_sommet;i++)
		for(j=0;j<taille_domaine;j++)
			copie[i][j] = values[i][j];

	for(i=0;i<taille_domaine;i++){

		if(values[variable][i] == 1){

			if( CF_heuristique(values,variable,i) ){
				nbAffectationHeuristique ++;
				affectation[variable] = i;
				affectationFC_heuristique(values,variable,i);
				//h_affiche_var_affectee();
				//printf("Affectation de la variable %d a la valeur %d\n",variable,i);
				//afficheFC(values);
				ok = 1;

				switch (choixHeuristique){
					case 1:
					nextVar =  h_min_domaine(values);
					break;
					case 2:
					nextVar =  h_first_fail(values);
					//printf("prochaine valeur %d\n",nextVar);
					break;
				}

				if(nextVar != -1){
					ok  = FC_heuristique(nextVar,values,choixHeuristique);
				}

				if(ok == 1){

					for(i=0;i<nb_sommet;i++)
						free(copie[i]);
						
					free(copie);
					return 1;
				}else{
					//printf("L'affectation de la variable %d a la valeur %d ne marche pas, backtrack Heuristique\n",variable,affectation[variable]);
					affectation[variable] = NULL;

					for(k=0;k<nb_sommet;k++)
						for(j=0;j<taille_domaine;j++)
							values[k][j] = copie[k][j];
					
						//afficheFC(values);
				}

			}else{
				//printf("Impossible d'affecter la variable %d a la valeur %d\n",variable,i);
			}

		}

	}
	//printf("L'affectation de la variable %d a la valeur %d ne marche pas, backtrack\n",variable,affectation[variable]);
	affectation[variable] = NULL;

	for(i=0;i<nb_sommet;i++)
			for(j=0;j<taille_domaine;j++)
				values[i][j] = copie[i][j];
	//afficheFC(values);
	for(i=0;i<nb_sommet;i++)
			free(copie[i]);
			
	free(copie);
	var_affectee[variable] = 0;
	return 0;
}

void testFC(){
	/* Spécifications: fonction qui permet de tester l'algorithme du foward checking*/
	int i,nextVar=0,choixHeuristique = 1;
	int ** values = initFC();
	nbAffectation = 0;

	nbAffectationHeuristique = 0;
	//printf("Tableau de depart du FC\n");
	//afficheFC(values);

	if ( FC(0, values ) ){
		printf("Il y a une solution\nTableau final du FC\nValeurs des affectations: \n");
		/*for(i=0;i<nb_sommet;i++){
			printf("Variable %d : %d \n",i,affectation[i]);
		}*/
		//afficheFC(values);
	}else{
		printf("Pas de solution\n");
		//afficheFC(values);
	}
	printf("Nombre d'affectations FC sans heuristique :%d\n",nbAffectation);
	
	free(affectation);
	values = initFC_heuristique();
	nextVar =  h_min_domaine(values);
	if ( FC_heuristique(nextVar, values,1) ){
		printf("Il y a une solution\nTableau final du FC avec heuristique\nValeurs des affectations: \n");
		/*for(i=0;i<nb_sommet;i++){
			printf("Variable %d : %d \n",i,affectation[i]);
		}*/
		//afficheFC(values);
	}else{
		printf("Pas de solution\n");
		//afficheFC(values);
	}
	printf("Nombre d'affectations min domaine :%d\n",nbAffectationHeuristique);
	nbAffectationHeuristique = 0;
	free(affectation);
	free(var_affectee);
	values = initFC_heuristique();
	nextVar =  h_first_fail(values);
	if ( FC_heuristique(nextVar, values,2) ){
		printf("Il y a une solution\nTableau final du FC avec heuristique\nValeurs des affectations: \n");
		/*for(i=0;i<nb_sommet;i++){
			printf("Variable %d : %d \n",i,affectation[i]);
		}*/
		//afficheFC(values);
	}else{
		printf("Pas de solution\n");
		//afficheFC(values);
	}
	printf("Nombre d'affectations first fail  :%d\n",nbAffectationHeuristique);
}

