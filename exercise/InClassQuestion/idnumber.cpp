#include <iostream>
using namespace std;

class Person{
    private:
        string firstName;
        string lastName;
        string fullName;
        int idNumber;
        string passID;

        void generateFullName(){
            fullName = firstName + " " + lastName;
        }

        void generatePassID(){
            passID = lastName + " " +  to_string(idNumber);
        }
    public:
        Person(string fName, string lName, int id){
            firstName = fName;
            lastName = lName;
            idNumber = id;
            generateFullName();
            generatePassID();
        }

        string getFirstName(){
            return firstName;
        }

        string getLastName(){
            return lastName;
        }

        string getFullName(){
            return fullName;
        }

        string getPassID(){
            return passID;
        }
};

int main()
{
    const int arraySize = 3;
    Person persons[arraySize] = {
        Person("John", "Smith", 12),
        Person("kyan", "lol", 13),
        Person("samira", "lim", 14)
    };
    for(int i = 0; i<3; i++){
        cout << persons[i].getFirstName() << endl;
        cout << persons[i].getLastName() << endl;
        cout << persons[i].getFullName() << endl;
        cout << persons[i].getPassID() << endl << endl;
    }


    return 0;
}
