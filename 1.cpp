#include <iostream>
using namespace std;

class myclass {
public:
    int x;
    //create constructor 
    myclass(int value){
    	x = value;
    	cout<<"constructor called ! value is :" <<endl;
    	
	}
	//destructor 
	~myclass(){
		cout<<"destructor called ! cleaning  up..." <<endl;
		
	}
};
int main()
{
	char name;
	cout<<"enter your name : ";
	cin>>name;
	cout<<"creating a object of my class .." <<endl;
	myclass obj(10);
	cout<<"doing some works with obj.." <<endl;
	cout<<"end of main function obj will be destroyed " <<endl;
	return 0;
}
