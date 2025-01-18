#include <iostream>
using namespace std;

// 4 member functions which are implicitly called by compiler

/*
1. constructor - default and parameterized
2. copy constructor
3. copy assignment operator
4. destructor - when objects are being destroyed then destructor will be called
*/

/*

1. constant data members
2. const member functions

- those functions which can not update data members of the class

*/

class Car {

	// data members
	int model_no;
	int price;

public:
	// this is pointer to char
	char * name;

	// constructor overloading
	// same name and (different no of parms or different type of parameters)

	// default constructor
	Car() {
		cout << "Inside default constructor" << endl;
	}

	// initialise data members
	// parameterized constructor
	Car(int model_no, int price, char * n) {

		this->model_no = model_no;
		this->price = price;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	// with only one parameter
	// model_no, name both will get garbage value
	Car(int price) {
		this->price = price;
	}
	// setters we make our parameters const

	void set_price(const int p) {
		price = p;
		if (p < 0) {
			price = 100;
		}
	}

	void set_model_no(const int p) {
		model_no = p;
	}

	// void set_name(string p) {
	// 	name = p;
	// }

	// make these getters as const member functions

	int get_price() const {
		return price;
	}

	string get_name() const {
		return name;
	}

	int get_model_no() const {
		return model_no;
	}

	void print() const {

		cout << "Name : " << name << endl;
		cout << "Price : " << price << endl;
		cout << "Model No : " << model_no << endl;
	}

	// override copy constructor
	// x is just an alias

	// deep copy
	Car(const Car &x) {
		price = x.price;
		model_no = x.model_no;

		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	// operator overloading - deep copy
	void operator = (Car &x) {
		price = x.price;
		model_no = x.model_no;

		name = new char[strlen(x.name) + 1];
		strcpy(name, x.name);
	}

	// destructor
	~Car() {
		cout << "Inside a destructor of Car : " << name << endl;

		if (name != NULL) {

			delete [] name;
		}
	}

};


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Car c(100, 200, "BMW");

	// shallow copy
	Car d(c); // call the implicit copy constructor

	// if i change price of d
	d.set_price(20);
	d.name[0] = 'P';

	// c.print();
	// d.print();

	Car e;
	e = d; // copy assignment operator c++ class

	e.name[0] = 'A';
	c.print();
	d.print();
	e.print();

	// just before the return statement
	// destructor will be called
	return 0;
}

