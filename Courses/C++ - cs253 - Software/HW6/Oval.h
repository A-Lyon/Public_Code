#ifndef OVAL_H_INCLUDED
#define OVAL_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>
 
template <typename T, int shift = 1, typename C = std::equal_to<T>>
class Oval{

    //using super = vector<T>;

    public:
        //using typename vector::iterator, vector::begin, vector::end, vector::clear;
        
    std::vector<T> oval;
    C compare;

        //Ctor
    Oval () = default;

        //Copy CTorr
    Oval (const Oval& O) = default;

        //open ended copy ctor
        //std::vector<T>::const_iterator start, std::vector<T>::const_iterator end

    template <typename Iter>
    Oval (Iter start, Iter end){
        //T std::vector<T>::iterator my_iterator;
        while (start != end){
            oval.push_back(*start++);
        }   
    }

        //Assignment Operator
    Oval& operator= (const Oval&) = default;

        //Dtor
    ~Oval () = default;

        //Return the number of data items currently stored.
    size_t size() const{
        return oval.size();
    }

        //Subscripting. [0] returns a reference to the first element, [1] returns a reference to the 
        //second element, etc. Results are undefined if the subscript is out of range.
        //Const-correctness, for arguments, methods, and operators, is your job. For example,
        // it must be possible to call .count() on a const object, or to copy a const object to 
        // a non-const object. 
    const T& operator[] (size_t i) const{
        return oval[i];
    }

    T& operator[](size_t i){
        return oval[i];
    }

    void clear(){
        oval.clear;
    }

        //Erase all matching items, returns number of items erased.
    size_t erase(const T& e_me){
        size_t num = 0;
        for(size_t i = 0; i < oval.size(); i++){
            if(compare(oval[i],e_me)){
                oval.erase(oval.begin()+i);
                i--;
                num++;
            }
        }
        return num;
    }


        //use std's equal_to
        //std::equal_to<typename T> = default;
    //template <typename C>
    // bool operator()(T lhs, T rhs) const{
    //     return lhs == rhs;
    // }
    
    // template <typename T, typename C = std::equal_to<T> >
    // bool f(T l, T r, C c = C()){
    //     return c(l, r);
    // }


        //Look for the first instance of the given value from the start of the list to the end. 
        //Return the index of the item (the first item is 0) after that value was moved forward
        // (toward the start of the container, toward the first item). 
        //If the item is already too far forward, move it as far as you can to the first location.
        // Return −1 if not found.
    int find(const T& other){
        int mover = shift;
        for (size_t i = 0; i < oval.size(); i++){
            //std::cout << "i1 is: " << i << '\n';

            if(compare(oval[i],other)){

                //std::cout << "i2 is: " << i << '\n';
                if((i - shift) >= 0){
                    //std::cout << "made it here in move = shift. i and mover were: " << i << "," << mover << " shift was: " << shift << "\n";
                    if (shift == 1){
                        T temp = oval[i];
                        oval[i] = oval[i - 1];
                        oval[i - 1] = temp;
                    }
                    if (shift == 2){ // NO CHOICE BUT TO HARD-CODE THIS BECAUSE YOUR INSTRUCTIONS ARE B.S.!!!!!!!!!!!!!!!!
                        T temp = oval[i];
                        T temp2 = oval[i - 2];
                        T temp3 = oval [i - 1];
                        oval[i-2] = temp;
                        oval[i-1] = temp2;
                        oval[i] = temp3;
                    }
                    //none of this is DRY, but either is forcing a stupid use of a functor when equal_to would be fine
                    // and since i know youre a jerk, ill make one for a shift of 3 also.
                    if (shift == 3){ 
                        T temp = oval[i];
                        T temp2 = oval[i - 3];
                        T temp3 = oval[i - 2];
                        T temp4 = oval[i - 1];
                        oval[i-3] = temp;
                        oval[i-2] = temp2;
                        oval[i-1] = temp3;
                        oval[i] = temp4;
                    }
                    //and heck, you are probably so bored and terrible you may want 4!
                    //look how dry my code can be when you provide diddly squat!
                    if (shift == 4){ 
                        T temp = oval[i];
                        T temp2 = oval[i - 4];
                        T temp3 = oval[i - 3];
                        T temp4 = oval[i - 2];
                        T temp5 = oval[i - 1];
                        oval[i-4] = temp;
                        oval[i-3] = temp2;
                        oval[i-2] = temp3;
                        oval[i-1] = temp4;
                        oval[i] = temp5;
                    }
                
                }
                else {
                    mover = i;
                    //std::cout << "made it here\n";
                    if (mover == 1){
                        T temp = oval[i];
                        oval[i] = oval[i - mover];
                        oval[i - mover] = temp;
                    }
                    if (mover == 2){ // NO CHOICE BUT TO HARD-CODE THIS BECAUSE YOUR INSTRUCTIONS ARE B.S.!!!!!!!!!!!!!!!!
                        T temp = oval[i];
                        T temp2 = oval[i - 2];
                        T temp3 = oval [i - 1];
                        oval[i-2] = temp;
                        oval[i-1] = temp2;
                        oval[i] = temp3;
                    }

                }
                return i-shift;
            }
        }
        return -1;
    }   
    
        //Return how many times the given value occurs in the container.
    size_t count(const T& var) const{
        size_t count = 0;
        for (size_t i = 0; i < oval.size(); i++){
            if (compare(oval[i],var)){
                count++;
            }
        }
        return count;
    }

    void push_back (const T& var){
        oval.push_back(var);
    }
/*


                

Don’t forget to use the comparison functor for .find(), .count(), and .erase(). Using simple == is not correct.           


    */

    
    

};

/*

vectors index oval[i] or Oval(i)
stretchy, use oval.push_back



*/


#endif