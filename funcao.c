#include "ArVNaria.h"
#include <stdio.h>
#include <stdio.h>
void Print(TArvNaria* a)
{
	if(EmptyNode(a))
	{
		printf("vazia\n");
	}
	else
	{
		printf("%c ",a->info);
	}
}
int EmptyNode(TArvNaria* a)
{
	return a==NULL;
}
TArvNaria* createNode(char item)
{
	TArvNaria* a;
	a=(TArvNaria*)malloc(sizeof(TArvNaria));
	a->filhoEsq=NULL;
	a->irmaoDir=NULL;
	a->info=item;
	return a;
}
int SearchTree(TArvNaria *a, char *item,int length)
{
	int compare=0;
	TArvNaria* aux=a->filhoEsq;
	while(!EmptyNode(aux))
	{
		if(aux->info==item[compare])
		{
			compare++;
			if(!EmptyNode(aux->filhoEsq))
			{
				aux=aux->filhoEsq;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(!EmptyNode(aux->irmaoDir))
			{
				aux=aux->irmaoDir;
			}
			else
			{
				break;
			}
		}
	}
	if(aux->fimDaPalavra && compare==length)
	{
		printf("\n%s\n",item);
		return 1;
	}
	else
	{
		printf("\nPalavra nao encontrada\n");
		return 0;
	}
}
char returnItem(TArvNaria* a)
{
	return a->info;
}
void ShowAllTree(TArvNaria **a)
{
	if(!EmptyNode(*a))
	{
		Print(*a);
		ShowAllTree(&(*a)->filhoEsq);
		ShowAllTree(&(*a)->irmaoDir);
	}
}
void InsertTree(TArvNaria** a, char *item,int length)
{
	if(length>0)
	{
		if(EmptyNode(*a))
		{
			*a=createNode(*item);
			if(length-1==0)
			{
				(*a)->fimDaPalavra=1;
			}
			InsertTree(&(*a)->filhoEsq, ++item, --length);
		}
		else
		{
			if(returnItem(*a)==*item)
			{
				InsertTree(&(*a)->filhoEsq, ++item, --length);
			}
			else
			{
				if(EmptyNode((*a)->irmaoDir))
				{
					if(returnItem(*a)<*item)
					{
						(*a)->irmaoDir=createNode(*item);
						InsertTree(&(*a)->irmaoDir->filhoEsq, ++item, --length);
					}
					else
					{
						TArvNaria *b=createNode(*item);
						TArvNaria *aux=*a;
						b->irmaoDir=*a;
						*a=b;
						InsertTree(&(*a)->filhoEsq, ++item, --length);
					}
				}
				else
				{
					if(returnItem(*a)<*item)
					{
						InsertTree(&(*a)->irmaoDir, item, length);
					}
					else
					{
						TArvNaria *b=createNode(*item);
						TArvNaria *aux=*a;
						b->irmaoDir=*a;
						*a=b;
						InsertTree(&(*a)->filhoEsq, ++item, --length);
					}
				}
			}
		}
	}
}
void removeBranchTree(TArvNaria **a,char item[tam])
{
    if(SearchTree(*a,item,strlen(item)))
    {
        printf("esta sendo removido\n");
        removeNodeTree(&(*a),item,strlen(item));
    }
    else
    {
        printf("Operacao Invalida invalida\n");
    }
}
void removeNodeTree(TArvNaria** a, char *item,int length)
{
    int compare=0;
	TArvNaria* aux=(*a)->filhoEsq;
	while(!EmptyNode(aux))
	{
		if(aux->info==item[compare])
		{
			compare++;
			if(EmptyNode(aux->filhoEsq) && EmptyNode(aux->irmaoDir) && aux->fimDaPalavra==1)
            {
                free(aux);
            }
            else if((!EmptyNode(aux->filhoEsq) || !EmptyNode(aux->irmaoDir)) && aux->fimDaPalavra==1)
            {
                aux->fimDaPalavra=0;
            }
            else
            {
                aux=aux->filhoEsq;
            }
		}
		else
		{
			if(EmptyNode(aux->filhoEsq) && EmptyNode(aux->irmaoDir) && aux->fimDaPalavra==1)
            {
                free(aux);
            }
            else if((!EmptyNode(aux->filhoEsq) || !EmptyNode(aux->irmaoDir)) && aux->fimDaPalavra==1)
            {
                aux->fimDaPalavra=0;
            }
            else
            {
                aux=aux->irmaoDir;
            }
		}
	}
	if(compare==length)
    {
        printf("palavra removida\n");
    }
}
