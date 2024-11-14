#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>



using namespace std;


void Try(){
    static int i = 0;
    cout << i << '\n';
    i ++;
}

int main(){
    for(int j = 0; j < 5 ; j++){
        Try();
    }
    return 0;
} 
