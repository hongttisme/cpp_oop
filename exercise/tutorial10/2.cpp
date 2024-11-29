#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string inputName;
    int count = 0;
    int theIndex;
    bool jasmineExist = false;
    ifstream File;
    File.open("Names.txt");
    while(File >> inputName){
        count ++;
        if(inputName == "Jasmine"){
            jasmineExist = true;
            theIndex = count -1;
        }
    }

    File.close();
    cout << "Name count: " << count <<endl;
    if (jasmineExist)
    {
    cout << "Jasmine index: " << theIndex;
    }
    
    return 0;
}
