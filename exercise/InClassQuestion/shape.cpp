#include <iostream>
using namespace std;

class Shape{
    private:
    string name;
    public:
    string getname(){
        return name;
    }
    void setname(string newName){
        name = newName;
    }


};

class Rectangle: public Shape{
    
}

int main(){
    
}