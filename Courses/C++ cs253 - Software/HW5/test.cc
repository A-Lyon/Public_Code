#include <iostream>
#include <string.h>
#include <list.h>

using namespace std;

int main(){

set<short> s = {89, 67, 12};
list<double> f(s.begin(), s.end());

cout << f.size() << '/' << *f.begin() << '/' << f.back() << '\n';

return 1;

}
