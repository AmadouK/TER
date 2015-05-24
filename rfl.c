#include "rfl.h"

void initRFL(){
	/* Sp�cifications: fonction permettant d'initialiser les variables permettant d'ex�cuter l'algorithme RFL */
	affectation = (int*) malloc(sizeof(int)*nb_sommet);
	AC8();
}

void afficheRFL(int** values){
	/* Sp�cifications: fonction permettant d'afficher les variables dans le tableau du RFL*/
	int i,j;
	for(i=0;i<nb_sommet;i++){
		for(j=0;j<taille_domaine;j++){
			printf("%d ",values[i][j]);
		}
		printf("\n");
	}
}

tab_variable createCopie(){
	/* Sp�cifications: fonction permettant de cr�er une copie de la structure en cas de Backtrack */
	tab_variable copie;
	int i,j,k,l,m,n;

	copie.var = (var_domaine***) malloc(sizeof(var_domaine*)*nb_sommet);
    for(i=0; i<nb_sommet; i++)
    {
        //On g�n�re le tableau � double dimension
        copie.var[i] = (var_domaine**) malloc(sizeof(var_domaine)*nb_sommet);
        for(j=0; j<nb_sommet; j++)
        {
            //Toutes les cases du tableau sont initialis�es a NULL.
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
	/* Sp�cifications: fonction permettant de r�cup�rer le domaine de chaque variable */
	int** values;
	int i=0,j=0,k=0,l=0,trouve=0,lien=0;

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

void backtrack_RFL(tab_variable copie){
	/*Sp�cifications : Fonction permettant de remettre l'�tat de la structure en cas de backtrack*/
	int i,j,k,l;

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
									tab.var[variable][i]->valeurs[j][k] = 0;
								}
						}
					}
					else if(tab.var[variable][i]->var2 ==  variable)
					{
						for(j=0;j<taille_domaine;j++)
						{
							if(j != x)
								for(k=0;k<taille_domaine;k++)
								{
									tab.var[variable][i]->valeurs[k][j] = 0;
								}
						}
					}

		}
	}
}
int RFL(int variable){
	int i,j,ok;
	int** values = getDomaine();
	tab_variable copie = createCopie();

	for(i=0; i<taille_domaine; i++)
	{
		if(values[variable][i] == 1)
		{
			affectationRFL(variable,i);
			affectation[variable] = i ;
			AC8();
			ok = 1;
			if(variable+1 < nb_sommet){
				ok = RFL(variable+1);
			}
			if(ok){
				return 1;
			}else{
				affectation[variable] = NULL;
				backtrack_RFL(copie);
			}
		}
	}

	affectation[variable] = NULL;
	backtrack_RFL(copie);

	return 0;
}

void testRFL(){
	int i;
	initRFL();
	printf("\nTableau de depart du RFL\n");
	afficheRFL(getDomaine());
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