#include "Phobic.h"
#include <cctype>
#include <set>
#include <iostream>

using namespace std;
    
    //constructors
    Phobic::Phobic(){
      make_scary(13);
    }
    
    Phobic::Phobic(int s) : scardy(s){
      make_scary(13);
    }
      
    //Copy constructor
    Phobic::Phobic(const Phobic& p) = default;
    
    //Destructor
    Phobic::~Phobic() = default;
    
    //Assignment Operatr
    Phobic& Phobic::operator=(const Phobic& s) = default;
    
    //Functions
    



    // called by a.add(n) = new Phobic   this.(callers vector) f.vector
		// a.add(b) = c; 
    //  this = a  rhs = b; new object c is returned
     //                       c needs to have the fears from a and b
    
    Phobic Phobic::add(const Phobic& rhs) const{
      int pho = this->scardy + rhs.get();
      //cout << pho;
      Phobic c(pho);
      for (int i : this->fears){
        c.make_scary(i);
      }
      for (int i : rhs.fears){
        c.make_scary(i);
      }
      return c;
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


  // a.add_to(b);
  // a = a+b,   and all of b's fear array to be added to a's fear array
  // b.fears = {2,3,4,126}
  // a.fears

    void Phobic::add_to (const Phobic& f){
      this->scardy = (this->scardy + f.get());
      for (int i: f.fears){
          this->make_scary(i);
      }

      for(int i = 0; i < f.fears.size(); i++){
        this-> make_scary(fears[i]);
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
		/*
    bool eq() const;
    bool lt() const;
    
    bool is_scary(int i);
    */
    bool Phobic::is_scary(int s) const{
      for (int i : this->fears){
        if (i == s){
          return true;
        }
      }
      return false;
    }

    bool Phobic::eq(const Phobic& f) const{
      if(this->scardy == f.scardy){
        return true;
      }
      else {
        return false;
      }
    }


    bool Phobic::lt(const Phobic& f) const{
      if( this->scardy < f.scardy){
        return true;
      }
      else {
        return false;
      }
    }


    
    //Accessor
    int Phobic::get() const{
      return scardy;
    }


  /*
    void Phobic::make_scary(int s){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      fears.insert(s5);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      fears.insert(s5);
      fears.insert(s6);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 =13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      fears.insert(s5);
      fears.insert(s6);
      fears.insert(s7);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 =13, int s8=13){
      // when making a number scary, check to see if the value is that number, and increment
        
      fears.insert(s);
      fears.insert(s2);
      fears.insert(s3);
      fears.insert(s4); 
      fears.insert(s5);
      fears.insert(s6);
      fears.insert(s7);
      fears.insert(s8);
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

    void Phobic::make_scary(int s, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 =13, int s8=13, int s9=13){
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
      
      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
      }
      }
    }

  */

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

      for (unsigned int o = 0; o < fears.size(); o++){       //scary{13, 14, 16 , 15                   }
        //  cout << "looped " << o;
        if (fears.count(scardy) > 0){
          scardy++;
        }
       // cout << scardy;
      }
    }

    //in makescary check for scary
    


