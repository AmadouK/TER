
#include "utile.h"
//Fonction permettant de tester les structures
void initVarAuto(){
	/* Spécifications: fonction permettant de génerer un graphe. Permet de tester la structure */
    int i,j;

	nb_sommet = 4;
	taille_domaine = 3;
    //Initialisation du tableau
    tab.var = (var_domaine***) malloc(sizeof(var_domaine*)*4);

    for(i=0; i<4; i++){
        //On génère le tableau à double dimension
        tab.var[i] = (var_domaine**) malloc(sizeof(var_domaine)*4);

        for(j=0; j<4; j++){
            //Toutes les cases du tableau sont initialisées a NULL.
            tab.var[i][j] = NULL;
        }

    }

    //Création d'un lien. On crée un var_domaine. Les cases concernées
    //recevront l'adresse du var_domaine
    tab.var[0][1] = tab.var[1][0] = (var_domaine*) malloc(sizeof(var_domaine));
	tab.var[1][2] = tab.var[2][1] = (var_domaine*) malloc(sizeof(var_domaine));
	tab.var[2][3] = tab.var[3][2] = (var_domaine*) malloc(sizeof(var_domaine));
	tab.var[3][0] = tab.var[0][3] = (var_domaine*) malloc(sizeof(var_domaine));
    //Pour éviter une confusion avec les variables,
    //on garde l'ordre dans la structure
    tab.var[0][1]->var1 = 0;
    tab.var[0][1]->var2 = 1;
    tab.var[0][1]->valeurs=(int**)  malloc(sizeof(int*)*3);

	tab.var[1][2]->var1 = 1;
    tab.var[1][2]->var2 = 2;
    tab.var[1][2]->valeurs=(int**)  malloc(sizeof(int*)*3);

	tab.var[2][3]->var1 = 2;
    tab.var[2][3]->var2 = 3;
    tab.var[2][3]->valeurs=(int**)  malloc(sizeof(int*)*3);

	tab.var[3][0]->var1 = 3;
    tab.var[3][0]->var2 = 0;
    tab.var[3][0]->valeurs=(int**)  malloc(sizeof(int*)*3);

    for(i=0; i<3; i++){
        tab.var[0][1]->valeurs[i]=(int*)  malloc(sizeof(int)*3);
		tab.var[1][2]->valeurs[i]=(int*)  malloc(sizeof(int)*3);
		tab.var[2][3]->valeurs[i]=(int*)  malloc(sizeof(int)*3);
		tab.var[3][0]->valeurs[i]=(int*)  malloc(sizeof(int)*3);
	}
    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            if(i==j){
                tab.var[0][1]->valeurs[i][j] = 0;
				tab.var[1][2]->valeurs[i][j] = 0;
				tab.var[2][3]->valeurs[i][j] = 0;
				tab.var[3][0]->valeurs[i][j] = 0;
			}else{
                tab.var[1][0]->valeurs[i][j] = 1;
				tab.var[1][2]->valeurs[i][j] = 1;
				tab.var[2][3]->valeurs[i][j] = 1;
				tab.var[3][0]->valeurs[i][j] = 1;
			}
        }

    }

}


void afficheTab(){
	/* Spécifications: fonction permettant d'afficher l'état des structures*/
    int i,j,k,l;

    for(i=0; i<nb_sommet; i++){

        for(j=0; j<nb_sommet; j++){

             if(tab.var[i][j] != NULL){
                printf("Lien entre la variable %d et la variable %d\n Variable A: %d, Variable B: %d\n\nAffichage du tableau\n\n"
                       ,i,j,tab.var[i][j]->var1,tab.var[i][j]->var2);

                for(k=0; k<taille_domaine; k++){

                    for(l=0; l<taille_domaine; l++){
                        printf ("%d ",tab.var[i][j]->valeurs[k][l]);
                    }

                    printf("\n");
                }

            }

        }

    }

}


void afficherdom()
{
	/* Spécifications: fonction permettant d'afficher les domaines actifs*/
	int i=0,j=0,k=0,l=0;
    int trouve=0;
    printf("Liste liens actifs:\n");

    for (j=0; j<nb_sommet; j++){
        printf("\n V %d\n",j);

        for (k=0; k<taille_domaine; k++){
            printf("\n test ");

            for (i=0; i<nb_sommet; i++){

                if (tab.var[j][i]!=NULL){

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

            if (trouve==1){
                printf("%d ",k);
                trouve=0;
            }

        }

    }

}

