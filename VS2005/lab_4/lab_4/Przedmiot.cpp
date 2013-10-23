#include "stdafx.h"
#include "Przedmiot.h"

Przedmiot::Przedmiot(int p_rozmiar):z_Rozmiar (p_rozmiar) {
	z_Kolor = 0;
	st_IloscPrzedmiotow++;
}

Przedmiot::Przedmiot(int p_rozmiar, int p_kolor): z_Rozmiar (p_rozmiar) {
	z_Kolor = p_kolor;
	st_IloscPrzedmiotow++;
}

int Przedmiot::wezRozmiar() {
	return z_Rozmiar;
}

int Przedmiot::wezKolor() {
	return z_Kolor;
}

int Przedmiot::ustawKolor(int p_kolor) {
	z_Kolor = p_kolor;
	return 0;
}

int Przedmiot::st_IloscPrzedmiotow = 0;
