#include "stdafx.h"
#include "Pudelko.h"

Pudelko::Pudelko(int p_pojemnosc, Przedmiot* p_przedmiot): z_Rozmiar (p_pojemnosc), z_PojemnoscCalkowita (p_pojemnosc) {
	z_Kolor = 0;
	z_PrzedmiotyWsrodku.push_back(p_przedmiot);
	z_Pojemnosc = z_PojemnoscCalkowita - p_przedmiot->wezRozmiar();
}

Pudelko::Pudelko(int p_pojemnosc, int p_rozmiar, int p_kolor): z_Rozmiar (p_rozmiar), z_PojemnoscCalkowita (p_pojemnosc) {
	z_Pojemnosc = p_pojemnosc;
	z_Kolor = p_kolor;
	//z_Kolor = 0;
}

Pudelko::Pudelko(int p_pojemnosc, int p_rozmiar): z_Rozmiar (p_rozmiar), z_PojemnoscCalkowita(p_pojemnosc) {
	z_Pojemnosc = p_pojemnosc;
	z_Kolor = 0;
}

Pudelko::~Pudelko() {
	UsunWszystkie();
	delete this;
}

int Pudelko::Dodaj(Przedmiot * p_przedmiot) {
	if (z_Pojemnosc >= p_przedmiot->wezRozmiar()) {
		z_PrzedmiotyWsrodku.push_back(p_przedmiot);
		cout << "Dodalismy przedmiot o wielkosci: " << p_przedmiot->wezRozmiar() << endl;
		z_Pojemnosc = z_Pojemnosc - p_przedmiot->wezRozmiar();
		return 0;
	} else {
		cout << "Pudelko nie zmiesci przedmiotu o wielkosci: " << p_przedmiot->wezRozmiar()<< "\n";
	    //cout << endl << "Calkowita pojemnosc: " << z_PojemnoscCalkowita << "Pozostalo: " << z_Pojemnosc << endl;
		cout << "Pojemnosc " << z_Pojemnosc << "/"<< z_PojemnoscCalkowita << endl;
	}
	return 1;
}

int Pudelko::Usun(Przedmiot* p_przedmiot) {
	vector<Przedmiot*>::iterator iterPrzedmiot = z_PrzedmiotyWsrodku.begin();
	vector<Przedmiot*>::iterator iterPrzedmiotKoniec = z_PrzedmiotyWsrodku.end();

	for( int i=0; iterPrzedmiot != iterPrzedmiotKoniec; i++, iterPrzedmiot++) {
		if(*iterPrzedmiot == p_przedmiot) {
			z_Pojemnosc = z_Pojemnosc + z_PrzedmiotyWsrodku[i]->wezRozmiar();
			//cout << "usuwam przedmiot o wielkosci" << z_PrzedmiotyWsrodku[i]->wezRozmiar() << "\n";
			z_PrzedmiotyWsrodku.erase(iterPrzedmiot);
			return 0;
		}
	}
	return 1;
}

int Pudelko::Usun(int p_index) {
	if (z_PrzedmiotyWsrodku[p_index] != NULL) {
		vector<Przedmiot*>::iterator iterPrzedmiot = z_PrzedmiotyWsrodku.begin();
		iterPrzedmiot = iterPrzedmiot + p_index;
		z_Pojemnosc = z_Pojemnosc + z_PrzedmiotyWsrodku[p_index]->wezRozmiar();
		//cout << "usuwam przedmiot o wielkosci" << z_PrzedmiotyWsrodku[p_index]->wezRozmiar() << "\n";
		z_PrzedmiotyWsrodku.erase(iterPrzedmiot + p_index);
		return 0;
	} else {
		return 1;
	}
}

int Pudelko::UsunWszystkie() {
	z_PrzedmiotyWsrodku.clear();
	z_Pojemnosc = z_PojemnoscCalkowita;
	return 0;
}

int Pudelko::WezWolnaPojemnosc() {
	return z_Pojemnosc;
}

void Pudelko::Wypisz() {
	cout << endl << "Calkowita pojemnosc: " << z_PojemnoscCalkowita << endl;
	cout << "Pozostalo wolnego miejsca: " << z_Pojemnosc << endl;
	cout << "Pudelko jest koloru: "<< z_Kolor << endl;

	long cout_flags;
	cout_flags = cout.flags();

	vector<Przedmiot*>::iterator iterPrzedmiot = z_PrzedmiotyWsrodku.begin();
	vector<Przedmiot*>::iterator iterPrzedmiotKoniec = z_PrzedmiotyWsrodku.end();

	cout << "Ilosc przedmiotow: " << z_PrzedmiotyWsrodku.size();

	cout << endl;
	cout << "ID\tRozmiar\tKolor" << endl;
	for(int i=0; iterPrzedmiot != iterPrzedmiotKoniec; i++, iterPrzedmiot++) {
		cout.fill(' ');
		cout.right;
		cout << i+1 << "\t" << z_PrzedmiotyWsrodku[i]->wezRozmiar() << "\t" << z_PrzedmiotyWsrodku[i]->wezKolor() << endl;
	}
	cout.flags(cout_flags);
}


/*Pudelko* Pudelko::UtworzPudelkoZPrzedmiotow(Przedmiot * p_przedmiot, Przedmiot* p_przedmiot2) {
	Pudelko *P;
	P=new Pudelko(p_przedmiot->wezRozmiar()+p_przedmiot2->wezRozmiar(),p_przedmiot);
	cout << "Dodalismy przedmiot o wielkosci: " << p_przedmiot->wezRozmiar() << endl;
	P->Dodaj(p_przedmiot2);
	return P;
}
Pudelko* Pudelko::UtworzPudelkoZPrzedmiotow(Przedmiot * p_przedmiot) {
	Pudelko *P;
	P=new Pudelko(p_przedmiot->wezRozmiar(),p_przedmiot);
	cout << "Dodalismy przedmiot o wielkosci: " << p_przedmiot->wezRozmiar() << endl;
	return P;
}
*/

Pudelko* Pudelko::UtworzPudelkoZPrzedmiotow(Przedmiot * p_przedmiot, Przedmiot* p_przedmiot2) {
	Pudelko *P;
	if(p_przedmiot2 != NULL) {
		P=new Pudelko(p_przedmiot->wezRozmiar()+p_przedmiot2->wezRozmiar(),p_przedmiot);
		cout << "Dodalismy przedmiot o wielkosci: " << p_przedmiot->wezRozmiar() << endl;
		P->Dodaj(p_przedmiot2);
	} else {
		P=new Pudelko(p_przedmiot->wezRozmiar(),p_przedmiot);
		cout << "Dodalismy przedmiot o wielkosci: " << p_przedmiot->wezRozmiar() << endl;
	}
	return P;
}
