#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED

#include <dirent.h>
#include <string>

// Normally, I’d have DirectoryIterator be a nested class, Directory::iterator,
// to avoid namespace pollution.  However, this is easier to read.

//iterates through data
class DirectoryIterator {
  public:
    DirectoryIterator() = default; //no defined constructor, takes in 
    DirectoryIterator(DIR *);    //second constructor, takes in a DIR*
    DirectoryIterator(DIR *, std::string theMatch = "");    //third constructor, (std::string toMatch = "") takes in a DIR* and a string
    DirectoryIterator& operator++();
    //DirectoryIterator& operator++(string);
    std::string operator*() const;
    bool operator!=(const DirectoryIterator &) const;    //didnt define == since we dont need it for for loop
  private:
    bool wanted() const;
    DIR *dp = nullptr;    //end iterator, sets dp to null, this brings the end/
                        // to compare ends, compare dp
    std::string name;
    std::string toMatch;
};

//contains data
class Directory {
  public:
    typedef DirectoryIterator iterator;
    Directory() = delete;		// not really necessary
    Directory(const char dirname[]);

    //Fix 3, also impossible to do with the material provided. This class is not teaching c++, it is just confusing and frustrating.
    Directory(const char dirname[], std::string theMatch);
    ~Directory();
    iterator begin() const; //does most of the work
    iterator end() const;  //does most of the work
  private:
    DIR* dp;				// null if open failed
    std::string toMatch;
};

#endif /* DIRECTORY_H_INCLUDED */
