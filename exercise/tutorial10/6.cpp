#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   ofstream outFile;
   outFile.open("demo.txt");
   cout << "Writing data to the file." << endl;
   outFile << "Proton\n";
   outFile << "Volvo\n";
   outFile << "Honda\n";
   outFile << "Tesla\n";
   outFile << "BMW\n";
   outFile.close();
   cout << "Done" << endl;
    return 0;
}
