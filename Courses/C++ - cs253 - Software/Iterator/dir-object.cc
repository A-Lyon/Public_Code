#include <iostream>
#include "Directory.h"

using std::cout;

int main() {
    

    const char* dirname = ".";
    Directory dir(dirname);
    
    for (auto name : dir)
	    cout << "Filename: " << name << '\n';


    
    Directory ddt(dirname, "il");
    
    for (auto name : ddt)
	    cout << "Filename: " << name << '\n';    
    

}
