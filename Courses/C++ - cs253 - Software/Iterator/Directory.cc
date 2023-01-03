#include "Directory.h"
#include <iostream>

using namespace std;

// The directory iterator pre-fetches the name.  That is, readdir()
// is called when you first create the iterator, and upon ++.
//
// An end() iterator is designated by a null pointer for its DIR *.
// When readdir() fails, we set our pointer to null.

//makes copy of dp iterator
//++*this, increments the pointer, calls readdir
DirectoryIterator::DirectoryIterator(DIR *dp_arg) : dp(dp_arg) {

    //cout << "iterating past: " << dp_arg << "\n";
    
    ++*this;				// get that first entry
}

DirectoryIterator::DirectoryIterator(DIR *dp_arg, std::string theMatch) : dp(dp_arg) {

    //cout << "iterating past: " << dp_arg << "\n";
    toMatch = theMatch;
    ++*this;				// get that first entry
}

// Get the next entry in the directory (that we like) and
// put it in the member variable name.
//puts directory* in p
DirectoryIterator &DirectoryIterator::operator++() {	// pre-increment
    while (auto p = readdir(dp)) {	// Read a directory entry.
	name = p->d_name;		// C-string ⇒ C++ string
    
    //Fix#2 that doesnt work and is impossible to implement without cheating (like most of Jacks students are). The slides no not have enough information to implement this.
    if(wanted()){
         continue;
    }

	// if (name == ".")		// Stupid entry for current directory?
	//     continue;			// Nobody wants that.
	// if (name == "..")		// Stupid entry for parent directory?
	//     continue;			// Nobody wants that.
	return *this;			// Everything else, I like!
    }

    dp = nullptr;			// readdir failed; don’t try again.
    
    //cout << "Made it here. \n";
    
    return *this;

}

// DirectoryIterator &DirectoryIterator::operator++(string toMatch) {	// pre-increment
//     while (auto p = readdir(dp)) {	// Read a directory entry.
// 	name = p->d_name;		// C-string ⇒ C++ string
    
//     if(!wanted()){
//          continue;
//         }
// 	return *this;			// Everything else, I like!
//     }

//     dp = nullptr;			// readdir failed; don’t try again.  
//     return *this;

// }

//Fix #2 that is pointless and doesnt follow any of the slides in class, also the instructions saying .wanted() were extremely misleading. This kind of crap is counterproductive and demoralizing.
bool DirectoryIterator:: wanted() const{
    if((this->name == "." || this->name == "..")){
        return true;
    }
    if(name.find(toMatch) == std::string::npos){
        return true;
    }
    return false;
}

string DirectoryIterator::operator*() const {
    return name;			// Fetched in a previous ++.  doesnt advance iterator
                            // just gets what is at the location
}

bool DirectoryIterator::operator!=(const DirectoryIterator &rhs) const {
    return dp != rhs.dp;
}



////              Directory methods
// ctor takes in argument, calls opendir() 

Directory::Directory(const char dirname[]) : dp(opendir(dirname)) { 
    
    //cout << "ctor was called on: " << dp << "\n";
    try{
    //Fix #1
        if(dp == nullptr){
            throw std::runtime_error(dirname);
        }
    }
    catch(std::runtime_error& error){
        cerr << "Runtime error, " << error.what() << " is not a valid directory.\n";
    } 
}

    //Fix #3
Directory::Directory(const char dirname[], std::string theMatch) : dp(opendir(dirname)) { 
    //cout << toMatch << "\n";
    toMatch = theMatch;
    try{
    //Fix #1
        if(dp == nullptr){
            throw std::runtime_error(dirname);
        }
        
    }
    catch(std::runtime_error& error){
        cout << "Runtime error, " << error.what() << " is not a valid directory.\n";
    } 
}

Directory::~Directory() {
    if (dp)				// Only if opendir() succeeded:

    //cout << dp << " dtor was called. \n";

	closedir(dp);			//   should we close it. only closes if its open
}

Directory::iterator Directory::begin() const {
    return iterator(dp, this->toMatch); //iterator is alias for DirectoryIterator
}

//notice this method doesnt pass argument
Directory::iterator Directory::end() const {
    return iterator();
}
