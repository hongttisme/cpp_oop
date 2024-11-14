#include <iostream>

using namespace std;

class Coin{
    private:
    string sideUp;


    public:
    Coin(){
        toss();

    }

    void toss(){
        int randomNum = rand() % 2;

        
        if (randomNum == 0){
            sideUp = "heads";
        }else{
            sideUp = "tails";
        }
        return;
    }

    string getSideUp(){
        return sideUp;
    }


};

int main(){
    Coin theCoin;
    int headsCount =0;
    int tailsCount =0;

    cout << "initial facing up: "<< theCoin.getSideUp() << endl << endl;

    for (int i = 0 ; i < 20 ; i++){
        theCoin.toss();
        cout << theCoin.getSideUp() << endl;
        if(theCoin.getSideUp() == "heads"){
            headsCount ++;
        }else{
            tailsCount ++;
        }

    }
    cout << endl;
    cout << "heads count: " << headsCount << endl;
    cout << "tails count: " << tailsCount << endl;


} 
