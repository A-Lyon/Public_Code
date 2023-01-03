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
    [[nodiscard]] int get() const;
    [[nodiscard]] bool is_scary (int);

    // Variables
	std::set<int> fears = {13};

    

    //Operators
     Phobic& operator+=(const Phobic&);
     Phobic& operator-=(const Phobic&);
     Phobic& operator*=(const Phobic&);
     Phobic& operator/=(const Phobic&);



    //Main method for make_scary replacement, pass int? return Phobic object or void?
    Phobic& operator<< (int);
    		
private:
    int scardy;  
     
    };

    //Free Functions for operators like complex.cc

	//Phobic add(const Phobic&) const;	    
	[[nodiscard]] Phobic operator+(const Phobic&, const Phobic&);
    [[nodiscard]] Phobic operator-(const Phobic&, const Phobic&);
    [[nodiscard]] Phobic operator*(const Phobic&, const Phobic&);
    [[nodiscard]] Phobic operator/(const Phobic&, const Phobic&);

    //Equality Operators
    [[nodiscard]] bool operator==(const Phobic&, const Phobic&);
    [[nodiscard]] bool operator!=(const Phobic&, const Phobic&);
    [[nodiscard]] bool operator<(const Phobic&, const Phobic&);
    [[nodiscard]] bool operator<=(const Phobic&, const Phobic&);
    [[nodiscard]] bool operator>(const Phobic&, const Phobic&);
    [[nodiscard]] bool operator>=(const Phobic&, const Phobic&);


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

    

#endif /* PHOBIC_H_INCLUDED */
