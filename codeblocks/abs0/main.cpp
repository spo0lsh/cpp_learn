#include <iostream>

using namespace std;


class Abstrakcja
{
public:
	virtual void Wypisz()=0;
	virtual void Wypelnij()=0;
};

class AA : virtual public Abstrakcja
{
public:
	void Wypisz();
	void Wypelnij();
};

class BB : virtual public Abstrakcja
{
public:
	void Wypisz();
	void Wypelnij();
};

int main()
{
    AA A;
    A.Wypisz();
    BB B;
    B.Wypisz();
    return 0;
}


void AA::Wypisz()
{
    std::cout << "AA::Wypisz()" << std::endl;
}

void AA::Wypelnij()
{
    std::cout << "AA::Wypelnij()" << std::endl;
}

void BB::Wypisz()
{
    std::cout << "BB::Wypisz()" << std::endl;
}

void BB::Wypelnij()
{
    std::cout << "BB::Wypelnij()" << std::endl;
}
