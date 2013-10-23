// lab_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pudelko.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	Przedmiot P(1);
	Przedmiot P1(24,2);
	Przedmiot P2(50,10);
	Przedmiot P3(10,5);
	Pudelko *A;
	cout << "------------------------\n";
	A = Pudelko::UtworzPudelkoZPrzedmiotow(&P,&P1);
	A->Wypisz();
	A->UsunWszystkie();
	A->Wypisz();
	cout << "------------------------\n";
	A = Pudelko::UtworzPudelkoZPrzedmiotow(&P3);
	A->Wypisz();
	A->UsunWszystkie();
	A->Wypisz();
	cout << "------------------------\n";
	
	Pudelko *B = new Pudelko(5,11);
	Pudelko *C = new Pudelko(10,20,11);
	B->Dodaj(&P);
	B->Dodaj(&P1);
	B->Dodaj(&P2);
	B->Dodaj(&P3);
	B->Wypisz();
	C->Wypisz();
	/*
	
	
	//Przedmiot P(1);
	//Przedmiot P1(24,2);
	cout <<"Liczba zyjacych obiektow: "<< Przedmiot::st_IloscPrzedmiotow << endl;
	cout << "nowe pudlo B\n";
	//Pudelko *B;
	//Pudelko *C;
	Pudelko *D;
	B = Pudelko::UtworzPudelkoZPrzedmiotow(&P,&P1);
	B->Wypisz();
	B->Usun(&P1);
	B->Wypisz();
	cout <<endl;
	cout << "usuwamy wszystko z pudla B\n";
	B->UsunWszystkie();
	B->Wypisz();
	cout <<endl;
	cout << "nowe pudlo B\n";
	C = Pudelko::UtworzPudelkoZPrzedmiotow(&P);
	C->Wypisz();
	//Przedmiot P2(50,3);
	//Przedmiot P3(10,0);
	Przedmiot P4(15,7);
	Przedmiot P5(1,10);
	cout <<"Liczba zyjacych obiektow: "<< Przedmiot::st_IloscPrzedmiotow << endl;
	B->Dodaj(&P);
	B->Dodaj(&P1);
	B->Dodaj(&P2);
	B->Dodaj(&P3);
	B->Dodaj(&P4);
	B->Dodaj(&P5);
	B->Wypisz();
	C->Wypisz();
*/	
	system("PAUSE");
	return 0;
}

