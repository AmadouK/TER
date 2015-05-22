
#include "ac8.h"

int whitoutap(int x, int y, int valeur){
	/* Spécifications: fonction permettant d'eliminer valeur du domaine de y s'il n a pas de lien dans le domaine de x*/
   int placex,k;

   if (tab.var[x][y]->var1==x)
        placex=0;
   else
		placex=1;
  
    for (k=0;k<taille_domaine;k++){

        if (placex==0){

            if (tab.var[x][y]->valeurs[k][valeur])
                return 1;
            
        }else{

            if (tab.var[x][y]->valeurs[valeur][k])
                return 1;
            
        }

    }

    return 0;
}


void ajouter_liste(int x){
	/* Spécifications: fonction pour ajouter une variable x dans la liste d'attente*/
    int i=0;

    if (statut[x]==0){
        // on va trouver le premier index libre dans la liste
        while(liste[i]!=NULL)
			i++;

         liste[i]=x;
         statut[x]=1;
    }

}

void diminuer_domaine(int x,int valeur){
	/* Spécifications: fonction permettant d'enlever valeur du domaine de la variable x*/
	int i,k;

    for(i=0;i<nb_sommet;i++){

        if(tab.var[x][i]!=NULL){

            if(tab.var[x][i]->var1==x){
                
				for(k=0;k<taille_domaine;k++){
                    tab.var[x][i]->valeurs[valeur][k]=0;
                }

            }else{

                for (k=0;k<taille_domaine;k++){
                    tab.var[x][i]->valeurs[k][valeur]=0;
                }

            }

        }

    }

}

int sortir_liste(){
int i=0;

    while(liste[i]==NULL && i<nb_sommet)
        i++;

    return i;
}

void propagation(int x){
	/* Spécifications: fonction permettant d'enleve une valeur du domaine d'une variable en lien 
	avec x si elle n a pas de lien dans le domaine de x */
    int i,k;

    for (i=0;i<nb_sommet;i++){
        if(tab.var[i][x] != NULL){
            for (k=0;k<taille_domaine;k++){

                if (whitoutap(x,i,k)==0){

                    diminuer_domaine(i,k);
                    ajouter_liste(i);
                }

            }

        }

    }
}
 
void initialisation(){
	/* Spécifications: fonction permettant l'intialisation du statut et fait la première propagation */
    int i;
     statut = (int*) malloc(sizeof(int)*nb_sommet);
     liste = (int*) malloc(sizeof(int)*nb_sommet);

    for(i=0;i<nb_sommet;i++){
        liste[i]=NULL;
        statut[i]=0;
    }

    for (i=0;i<nb_sommet;i++){
        propagation(i);
    }

}

void AC8(){
	/* Spécifications: fonction permettant l'exécution de l'algorithme AC8 */
    int i,element;
    initialisation();
    i=sortir_liste();

	while(i<nb_sommet){
        element =liste[i];
        liste[i]=NULL;
        propagation(element);
		printf("element %d enleve de la liste \n",element);
		afficherdom();
		system("pause");
		system("cls");
		 i=sortir_liste();
	}
	printf("Fin de la boucle, nous sommes au %d eme\n",i);
}