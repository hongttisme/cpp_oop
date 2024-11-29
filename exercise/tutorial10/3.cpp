#include <iostream>
#include <fstream>
using namespace std;


bool isPrime(int num){
    int k = num - 1;
    while (k > 1)
    {
        if(num%k == 0)return false;
        k --;
    }
    
    return true;
}


bool isPrime(int num){
    int k = 2;
    while(k < num){
        k++;
    }
}


int main()
{
    int inputNum;
    int count = 0;
    
    ifstream File;
    ofstream outFile;


    File.open("Numbers2.txt");
    outFile.open("PrimeNumbers.txt");

    while(File >> inputNum){
        if(isPrime(inputNum)){
            outFile << inputNum << endl;
            count ++;

        }
    }

    File.close();
    outFile.close();

    cout << "Prime count: " << count <<endl;
    
    return 0;
}
