#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

vector<int> v;

//1. add elements when not 0
int i;
while (cin >> i){
      if (i > 0){
        v.push_back(i);
      }
      else {
        break;
      } 
    }
    
//2. display values one per line
for (size_t i=0; i < v.size(); i++){
  cout << v[i] << "\n";
}    
    
//3. import file
string s;
ifstream in("/etc/resolv.conf");
  while (getline(in,s)){
  }

//4.
multiset<char> ms;
  for (auto val : s){
    ms.insert(val);
  }

//5. 
set<char> c;
  for (char ch : ms){
    c.insert(ch);
  }

//6.
  cout << "string: size=" << s.size();
  cout << "set: size=" << c.size();
  cout << "multiset: size=" << ms.size();

/*QUESTION 7

The size() function returns how many elements a container is holding. 
A string has several bytes being used to store the pointer, the size, and the currently used amount, which
makes it more effecient to store in an object, and to store contiguously. In a set, the data is not stored contiguously. 

*/





return 0;

}