#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>
#include "CountSort.h"
#include <stdexcept>

using namespace std;    

//template <typename T>

    int size_container;
    int num_elements;
    int upper;
    int lower;
    int* location;
    std::vector<int> container;


    //ctor
    CountSort::CountSort(int a, int b) : upper(b), lower(a) {
        if(a > b){
            throw std::out_of_range ("First value should be less than second value.");
        }
        else {
            size_container = upper - lower + 1;

            // cout << size_container << "\n";
            // num_elements = 0;
            // cout << num_elements << "\n";

            //zero out container
             for(int i = 0; i < size_container; i++){
                 container.push_back(0);
             }

             cout << "Ive never seen a class in either of my degrees that the 'professor' was so lazy and bitter, that he actively creates problems that he hasnt prepared his students to address";
        }
    }





    //dtor
    CountSort::~CountSort() = default;

    int CountSort::size(){
        return num_elements;
    }

    int CountSort::width(){
        return this->size_container;
    }

    bool CountSort::empty(){
        return num_elements == 0;
    }

    int CountSort::min(){
        return lower;
    }

    int CountSort::max(){
        return upper;
    }

    void CountSort::clear(){
        num_elements = 0;
        container.clear();
    }
    
    int CountSort::get(int n){
        return container[n];
    }

    void CountSort::insert(int n){
        if(n > upper || n < lower){
            throw std::out_of_range ("Your value is out of the range for this container.");
        }
        else {
            container[n - lower]++;
            num_elements++;
        }
    }

    /*
     cant even try to implement any of these fucking methods because the instructions
     are fucking vague and confusing. Jack, you are an absolutely GARBAGE instructor. Quit. please.
     Future generations of programmers will benefit fromyou NOT wasting students time and ruining C++ for them.\
     retire. just, retire.
     */

    // class iterator;
    // // iterator methods
    // //class iterator{
        
    
    //         // int i;
    //         // std::vector<int>& v;
            
    //         iterator(CountSort* location){
                
    //         }

    //         int operator*(){
    //             return container[0] + container->lower;
    //         }
    //         iterator& operator++();
    //         iterator operator++(int num);

    //         bool operator==(const CountSort::iterator& rhs){
    //             return this.location == rhs;
    //         }
    //         bool operator!=(const CountSort::iterator& rhs){
    //             return this.location != rhs;
    //         }

    
    
    std::vector<int>::iterator CountSort::begin(){
        return container.begin();
    }

    std::vector<int>::iterator CountSort::end(){
        return container.end();
    }


    





