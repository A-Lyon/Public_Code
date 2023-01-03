#include <iostream>

using namespace std;

class Foo {
public:
    // Redefine operator new for only this class.
    void *operator new(size_t size) {
	// We can still call new to allocate chars--that will call
	// the global new operator.
	void *p = new char[size];
	cout << "new(" << size << ") returns " << p << '\n';
	return p;
    }

    // Redefine operator delete for only this class.
    void operator delete(void *p, size_t size) {
	cout << "delete(" << p << ", " << size << ")\n";
	delete[] static_cast<char *>(p);
    }

    char zot[4000];
};

class Bar : Foo {
  public:
    double datum;

    void *operator new(size_t size) {
	// We can still call new to allocate chars--that will call
	// the global new operator.
	void *p = new char[size];
	cout << "new(" << size << ") returns " << p << '\n';
	return p;
    }

    // Redefine operator delete for only this class.
    void operator delete(void *p, size_t size) {
	cout << "delete(" << p << ", " << size << ")\n";
	delete[] static_cast<char *>(p);
    }

    char zot[4000];
};


int main() {
cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Bar) = " << sizeof(Foo) << '\n';
    Foo *r = new Foo;
    Foo *s = new Foo;
    cout << "r=" << r << '\n'
	 << "s=" << s << '\n';
    delete r;
    delete s;

    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n' << "size of(Bar)" << sizeof(Bar) << "\n";
    Bar *b = new Bar;
    cout << "b = " << b;

    return 0;
}