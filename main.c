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
    genereGraphe(100,10,5,0.9);
    afficheTab();
	//system("pause");
	//AC8();
	//system("pause");
	//system("cls");
	//afficherdom();
	/*system("cls");*/
	//testFC();
	testRFL();
    EXIT_SUCCESS;
}
