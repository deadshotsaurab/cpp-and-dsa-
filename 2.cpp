#include <iostream>
using namespace std;

class myclass {
    public:
        int x;

        // Default constructor
        myclass() {
            x = 0;
            cout << "Default constructor is called. x: " << x << endl;
        }

        // Parameterized constructor
        myclass(int val) {
            x = val;
            cout << "Parameterized constructor is called. x: " << x << endl;
        }

        // Destructor
        ~myclass() {
            cout << "Destructor is called. x: " << x << endl;
        }
};

int main() {
	char name;
	cout<<"enter your name :";
	cin>>name;
    myclass obj1;       // Calls the default constructor
    myclass obj2(10);   // Calls the parameterized constructor
    return 0;
}

