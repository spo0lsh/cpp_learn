#include "stdafx.h"
#include "Przedmiot.h"

class Pudelko {
	int z_Pojemnosc;
	const int z_PojemnoscCalkowita;
	const int z_Rozmiar;
	int z_Kolor;
	vector<Przedmiot*> z_PrzedmiotyWsrodku;
public:
	Pudelko(int, Przedmiot*);
	Pudelko(int, int, int);
	Pudelko(int, int);
	~Pudelko();

	int Dodaj(Przedmiot* );
	int Usun(Przedmiot* );
	int Usun(int);
	int UsunWszystkie();
	int WezWolnaPojemnosc();
	void Wypisz();
	// domniemane argumenty, 5.6 tom I str 87
	//static Pudelko* UtworzPudelkoZPrzedmiotow(Przedmiot*);
	//static Pudelko* UtworzPudelkoZPrzedmiotow(Przedmiot*, Przedmiot*);
	static Pudelko* UtworzPudelkoZPrzedmiotow(Przedmiot*, Przedmiot* = NULL);
};
