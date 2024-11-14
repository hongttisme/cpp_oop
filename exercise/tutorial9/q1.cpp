#include<iostream>
using namespace std;

class Complex{
    private:
    double real;
    double imag;
    public:
    Complex() = default;
    Complex(double r, double i){
        real = r;
        imag = i;
    }

    Complex operator +(Complex c){
        double new_r = real + c.getReal();
        double new_i = imag + c.getImag();
        return Complex(new_r, new_i);

    }

    Complex operator -(Complex c){
        double new_r = real - c.getReal();
        double new_i = imag - c.getImag();
        return Complex(new_r, new_i);

    }

    double getReal(){
        return real;
    }
    double getImag(){
        return imag;
    }
    void printComplex(){
        cout << "(" << real << ", " << imag << ")" << endl;
    }

};

int main(){
    Complex c1(2,2);
    Complex c2(5,3);
    Complex c3 = c1 + c2;
    c3.printComplex();

    Complex c4 = c1 - c2;
    c4.printComplex();
    return 0;
}