
#include <iostream>
using namespace std;

class A {
protected:
	int x;
public:
	A() : x(42) {}
};

class B : public A {
};

class C : public B {
protected:
	typedef B Precursor;

public:
	void foo() {
		//cout << x << endl;  // error: ‘x’ was not declared in this scope
		cout << Precursor::x << endl;
		cout << this->x << endl;
	}

	int get() {
		return Precursor::x;
	}

	int* getPtr() {
		// error: ‘A<int>::FT A<int>::x’ is protected
		// error: within this context
		// error: cannot convert ‘A<int>::FT A<int>::* {aka int A<int>::*}’ to ‘C<int>::FT* {aka int*}’ in return
		return &Precursor::x;
		//return &this->x;  // this works
	}
};


int main() {
	C obj;
	obj.foo();
	cout << obj.get() << endl;
	cout << obj.getPtr() << endl;
}

