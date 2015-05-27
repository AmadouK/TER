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
    genereGraphe(4,4,4,0.6);
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
