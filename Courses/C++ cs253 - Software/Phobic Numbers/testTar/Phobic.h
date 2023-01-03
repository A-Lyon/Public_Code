#ifndef PHOBIC_H_INCLUDED
#define PHOBIC_H_INCLUDED
#include<set>
#include <iostream>

	class Phobic
	{

	public:
    
    //constructors
   	 Phobic();
     Phobic(int s);
    
     
    //Copy constructor
    Phobic(const Phobic&);
    
    //Destructor
    ~Phobic();
    
    //Assignment Operatr
    Phobic& operator=(const Phobic&);
    
    // Variables
    std::set<int> fears = {13};
    
    //Functions
    
		Phobic add(const Phobic&) const;
    Phobic sub(const Phobic&) const;
    Phobic mul(const Phobic&) const;
    Phobic div(const Phobic&) const;
		
    void add_to(const Phobic&);
    void sub_from(const Phobic&);
    void mul_by(const Phobic&);
    void div_by(const Phobic&);
    /*
    bool eq() const;
    bool lt() const;
    bool is_scary(int i);
    */

    bool is_scary(int) const;
    bool eq(const Phobic&) const;
    bool lt(const Phobic&) const;

    /*
    void make_scary(int);
    void make_scary(int, int s2 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 = 13, int s8 = 13);
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 = 13, int s8 = 13, int s9 = 13);
    */
    
    void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 = 13, int s8 = 13, int s9 = 13, int s10 = 13);


    //Accessor
    int get() const;
    
		
   private:
     int scardy;  
     
	};

#endif /* PHOBIC_H_INCLUDED */
