#include "Phobic.h"
#include <cctype>
#include <set>
#include <iostream>
#include <string>

using namespace std;
    
    //constructors
    Phobic::Phobic(){
      *this << 13;
    }
    Phobic::Phobic(int s) : scardy(s){
      *this << 13;
    }
      
    //Copy constructor
    Phobic::Phobic(const Phobic& p) = default;
    
    //Destructor
    Phobic::~Phobic() = default;
    
    //Assignment Operatr
    Phobic &Phobic::operator=(const Phobic& s) = default;
    
    //Accessors
    int Phobic::get() const{
      return scardy;
    }

    bool Phobic::is_scary(int checkMeOut){
      for(int i : this->fears){
        if(i == checkMeOut){
          return true;
        }

      }
      return false;
    }

    //Operators
    Phobic &Phobic::operator+=(const Phobic& rhs){
      scardy += rhs.scardy;
      for (int f : rhs.fears){
        *this << f;
      }
      return *this;
    }

    Phobic &Phobic::operator-=(const Phobic& rhs){
      scardy -= rhs.scardy;
      for (int f : rhs.fears){
        *this << f;
      }      
      return *this;
    }

    Phobic &Phobic::operator*=(const Phobic& rhs){
      for (int f : rhs.fears){
        *this << f;
      }
      scardy *= rhs.scardy;
      return *this;
    }

    Phobic &Phobic::operator/=(const Phobic& rhs){
      for (int f : rhs.fears){
        *this << f;
      }
      if (rhs.get() == 0){
        	throw runtime_error("./test: invalid args, divide by zero with operands: " + to_string(scardy) + " and " + to_string(rhs.get()) + "./n");
      } 
      scardy /= rhs.scardy;  
      return *this;
    }

    //Free functions like complex.cc

    
    // called by a.add(n) = new Phobic   this.(callers vector) f.vector
	/*
	Phobic Phobic::add(const Phobic& f) const{
     	 int pho = this->scardy + f.get();
     	 //cout << pho;
      	Phobic c(pho);
      	for (int i : this->fears){
        	c.make_scary(i);
      	}
      	for (int i : f.fears){
        	c.make_scary(i);
      	}
      	return c;
	}
  */

Phobic operator+(const Phobic& lhs, const Phobic& rhs){
	  Phobic retVal = lhs;
    return retVal += rhs;
    }	

Phobic operator-(const Phobic& lhs, const Phobic& rhs){
    Phobic retVal = lhs;
    return retVal -= rhs;
}    

Phobic operator*(const Phobic& lhs, const Phobic& rhs){
    Phobic retVal = lhs;
    return retVal *= rhs;
}    

Phobic operator/(const Phobic& lhs, const Phobic& rhs){
    //check divide by zero
    if (rhs.get() == 0){
        	throw runtime_error("./test: invalid args, divide by zero with operands: " + to_string(lhs.get()) + " and " + to_string(rhs.get()) + "./n");
    }
    Phobic retVal = lhs;
    return retVal /= rhs;
}




//Equality Operators
bool operator==(const Phobic& lhs, const Phobic& rhs){
    return lhs.get() == rhs.get();
}

bool operator!=(const Phobic& lhs, const Phobic& rhs){
    return !(lhs == rhs);
}

bool operator<(const Phobic& lhs, const Phobic& rhs){
      return (lhs.get() < rhs.get());
}

bool operator<=(const Phobic& lhs, const Phobic& rhs){
      return (lhs.get() <= rhs.get());
    
}

bool operator>(const Phobic& lhs, const Phobic& rhs){
      return (lhs.get() > rhs.get());
}

bool operator>=(const Phobic& lhs, const Phobic& rhs){
      return (lhs.get() >= rhs.get());
}


Phobic& Phobic::operator<< (int p){
    this->fears.insert(p);

    for (unsigned int o = 0; o < fears.size(); o++){       //fears{13, 14, 16 , 15 , ... , 28    }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy+=1;
        //  cout << scardy;
        }
        //cout << scardy;
      }
    return *this;
  }
  
	
    	Phobic Phobic::sub(const Phobic& f) const{
      	int pho = this->scardy - f.get();
      	//cout << pho;
      	Phobic c(pho);
      	for (int i : this->fears){
        	c.make_scary(i);
      	}
      	for (int i : f.fears){
        	c.make_scary(i);
      	}
      	return c;
 	}
	

Phobic Phobic operator-(const Phobic& l, const Phobic& r){
	    int s = l.scardy - r.scardy;
	    Phobic su(s);

	    for (int i : l.fears){
		    su.make_scary(i);
	    }
	    for (int i : r.fears){
		    su.make_scary(i);
	    }
	    return su;
      }

	
    	Phobic Phobic::mul(const Phobic& f) const{
      	int pho = this->scardy * f.get();
      	//cout << pho;
      	Phobic c(pho);
      	for (int i : this->fears){
        	c.make_scary(i);
      	}
      	for (int i : f.fears){
        	c.make_scary(i);
      	}
      	return c;
    	}
	

Phobic Phobic operator*(const Phobic& l, const Phobic& r){
	int m = l.scardy * r.scardy;
	Phobic mu(m);

	for (int i : l.fears){
		mu.make_scary(i);
	}
	for (int i : r.fears){
		mu.make_scary(i);
	}
	return mu;
     }

	
	Phobic Phobic::div(const Phobic& f) const{
      	//check divide by zero
      	if (f.get() == 0){
        	cerr << "argv[0]: Invalid args, divide by zero";
      	}
      	int pho = this->scardy / f.get();
      		//cout << pho;
      	Phobic c(pho);
      	for (int i : this->fears){
        	c.make_scary(i);
      	}
      	for (int i : f.fears){
        	c.make_scary(i);
      	}
      	return c;      
    	}
	

     Phobic Phobic::operator/(const Phobic&l, const Phobic& r){
	if(r.scardy = 0){
		cerr << "argv[0]: Invalid args, divide by zero."
	}
	int d = l.scardy / r.scardy;
	Phobic di(d);
	
	for (int i : l.fears){
		di.make_scary(i);
	}
	for (int i : r.fears){
		di.make_scary(i);
	}
	return di;
     }

    void Phobic::add_to (const Phobic& f){
      this->scardy = (this->scardy + f.get());
      for (int i: f.fears){
          this->make_scary(i);
      }
    }

    void Phobic::sub_from (const Phobic& f){
      this->scardy = (this->scardy - f.get());
      for (int i: f.fears){
          this->make_scary(i);
      } 
    }

    void Phobic::mul_by (const Phobic& f){
     this->scardy = (this->scardy * f.get());
      for (int i: f.fears){
          this->make_scary(i);
      }
    }

    void Phobic::div_by (const Phobic& f){
      //check divide by zero
      if (f.get() == 0){
        cerr << "argv[0]: Invalid arg, divide by zero";
      }
  
      this->scardy = (this->scardy / f.get());
      for (int i: f.fears){
          this->make_scary(i);
      } 
    }
		
    bool eq() const;
    bool lt() const;
    
    bool is_scary(int i);
    
    void Phobic::make_scary(int s, int s2, int s3, int s4, int s5, int s6, int s7, int s8, int s9, int s10){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      fears.insert(s5);
      fears.insert(s6);
      fears.insert(s7);
      fears.insert(s8);
      fears.insert(s9);
      fears.insert(s10);

      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
        }
       // cout << scardy;
      }
    }

    //in makescary check for scary
    


