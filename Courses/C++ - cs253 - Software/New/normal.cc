#include <iostream>

using namespace std;

class Foo {
  public:
    double datum;
};




int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Foo) = " << sizeof(Foo) << '\n';
    Foo *p = new Foo;
    Foo *q = new Foo;
    cout << "p=" << p << '\n'
	 << "q=" << q << '\n';
    delete p;
    delete q;
    
    for (int i = 0; i < 10000000; i++){
      Foo *r = new Foo;
     // cout << r;
    }
    

}
