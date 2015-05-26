#include "rfl.h"

void initRFL(){
	/* Spécifications: fonction permettant d'initialiser les variables permettant d'exécuter l'algorithme RFL */
	affectation = (int*) malloc(sizeof(int)*nb_sommet);
	AC8();
}

void afficheRFL(int** values){
	/* Spécifications: fonction permettant d'afficher les variables dans le tableau du RFL*/
	int i,j;
	for(i=0;i<nb_sommet;i++){
		for(j=0;j<taille_domaine;j++){
			printf("%d ",values[i][j]);
		}
		printf("\n");
	}
}

tab_variable createCopie(){
	/* Spécifications: fonction permettant de créer une copie de la structure en cas de Backtrack */
	tab_variable copie;
	int i,j,k,l,m,n;

	copie.var = (var_domaine***) malloc(sizeof(var_domaine*)*nb_sommet);
    for(i=0; i<nb_sommet; i++)
    {
        //On génère le tableau à double dimension
        copie.var[i] = (var_domaine**) malloc(sizeof(var_domaine)*nb_sommet);
        for(j=0; j<nb_sommet; j++)
        {
            //Toutes les cases du tableau sont initialisées a NULL.
            copie.var[i][j] = NULL;
        }
    }

	for(i=0; i<nb_sommet; i++)
	{
		for(j=i+1; j<nb_sommet; j++)
		{
			if(tab.var[i][j] != NULL)
			{
				copie.var[i][j] = copie.var[j][i] = (var_domaine*) malloc(sizeof(var_domaine));
				copie.var[i][j]->valeurs=(int**)  malloc(sizeof(int*)*taille_domaine);
				
				for(m=0; m<taille_domaine; m++){
					copie.var[i][j]->valeurs[m] = (int*)  malloc(sizeof(int)*taille_domaine);
				}

				copie.var[j][i]->var1 = copie.var[i][j]->var1 = tab.var[i][j]->var1;
				copie.var[j][i]->var1 = copie.var[i][j]->var2 = tab.var[i][j]->var2;

				for(k=0; k<taille_domaine; k++)
				{
					for(l=0; l<taille_domaine; l++)
					{
						copie.var[j][i]->valeurs[k][l] = copie.var[i][j]->valeurs[k][l] = tab.var[i][j]->valeurs[k][l];
					}
				}
			}
		}
	}
	return copie;
}

int **getDomaine(){
	/* Spécifications: fonction permettant de récupérer le domaine de chaque variable */
	int** values;
	int i=0,j=0,k=0,l=0,trouve=0,lien=0,ok = 1;
    values = (int**) malloc(sizeof(int*)*nb_sommet);

	for(i=0;i<nb_sommet;i++)
		values[i] = (int*) malloc(sizeof(int)*taille_domaine);

    for (i=0; i<nb_sommet; i++){
		
        for (k=0; k<taille_domaine; k++){
			ok = 1;
            for (j=0; j<nb_sommet; j++){
				trouve = 0;
				lien = 0;
                if (tab.var[i][j] != NULL){
					lien = 1;
                    
                    if (tab.var[i][j]->var1 == i){

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[i][j]->valeurs[k][l])
                                trouve=1;

                        }

                    }else{

                        for (l=0; l<taille_domaine; l++){

                            if(tab.var[i][j]->valeurs[l][k]){
                                trouve=1;
                            }

                        }

                    }

                }

				if (lien == 1 && trouve==0){
					ok = 0;
				}
            }
			if(ok == 1)
				values[i][k] = 1;
			else
				values[i][k] = 0;
			
        }

    }
	return values;
}

void backtrack_RFL(tab_variable copie){
	/*Spécifications : Fonction permettant de remettre l'état de la structure en cas de backtrack*/
	int i,j,k,l,m;

	for(i=0; i<nb_sommet; i++)
	{
		for(j=i+1; j<nb_sommet; j++)
		{
			if(copie.var[i][j] != NULL)
			{
				tab.var[j][i]->var1 = tab.var[i][j]->var1 = copie.var[i][j]->var1;
				tab.var[j][i]->var1 = tab.var[i][j]->var2 = copie.var[i][j]->var2;

				for(k=0; k<taille_domaine; k++)
				{
					for(l=0; l<taille_domaine; l++)
					{
						tab.var[j][i]->valeurs[k][l] = tab.var[i][j]->valeurs[k][l] = copie.var[i][j]->valeurs[k][l];
					}
				}
			}
		}
	}
}

 void affectationRFL(int variable, int x){
	 /*Spécifications : Fonction permettant de modifier la structure pour simuler l'affectation de la variable à x*/
	int i,j,k;

	for(i=0;i<nb_sommet;i++)
	{
		if(tab.var[variable][i] != NULL)
		{
			if(tab.var[variable][i]->var1 ==  variable)
			{
				for(j=0;j<taille_domaine;j++)
				{
					if(j != x)
						for(k=0;k<taille_domaine;k++)
						{
							tab.var[i][variable]->valeurs[j][k] = tab.var[variable][i]->valeurs[j][k] = 0;
						}
				}
			}
			else
			{
				for(j=0;j<taille_domaine;j++)
				{
					if(j != x)
						for(k=0;k<taille_domaine;k++)
						{
							tab.var[i][variable]->valeurs[k][j] = tab.var[variable][i]->valeurs[k][j] = 0;
						}
				}
			}

		}
	}

	
}
int RFL(int variable){
	/*Spécifications : Fonction permettant d'executer l'algorithme du RFL sur une variable*/
	int i,j,ok;
	int** values = getDomaine();
	tab_variable copie = createCopie();

	afficheRFL(values);
	for(i=0; i<taille_domaine; i++)
	{
		if(values[variable][i] == 1)
		{
			affectationRFL(variable,i);
			affectation[variable] = i;
			printf("Affectation de la variable %d a la valeur %d\n",variable,affectation[variable]);
			AC8();
			ok = 1;
			if(variable+1 < nb_sommet){
				ok = RFL(variable+1);
			}
			if(ok){
				return 1;
			}else{
				printf("L'affectation de la variable %d a la valeur %d ne marche pas, backtrack\n",variable,affectation[variable]);
				affectation[variable] = NULL;
				backtrack_RFL(copie);
				//values = getDomaine();
				afficheRFL(values);
			}
		}
	}

	affectation[variable] = NULL;
	backtrack_RFL(copie);
	return 0;
}

void testRFL(){
	/*Spécifications : Fonction permettant de démarrer l'algoriithme RFL sur tout la structure*/
	int i;
	initRFL();
	printf("\nDepart du RFL\n\n");
	//afficheRFL(getDomaine());
	if ( RFL(0) ){
		printf("Il y a une solution\nTableau final du RFL\nValeurs des affectations: \n");
		for(i=0;i<nb_sommet;i++){
			printf("Variable %d : %d \n",i,affectation[i]);
		}
		afficheRFL(getDomaine());
	}else{
		printf("Pas de solution\n");
		afficheRFL(getDomaine());
	}
}