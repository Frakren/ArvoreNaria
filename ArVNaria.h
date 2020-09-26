#ifndef ARVNARIA_H_INCLUDED
#define ARVNARIA_H_INCLUDED
#define tam 5000
typedef struct NoArvNaria
{
  char info;
	int fimDaPalavra;
  struct NoArvNaria *filhoEsq;
  struct NoArvNaria *irmaoDir;
} TArvNaria;
TArvNaria* createNode(char item);
int EmptyNode(TArvNaria* a);
void InsertTree(TArvNaria** a, char *item,int length);
void Print(TArvNaria* a);
void DeleteItemOnTree(TArvNaria *a, char item[tam],int length);
int SearchTree(TArvNaria *a, char *item,int length);
void ShowAllTree(TArvNaria **a);
void removeBranchTree(TArvNaria **a,char item[tam]);
void removeNodeTree(TArvNaria** a, char *item,int length);
#endif
