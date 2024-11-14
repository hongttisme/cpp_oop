#include<iostream>
using namespace std;

class NumDays{
    private:
    double hours;
    double days;

    public:
    NumDays() = default;
    NumDays(double h){
       setHours(h);
       convert();
    }

    void convert(){
        days = hours/24;
    }

    void setHours(int h){
        hours = h;
    }

    int getHours(){
        return hours;
    }

    double getDays(){
        return days;
    }

    double operator +(NumDays nd){

        return hours + nd.getHours();

    }
    double operator -(NumDays nd){

        return hours - nd.getHours();

    }

    
    NumDays operator++(){
        hours ++;
        convert();
        return *this;
    }

    NumDays operator--(){
        hours --;
        convert();
        return *this;
    }

};

int main(){
    NumDays nd1(12);
    NumDays nd2(36);

    cout << nd1.getDays() << endl;
    cout << nd2.getDays() << endl;

    cout << nd1 + nd2 << endl;
    cout << nd1 - nd2 << endl;

    ++nd1;
    cout << nd1.getDays() << endl;

    --nd2;
    cout << nd2.getDays() << endl;

}