#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   cout << "Nazwa programu: " << argv[0] << endl;
   cout << "Ilosc argumentow: " << argc << endl;
   for(int i = 1; i < argc; i++)
      {
         cout << i << ". Argument to: " << argv[i] << endl;
      }
   return 0;
}
