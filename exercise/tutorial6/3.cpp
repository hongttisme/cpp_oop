#include <iostream>

using namespace std;

class RetailItem{
    private:
    string description;
    int unitsOnHand;
    double price;


    public:
    RetailItem(){
        setDescrioption("");
        setUnitsOnHand(0);
        setPrice(0);
    }

    RetailItem(string s, int u, double p){
        setDescrioption(s);
        setUnitsOnHand(u);
        setPrice(p);
    }

    void setDescrioption(string s){
        description = s;
    }
    void setUnitsOnHand(int u){
        unitsOnHand = u;
    }
    void setPrice(double p){
        price = p;
    }

    string getDescrioption(){
        return description ;
    }
    int getUnitsOnHand(){
        return unitsOnHand ;
    }
    double getPrice(){
        return price ;
    }

};

class CashRegister{
    private:
    RetailItem theRetailItem;
    int theQuantity;


    public:


    CashRegister(RetailItem item, int quantity){
    theRetailItem = item;
    theQuantity = quantity;
    }

    double getSubtotal(){
        return theQuantity * theRetailItem.getPrice();
    }

    double getTax(){
        return getSubtotal()* 0.06;
    }

    double getTotal(){
        return getSubtotal() + getTax();
    }



    
};

int main(){
    RetailItem item1("A4 paper", 100, 20);
    int quantity;

    cout << "Enter purchase quantity: ";
    cin >> quantity;

    CashRegister cashRegister1(item1, quantity);
    
    cout << "The subtotal: $" <<  cashRegister1.getSubtotal() << endl;
    cout << "The tax: $" << cashRegister1.getTax() << endl;
    cout << "The total: $" << cashRegister1.getTotal() << endl;

    return 0;
} 
