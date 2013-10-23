#include "stdafx.h"


class Przedmiot {
protected:
	const int z_Rozmiar;
	int z_Kolor;
public:
	static int st_IloscPrzedmiotow;
	Przedmiot(int);
	Przedmiot(int, int);
	int wezRozmiar();
	int wezKolor();
	int ustawKolor(int);
};
