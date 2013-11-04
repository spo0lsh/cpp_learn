#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () {
//write
  ofstream fout ("example.txt");
  if (fout.is_open())
  {
    fout << "This is a line.\n";
    fout << "This is another line.\n";
    fout.close();
  }
  else cout << "Unable to open file";

//read

  string line;
  ifstream fin ("example.txt");
  if (fin.is_open())
  {
    while ( getline (fin,line) )
    {
      cout << line << endl;
    }
    fin.close();
  }

  else cout << "Unable to open file";

    return 0;
}
