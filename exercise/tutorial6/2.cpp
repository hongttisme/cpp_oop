#include <iostream>



using namespace std;

class RoomDimension{
    private:
    double length;
    double width;

    public: 
    double getArea(){
        return length * width;
    }
    void setLength(double l){
        length = l;
    }
    void setWidth(double w){
        width = w;
    }

};

class RoomCarpet{
    private:
    public:
    RoomDimension theRoomDimension;
    double carpetCostsquarePerFoot;
    double getTotalCost(){
        return carpetCostsquarePerFoot * theRoomDimension.getArea();
    }

};

int main(){
    
    RoomCarpet theRoomCarpet;
    double temp;

    cout << "Enter length of room: " ;
    cin >> temp;
    theRoomCarpet.theRoomDimension.setLength(temp);

    cout << "Enter width of room: " ;
    cin >> temp;
    theRoomCarpet.theRoomDimension.setWidth(temp);

    cout << "Enter cost per square feet: " ;
    cin >> theRoomCarpet.carpetCostsquarePerFoot;
    cout << "The total cost of carpet: " << theRoomCarpet.getTotalCost();

    return 0;
}
