#include<iostream>
using namespace std;

class animal {
public:
	animal() {}
	~animal() {}

	const void name1() { cout << "animal " << endl; }
	virtual const void name2() { cout << "animal " << endl; }
};

class cat : public animal {
public:
	const void name1() { cout << "cat " << endl; }
	const void name2() { cout << "cat " << endl; }
};

class dog : public animal{
public:
	const void name1() { cout << "dog " << endl; }
	const void name2() { cout << "dog " << endl; }
};

void func1(animal& a, cat& b, dog& c) {
	a.name1();
	b.name1();
	c.name1();
}

void func2(animal& a, cat& b, dog& c) {
	a.name2();
	b.name2();
	c.name2();
}

void func3(animal& a, animal& b, animal& c) {
	a.name1();
	b.name1();
	c.name1();
}

void func4(animal& a, animal& b, animal& c) {
	a.name2();
	b.name2();
	c.name2();
}

int main() {
	animal a;
	cat b;
	dog c;

	func1(a, b, c);  // animal cat dog
	func2(a, b, c);  // animal cat dog
	func3(a, b, c);  // animal animal animal
	func4(a, b, c);  // animal cat dog
}