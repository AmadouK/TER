#include "structure.h"
#include "utile.h"
#include "forwardChecking.h"
#include "ac8.h"
#include "generateur_graphe.h"
#include "rfl.h"

int main(void)
{
    //initVarAuto();
    //printf("Debut : \n");
    genereGraphe(5,5,3,0.8);
    afficheTab();
	//system("pause");
	//AC8();
	//system("pause");
	//system("cls");
	//afficherdom();
	/*system("cls");*/
	testFC();
	testRFL();
    EXIT_SUCCESS;
}
