#ifndef COUNTSORT_H_INCLUDED
#define COUNTSORT_H_INCLUDED

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cassert>

//template <typename T>
class CountSort{

    private:

    int size_container;
    int num_elements;
    int upper;
    int lower;
    int* location;
    std::vector<int> container;
    
    public:

    //ctor
    CountSort(int a, int b);

    //ctor with initializer_list
    //CountSort& operator= (std::initializer_list<int> nums);
    CountSort& operator= (std::initializer_list<int> nums){
        for(auto num: nums){
            this->insert(num);
        }
        return *this;
    }



    //dtor
    ~CountSort();
    
    //methods
    int size();
    int width();
    bool empty();
    void insert(int n);
    int min();
    int max();
    void clear();
    int get(int n);

    // //iterator initialization
    // class iterator;
    // // iterator methods
    // class iterator{
        
    //     public:
    //         int i;
    //         std::vector<int>& v;
            
    //         iterator(CountSort* location);
    //         int operator*();
    //         iterator& operator++();
    //         iterator operator++(int num);
    //         
    //         bool operator==(const CountSort::iterator& rhs);
    //         bool operator!=(const CountSort::iterator& rhs);

    // };
    
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();
    

};










#endif 