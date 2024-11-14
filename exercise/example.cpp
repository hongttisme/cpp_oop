#include <iostream>
#include <map>
#include <vector>
#include <set>


using namespace std;

class hello{
    public:
    void printhello(){
        cout << "hello" << endl;
    }

};


// return -1 when user input incorrectly
double getPositiveDouble() {
    double value;
    cin >> value;

    // Check if the input failed 
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        return -1;
    }

    if(value<= 0){
        return -1;
    }

    // Successfully read a double value
    return value;
}

int main(){
    double a = getPositiveDouble();
    if(a == -1){
        cout << "failed";
    }else{
        cout << "passed: ";
        cout << a;
    }
    return 0;
} 
