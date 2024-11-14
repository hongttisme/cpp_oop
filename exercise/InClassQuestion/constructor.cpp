#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>



using namespace std;

class Point{
    private:
    float coord_x, coord_y;
    public:
    Point(){
        coord_x = 0;
        coord_y = 0;
    }

    Point(float x){
        coord_x = x;
        coord_y = 0;
    }

    Point(float x, float y){
        coord_x = x;
        coord_y = y;
    }
    void Print(){
        cout << "x: " << coord_x << ", y: " << coord_y << endl;
        return;
    }

};


int main(){
    Point a;
    Point b(1);
    Point c(1,1);
    a.Print();
    b.Print();
    c.Print();
    return 0;
} 
