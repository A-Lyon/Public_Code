#include <iostream>
#include <sstream>

using namespace std;

class Number {
  public:
    Number() = default;
    Number(const Number &) = default;
    Number(int v) : value(v) {}
    Number &operator=(int n) { value = n; return *this; }
    
    operator int() const { return value; } //converts Number to int
  
  private:
    int value = 0;			// default value unless otherwise given
};


//input operator, reads int from stream and assigns to number, and returns refrence
// to the stream
istream &operator>>(istream &is, Number &rhs) {
    string n;
    int i;
    //std::string::size_type sz;
    is >> n;
    //cout << n << "\n";
    
    if(n.compare("one") == 0){
      i = 1;
    }
    else if(n.compare("two") == 0){
      i = 2;
    }
    else if(n.compare("three") == 0){
      i = 3;
    }
    else if(n.compare("four") == 0){
      i = 4;
    }
    else if(n.compare("five") == 0){
      i = 5;
    }
    //stoi absolutely wont work, even when formatted exactly like c++ refrence
    // so im converting c++ string to cstr to use atoi and it worked.
    // its ugly, im sorry!
    else {
      char* a = &(n[0]);
      i = std::atoi(a);
    }
    
    rhs = i;
    return is;
}

// reads from string stream into number. 
// three is not valid integer, so it should fail.
// stops at t, because stream is at fail state.... 

int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    
    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}




/*
    switch(n){
      case "one":
        i = 1;
        break;
      case "two":
        i = 2;
        break;
      case "three":
        i=3;
        break;
      case "four":
        i = 4;
        break;
      case "five":
        i = 5;
        break;
      default:
        i = stoi(n);
*/