#include "Phobic.h"
#include "Phobic.h"     // I meant to do that.
#include <iostream>
#include <cassert>
#include <stdexcept>
 
using namespace std;
 
int main() {
    
    /*
    const Phobic three(3), seven(7), ten(10);
    cout << "three holds: " << three.get() << "\n"; 
    cout << "seven holds: " << seven.get() << "\n";
    cout << "ten holds: " << ten.get() << "\n";  
    Phobic thirteen = three + ten;
    cout << "thirteen holds: " << thirteen.get() << "\n";
    thirteen << 14;
    thirteen << 16;
    cout << "thirteen holds: " << thirteen.get() << "\n";
    thirteen << 15;
    cout << "thirteen holds: " << thirteen.get() << "\n";
    */

    
    const Phobic three(3), seven(7), two=seven/three, five{seven-two}, ten=10;
    assert(five == 5);
    assert(ten-two == 4*two);
    
    
    assert(ten/two == two+two+two/two);
    Phobic x(4); x << 12 << 3;  // fears 3, 12, and 13
    Phobic y; y << 11;          // fears 11 & 13
    Phobic fearful(y/x);
    assert(fearful.is_scary(11));
    assert(fearful.is_scary(12));
    assert(fearful.is_scary(13));
    assert(!x.is_scary(11));
    assert(!y.is_scary(3));
    assert(!y.is_scary(2));
    //Phobic castor, pollox;
    //castor + pollox;
    //Phobic tt = y/0;
 
    Phobic a(13);               // 14
    assert(a.get() == 14);
    a << 14;                    // a is bumped to 15
    assert(a.get() == 15);
    a = a;                      // fraught with peril
    assert(a.is_scary(14));     // did it survive?
 
    assert(2 + a == 17);
    assert(a + 2 == 17);
    assert(a + a == 30);
    assert(a - two == 15);      // 15 - 2 is 13 bumped to 15
    assert(30 == two * a);
    assert(seven == a / two);
 
    a += ten;                   // 15 ⇒ 25
    assert(a == 25);
    a -= 5;                     // 25 ⇒ 20
    assert(20 == a);
    a *= a;                     // 20 ⇒ 400
    assert(a == 400);
    a /= ten;                   // 400 ⇒ 40
    assert(a == 40);
    
    assert(two < three);
    assert(3 > two);
    assert(3 <= ten);
    assert(ten >= 5);
    assert(ten == ten);
    assert(-10 != ten);
 
    try {
        a /= (two/ten);         // attempt division by zero
    }
    catch (const runtime_error &) {  // Hey, no variable!
        a += 3 - two;           // 40 ⇒ 41
    }
    assert(a.get() == 41);      // Did we catch the divide by zero?
    
    cout << "Success!\n";
    return 0;
}
