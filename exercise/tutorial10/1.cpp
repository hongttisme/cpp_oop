#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    double inputNum;
    double sum=0;
    double count = 0;
    double max = -10000;
    ifstream File;
    File.open("Numbers1.txt");
    while(File >> inputNum){
        count ++;
        sum += inputNum;
        if (inputNum > max){
            max = inputNum;
        }
    }

    File.close();
    cout << "average: " << sum / count <<endl;
    cout << "max: " << max;
    return 0;
}
