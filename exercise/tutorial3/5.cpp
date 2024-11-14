#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>



using namespace std;

int main(){
    struct date
    {
        int day;
        int month;
        int year;
    };
    date compare_date[2];
    for(int i = 0; i < 2; i++){
        cout<< "date " << i+1 <<" \n";
        cout << "input day: ";
        cin >> compare_date[i].day;
        cout << "input month: ";
        cin >> compare_date[i].month;
        cout << "input year: ";
        cin >> compare_date[i].year;
    }
    if (compare_date[0].day == compare_date[1].day)
    {
            if (compare_date[0].month == compare_date[1].month)
            {
                    if (compare_date[0].year == compare_date[1].year)
                    {
                        cout << "is equal";
                        return 0;
                    }
            }
    }
    cout << "not equal";
    
    
    return 0;
} 
