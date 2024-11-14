#include <iostream>

using namespace std;
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction() = default;
        Fraction(int a, int b){
            numerator = a;
            denominator = b;
        }

        Fraction operator +(Fraction f){
              int new_n = numerator + f.getNumerator();
              int new_d = denominator;
              return Fraction(new_n, new_d);
        }

        Fraction operator -(Fraction f){
            int new_n = numerator - f.getNumerator();
            int new_d = denominator;
            return Fraction(new_n, new_d);
        }

        Fraction operator *(Fraction f){
            int new_n = numerator * f.getNumerator();
            int new_d = denominator * f.getDenominator();
            return Fraction(new_n, new_d);
        }

        int getNumerator(){
            return numerator;
        }

        int getDenominator(){
            return denominator;
        }

        void display(){
            cout << numerator << "/" << denominator << endl;
        }
};

int main()
{
    Fraction f1(5, 12);
    f1.display();

    Fraction f2(6, 12);
    f2.display();

    Fraction f3 = f1 + f2;
    f3.display();

    Fraction f4 = f1 - f2;
    f4.display();

    Fraction f5 = f1 * f2;
    f5.display();

    return 0;
}
