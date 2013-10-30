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
	void Wypisz()
	{
    std::cout << "AA::Wypisz()" << std::endl;
    }
	void Wypelnij()
	{
    std::cout << "AA::Wypelnij()" << std::endl;
    }
};

class BB : virtual public Abstrakcja
{
public:
	void Wypisz()
	{
    std::cout << "BB::Wypisz()" << std::endl;
    }
	void Wypelnij()
	{
	    std::cout << "BB::Wypelnij()" << std::endl;
	}
};

int main()
{
    AA A;
    A.Wypisz();
    BB B;
    B.Wypisz();
    return 0;
}
