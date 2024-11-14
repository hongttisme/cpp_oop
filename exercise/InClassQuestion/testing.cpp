#include <iostream>
using namespace std;

class MyClass {
public:
    int intValue;
    double doubleValue;
    string strValue;

    // Constructor for int
    MyClass(int val) {
        intValue = val;
        cout << "Integer constructor called with value: " << intValue << endl;
    }

    // Constructor for double
    MyClass(double val) {
        doubleValue = val;
        cout << "Double constructor called with value: " << doubleValue << endl;
    }

     MyClass(float val) {
        doubleValue = val;
        cout << "Float constructor called with value: " << doubleValue << endl;
    }

    // Constructor for string
    MyClass(string val) {
        strValue = val;
        cout << "String constructor called with value: " << strValue << endl;
    }
};

int main() {
    MyClass obj1(10);           // Calls int constructor
    MyClass obj2(5.5f);          // Calls double constructor
    MyClass obj3("Hello");      // Calls string constructor

    return 0;
}
