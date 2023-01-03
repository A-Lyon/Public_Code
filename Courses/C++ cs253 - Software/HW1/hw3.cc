#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <cerrno>

using namespace std;


int main(int, char *argv[]) {
    //get variables
    string name = argv[0];
    int arr[100] = {0};
    int i;
    int last = 0;
    int counter = 0;


    //populate count array
    while (cin >> i){
      if(i<0 || i>99){
        cerr << name << ": Error, value needs to be between 0 and 99.\n"; 
        return 1;
      }  
      else {
        arr[i] = arr[i] + 1; 
        last++;
      }
    } 
    
    //print count array in #x# 
    for (int b=0; b < 100; b++){
       int num = arr[b];
       
       if (num > 0){
         cout << b << "x" << num << " ";
       }
    }
    cout << "\n";
    
    //print count array full with commas
    
    //cout << "last is: " << last;
    
    for (int c=0; c<100; c++){
      int numm = arr[c];
      
      if (numm > 0){
       
         for (int e=0; e<numm; e++){
           counter++;
           if(counter < last){
              cout << c << ",";  
            }
            else {
              cout << c;
            }         
         }  
      }
    }
    cout << "\n";
    
          
    return 0;

}
