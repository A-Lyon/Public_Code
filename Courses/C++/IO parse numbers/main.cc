#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <cerrno>
#include <fstream>

using namespace std;


 //assign args to values
    void import_args(int argc, char *argv[], long &lowBound, long &upBound, long &range){
      if (argc < 3){
        cerr << "Invalid number of arguments\n";
        exit(EXIT_FAILURE);
      }
      
      lowBound = strtol(argv[1], nullptr, 10);
      upBound = strtol(argv[2], nullptr,10);
      
      if(lowBound > upBound){
        cerr << "Invalid arguments for lower and upper range.\n";
        exit(EXIT_FAILURE);
      }
      range = upBound - lowBound + 1;

    }


    //populate count array
    void populate_count_from_stdin(long *arr, int &last, long &lowBound, long &upBound){
      
      long i;
      while (cin >> i){
        if(i < lowBound || i > upBound){
        cerr << "Error, value needs to be within range.\n"; 
        exit(EXIT_FAILURE);
        }  
        else {
        arr[i - lowBound] = arr[i - lowBound] + 1; 
        last++;
        }
      }
    } 

    void populate_count_from_file(long *arr, string &filename, int &last, long &lowBound, long &upBound){
      //i = -19
      ifstream in(filename);

      //error checking
      if(!in) {
          cerr << "Cannot open file: " << filename;
          exit(EXIT_FAILURE);
      }

      double d;
      while (in >> d){
        if(d < lowBound || d > upBound){
        cerr << d << " is not a value in the range of." << lowBound << " to " << upBound << "\n"; 
        exit(EXIT_FAILURE);
        }  
        else {
        arr[d - lowBound] = arr[d - lowBound] + 1; 
        last++;
        }
      }   

      if(!in.eof()){
          cerr << "File " << filename << " holding improper values."
      }

    } 
    
    //print count array in #x# 
    void print_count_array_X(long arr[], long range, long &lowBound){
    for (int b=0; b < range; b++){
       int num = arr[b];
       
       if (num > 0){
         cout << b + lowBound << "x" << num << " ";
       }
    }
    cout << "\n";
  }
    //print count array full with commas
    
    //cout << "last is: " << last;
  void print_count_array_commas(long arr[], long range, long &lowBound, int last){  
    int counter = 0;
    for (int c=0; c<range; c++){
      int numm = arr[c];
      
      if (numm > 0){
       
         for (int e=0; e<numm; e++){
           counter++;
           //cout << "counter is \n" << counter;
           //cout << "last is \n" << last;
           if(counter < last){
              cout << c + lowBound << ",";  
            }
            else {
              cout << c + lowBound;
            }         
         }  
      }
    }
    cout << "\n";
  } 

int main(int argc, char *argv[]) {
    //get variables

    long range;
    long lowBound;
    long upBound;
    string program_name = argv[0];
    int last = 0;

    import_args(argc, argv, lowBound, upBound, range);
    long* arr = new long[range]; 

    if(argc > 3){
      for(int l = 3; l < argc; l++){
        string filename = argv[l];
        populate_count_from_file(arr, filename, last, lowBound, upBound);
      }
    }

    else {
      populate_count_from_stdin(arr, last, lowBound, upBound);
    }
    
    print_count_array_X(arr, range, lowBound);
    print_count_array_commas(arr, range, lowBound, last);

    delete[] arr;
    return 0;
}
 
// end of main, make sure to build functions above.

