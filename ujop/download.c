#include <stdio.h>
#include <stdlib.h>

typedef struct PRVEK
{
	int Hodnota;
	struct PRVEK * Dalsi;
} Prvek; 

typedef struct SEZNAM
{
	Prvek* Prvni;
	Prvek* Posledni;
} Seznam; 

int NactiHodnotu(int *Cislo)
{	
	printf("Zadej cislo: ");
	return scanf("%d",Cislo)==1; //vlozi se do adresy v promenne Cislo (ukazatel), jestli je pocet uspesnych operaci rovno 1, pak vráti true, jinak false
}

void Pis (Prvek* X)
{
	if (!X) return; //Když není prvek, vyjdi z procedury
	printf("%d, ",X->Hodnota);	// ekvivalent X->Hodnota) je (*X).Hodnota
	Pis (X->Dalsi);
}

void VypisSeznam(Seznam SpojovySeznam) //promenna SpojovySeznam a je tzpu Seznam
{
	Pis(SpojovySeznam.Prvni);
	printf("\n");
}

void Uvolnuj(Prvek* PrvekUvolnit)
{
	if(!PrvekUvolnit) return;
	Uvolnuj(PrvekUvolnit->Dalsi);
	free (PrvekUvolnit);
}

void UvolniSeznam(Seznam SpojovySeznamUvolnit)
{
	Uvolnuj(SpojovySeznamUvolnit.Prvni);
}

int  Hledej(Prvek* AktualniPrvek, int HledaneCislo)			// rekurze - do první instance pošleme první prvek (adresu)
{
	if(!AktualniPrvek) return 0;
	if(AktualniPrvek->Hodnota==HledaneCislo) return 1;
	return Hledej(AktualniPrvek->Dalsi, HledaneCislo);
} 

int  Hledej1(Prvek * AktualniPrvek, int HledaneCislo)			// cyklus - do první instance pošleme první prvek (adresu)
{
	for( ;AktualniPrvek;AktualniPrvek=AktualniPrvek->Dalsi) if (AktualniPrvek->Hodnota==HledaneCislo) return 1;
	return 0;
} 

int HledejCislo(Seznam SeznamPrvku,int X)
{
	//return Hledej(SeznamPrvku.Prvni, X);
	return Hledej1(SeznamPrvku.Prvni, X);
}

void PridejDoSeznamu(Seznam* NaseCisla, int NoveCislo)
{
	if(!NaseCisla->Prvni)
	{
		NaseCisla->Prvni=(Prvek*)malloc(sizeof(Prvek));
		NaseCisla->Prvni->Hodnota=NoveCislo;
		NaseCisla->Prvni->Dalsi=NULL;		
		NaseCisla->Posledni=NaseCisla->Prvni;
	}
	else
	{
		NaseCisla->Posledni->Dalsi=(Prvek*)malloc(sizeof(Prvek));
		NaseCisla->Posledni->Dalsi->Hodnota=NoveCislo;
		NaseCisla->Posledni->Dalsi->Dalsi=NULL;		
		NaseCisla->Posledni=NaseCisla->Posledni->Dalsi;
	}
}

int main (void)
{
	int C;
	Seznam Cisla;
	Cisla.Prvni=NULL;
	Cisla.Posledni=NULL;
	while (NactiHodnotu(&C)) PridejDoSeznamu(&Cisla,C);
	fflush(stdin); //vyprázdní standardní vstup
	printf("Vypis zadanych cisel\n");
	VypisSeznam(Cisla);
	while (1)
	{
		printf("Zadej hledane cislo: ");
		if (scanf("%d",&C)==1) break;
		printf("Nespravny vstup!\n");
		fflush(stdin);
	}
	if (HledejCislo(Cisla,C)) printf("Seznam obsahuje hledane cislo\n"); else printf("Seznam neobsahuje hledane cislo\n");
	UvolniSeznam(Cisla);
	return 0;
}
