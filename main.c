#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcao.c"

int main(void) {
	TArvNaria* teste=createNode('\0');
	FILE *arq;
	arq=fopen("arquivo.txt", "r");
	char aux[tam];
	char testa[tam]="cleber";
	char testa1[tam]="clebson";
	while((fscanf(arq,"%s",aux))!=EOF)
	{
		InsertTree(&teste->filhoEsq, aux,strlen(aux));
	}
	ShowAllTree(&teste);
	removeBranchTree(&teste,testa);
    ShowAllTree(&teste);
    printf("\n");
	InsertTree(&teste->filhoEsq,testa,strlen(testa));
    ShowAllTree(&teste);
	return 1;
}
