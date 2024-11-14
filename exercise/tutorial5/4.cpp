#include <iostream>
using namespace std;
class Sample {
 static int count;
public:
 Sample()
 {
 count++;
 }
 static void printTotalObj()
 {
 cout << count << endl;
 }
};
int Sample::count = 0;
int main()
{
 Sample S1;
 Sample S2;
 Sample::printTotalObj();
 return 0;
}