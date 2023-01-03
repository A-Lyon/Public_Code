#ifndef PHOBIC_H_INCLUDED
#define PHOBIC_H_INCLUDED
#include <set>
#include <iostream>
#include <ostream>
#include <string>

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
    
    //Accessor
    int get() const;

    // Variables
	std::set<int> fears = {13};

    //Operators
    Phobic& operator+=(const Phobic &);
    Phobic& operator-=(const Phobic &);
    Phobic& operator*=(const Phobic &);
    Phobic& operator/=(const Phobic &);
    		
private:
    int scardy;  
     
    };

    //Free Functions for operators like complex.cc

	//Phobic add(const Phobic&) const;	    
	Phobic operator+(const Phobic&, const Phobic&);
    Phobic operator-(const Phobic&, const Phobic&);
    Phobic operator*(const Phobic&, const Phobic&);
    Phobic operator/(const Phobic&, const Phobic&);

    bool operator==(const Phobic&, const Phobic&);
    bool operator!=(const Phobic&, const Phobic&);

    /*
	// Phobic sub(const Phobic&) const;
	Phobic operator-(const Phobic&, const Phobic&);

	//Phobic mul(const Phobic&) const;
	Phobic operator*(const Phobic&, const Phobic&);
   
	//Phobic div(const Phobic&) const;
	Phobic operator/(const Phobic&, const Phobic&);	
	
    
    void add_to(const Phobic&);
    void sub_from(const Phobic&);
    void mul_by(const Phobic&);
    void div_by(const Phobic&);
    
    */

    
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
    
    //void make_scary(int, int s2 = 13, int s3 = 13, int s4 = 13, int s5 = 13, int s6 = 13, int s7 = 13, int s8 = 13, int s9 = 13, int s10 = 13);

    //Phobic operator<< (int);

#endif /* PHOBIC_H_INCLUDED */
