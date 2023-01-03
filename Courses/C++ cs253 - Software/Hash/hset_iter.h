#ifndef HSET_ITER_H_INCLUDED
#define HSET_ITER_H_INCLUDED

#include <list>
#include <vector>
#include <iterator>	// for advance()

// Each hset_iter contains a reference to its associated hash,
// and an int indicating progress within the hash.

template <typename T, int size = 5> //exercise 1
class hset_iter {
  private:
    using table_t = typename std::vector<std::list<T>>;
    const table_t& parent;  // reference to the hash table we’re iterating over
    int vector_i;		    // how far along we are.  0=first item

  public:
    hset_iter(table_t& table, int n) : parent(table), vector_i(n) { }

    bool operator==(const hset_iter& rhs) const {
	    return vector_i == rhs.vector_i;
    }

    bool operator!=(const hset_iter& rhs) const {
	    return !(*this == rhs);
    }

    // Return a pointer to the num'th element,
    // where num==0 is the first element.

    T operator*() const {
	    unsigned int remaining = vector_i;

    //int list_i = 0;
    int list_i = 0;
	
	// First, find the right list:
	for (list_i=0; parent[list_i].size() <= remaining; list_i++){
        remaining -= parent[list_i].size();
    }
	// Second, find the right slot within that list:
	auto it = parent[list_i].begin();
	advance(it, remaining);  // go forward that many steps
	return *it;
    }

    // Pre-increment
    void operator++() {
	 ++vector_i;
    }
};

#endif /* HSET_ITER_H_INCLUDED */
