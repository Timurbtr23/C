#include <stdio.h>
#include <stdlib.h>

int Vstup(char ** Pole, char ** Original, int * i)
{
	int j, velikost=10;
	* Pole=(char*)malloc(velikost*sizeof(char)); //ukazatel na char lze take : char * Pole; Pole=(char*)malloc(10*sizeof(char));
	printf("Zadej radu zavorek:\n");
	while ((*Pole)[(*i)-1]!='\n') 
	{
		scanf("%c", &(*Pole)[(*i)++]);
		if (((*Pole)[(*i)-1]!='(') && ((*Pole)[(*i)-1]!=')') && ((*Pole)[(*i)-1]!='\n'))
		{
			printf("Chyba zadani!");
			return 1;
		}
		if ((*i)==velikost) 
		{
			velikost*=2;
			* Pole = realloc(*Pole, velikost*sizeof(char));
		}
	} 
	* Original=(char*)malloc(((*i)-1)*sizeof(char));
	for(j = 0; j < (*i)-1; j++) (* Original)[j]= (*Pole)[j];
	return 0;
}

void Hledej(char ** Pole, int * i)
{
	int j, nasel=1, indexleva=-1;
	while (nasel==1)
	{
		indexleva=-1;
		nasel=0;
		for (j = 0; j < (*i)-1; j++)
		{
			if ((*Pole)[j]=='(') indexleva=j;
			if (((*Pole)[j]==')') && (indexleva>-1))
			{
				(*Pole)[indexleva]='*';
				(*Pole)[j]='*';
				nasel=1;
				break;
			}
		}
	}
}

void Vystup(char * Pole, char * Original, int * i)
{
	int j, k, max=0, pocet=0;
	for(j = 0; j < * i-1; j++) if (Pole[j]=='*') pocet++; else {if (pocet>max) max=pocet;pocet=0;}
	if (pocet>max) max=pocet;
	pocet=0;

	printf("Reseni:\n");
	if (max>0)
	{
		for(j=0;j<(*i)-1;j++)
		{
			if (Pole[j]=='*') pocet++; else pocet=0;
			if (pocet==max) {for(k=j-max+1;k<=j;k++) Pole[k]=' '; pocet=0;}
		}
		for(j=0;j<(*i)-1;j++) if (Pole[j]==' ') printf("%c",Original[j]); else printf("*");
		printf(" - %d\n",max);
	}
	else printf("neexistuje!\n");
}

int main (void)
{
	int i=0;
	char * Pole, * Original;
	if (Vstup(&Pole, &Original,&i)) return 1;
	Hledej(&Pole,&i);
	Vystup(Pole, Original, &i);
	free(Pole);
	free(Original);
	return 0;
}

