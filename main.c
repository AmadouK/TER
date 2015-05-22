#include "structure.h"
#include "utile.h"
#include "forwardChecking.h"
#include "ac8.h"
#include "generateur_graphe.h"

int main(void)
{
    //initVarAuto();
    //printf("Debut : \n");
    genereGraphe(4,4,3,1.);
    afficheTab();
	//system("pause");
	//AC8();
	//system("pause");
	//system("cls");
	//afficherdom();
	/*system("cls");*/
	testFC();

    EXIT_SUCCESS;
}
