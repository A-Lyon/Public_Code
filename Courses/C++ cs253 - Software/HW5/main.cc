
#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <cerrno>
#include <fstream>
#include <unistd.h>

using namespace std;


//testing a problem
/*  void cin(){
    cout << "a string.";       //ambiguous call to cin crashes
  }
*/

 //assign args to values using getopt()
 //       doc @ https://cs.colostate.edu/~cs253/man.php?getopt(3)
void import_args(int argc, char* argv[], long& lowBound, long& upBound, int& r, int& f, int& s, int& c, int& v, string& delim) {

    int opt;
    [[maybe_unused]]string input, range;
    
    while ((opt=getopt(argc,argv,"r:fsc:v"))!=-1){
        switch (opt) {
        case 'r':
            r++;
            input = optarg;
            range = input.substr(0, input.find('-'));
            lowBound = (stol(range));
            //cout << lowBound << '\n';
            range = input.substr(input.find('-')+1);
            upBound = (stol(range));
            //cout << upBound << '\n';
            break;
        case 'f':
            f++;
            break;
        case 's':
            s++;
            break;
        case 'c':
            c++;
            delim = optarg;
            break;
        case 'v':
            v++;
            break;
        default: 
            break;
        }
    }

    

      
      // old shit!
      // if (argc < 3){
      //   cerr << "Invalid number of arguments\n";
      //   exit(EXIT_FAILURE);
      // }
      
      // lowBound = strtol(argv[1], nullptr, 10);
      // upBound = strtol(argv[2], nullptr,10);
      
      // if(lowBound > upBound){
      //   cerr << "Invalid arguments for lower and upper range.\n";
      //   exit(EXIT_FAILURE);
      // }
      // range = upBound - lowBound + 1;

    }


    //populate count array
    void populate_count_from_stdin(long *arr, int &last, long &lowBound, long &upBound){
      //i = -19
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

      long d;
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
          cerr << "File " << filename << " holding improper values.";
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
  void print_count_array_commas(long arr[], long range, long &lowBound, int last, int cFlag, string& delimOpt){  
    int counter = 0;
    string delim = ",";

    if(cFlag > 0){
      delim = delimOpt;
    }

    for (int c=0; c<range; c++){
      int numm = arr[c];
      
      if (numm > 0){
       
         for (int e=0; e<numm; e++){
           counter++;
           //cout << "counter is \n" << counter;
           //cout << "last is \n" << last;
           if(counter < last){
              cout << c + lowBound << delim;  
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
    //cout << argc;
    long Range = 100;
    long lowBound = 0;
    long upBound = 99;
    const string PROGRAM_NAME = argv[0];
    [[maybe_unused]] string delim;
    [[maybe_unused]] int last = 0;
    [[maybe_unused]] int r = 0, f = 0, s = 0, c = 0, v = 0;

    import_args(argc, argv, lowBound, upBound, r, f, s, c, v, delim);
    
    if ((c > 0) && (s == 0)){
      cerr << "Program: " << PROGRAM_NAME << " operation terminated. -c given without implicit -s call." << '\n';
      exit(1);
    }

    //test args
    // cout << lowBound << '\n';
    // cout << upBound << '\n';
    // cout << delim << '\n';

    if (c > 1) {
      cerr << "Program: " << PROGRAM_NAME << " operation terminated. -c given twice." << '\n';
      exit(1);
    }


    if (r > 1) {
      cerr << "Program: " << PROGRAM_NAME << " operation terminated. -r given twice." << '\n';
      exit(1);
    }

    if (r == 1) {
        Range = upBound - lowBound;
    }

    long* arr = new long[Range];

    populate_count_from_stdin(arr, last, lowBound, upBound);
    



    if (f > 0) {
      print_count_array_X(arr, Range, lowBound);
    }
    if (s > 0){
      print_count_array_commas(arr, Range, lowBound, last, c, delim);
    }



    // if(argc > 3){
    //   for(int l = 3; l < argc; l++){
    //     string filename = argv[l];
    //     populate_count_from_file(arr, filename, last, lowBound, upBound);
    //   }
    // }

    // else {
    //   populate_count_from_stdin(arr, last, lowBound, upBound);
    // }
    
    //print_count_array_X(arr, range, lowBound);
    // print_count_array_commas(arr, range, lowBound, last);

    delete[] arr;
    return 0;
}
 
// end of main, make sure to build functions above.

