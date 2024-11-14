#include<iostream>
using namespace std;

class Ship{
    protected:
    string nameOfShip;
    int yearShipBuild;

    public:
    Ship() = default;
    Ship(string name, int year){
        setShipName(name);
        setShipBuildYear(year);
    }

    string getShipName(){
        return nameOfShip;
    }

    int getShipBuildYear(){
        return yearShipBuild;
    }

    void setShipName(string name){
        nameOfShip = name;
    }

    void setShipBuildYear(int year){
        yearShipBuild = year;
    }

    
    virtual void printInfo(){
        cout << "ship's name: " << nameOfShip << endl;
        cout << "year it was build: " << yearShipBuild << endl;
    }

};

class CruiseShip: public Ship{
    protected:
    int maxPassengers;
    public:
    CruiseShip() = default;
    CruiseShip(string name, int year, int maxNum){
        setShipName(name);
        setShipBuildYear(year);
        setMaxPassengers(maxNum);
    }

    int getMaxPassengers(){
        return maxPassengers;
    }
    void setMaxPassengers(int num){
        maxPassengers = num;
    }

    void printInfo(){
        cout << "ship's name: " << nameOfShip << endl;
        cout << "max passengers: " << maxPassengers << endl;
    }
};


class CargoShip: public Ship{
    protected:
    int cargoCapacity;
    public:
    CargoShip() = default;
    CargoShip(string name, int year, int capacity){
        setShipName(name);
        setShipBuildYear(year);
        setCargoCapacity(capacity);
    }

    int getCargoCapacity(){
        return cargoCapacity;
    }
    void setCargoCapacity(int num){
        cargoCapacity = num;
    }

    void printInfo(){
        cout << "ship's name: " << nameOfShip << endl;
        cout << "Cargo capacity: " << cargoCapacity << endl;
    }
};

int main(){

    Ship ship1("ship1", 2000);
    ship1.printInfo();

    CruiseShip ship2("ship2", 2001, 10000);
    ship2.printInfo();

    CargoShip ship3("ship3", 2002, 9999);
    ship3.printInfo();


}