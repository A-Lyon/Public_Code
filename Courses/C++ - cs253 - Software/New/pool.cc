#include <iostream>

using namespace std;

class Foo {
  public:
    static void *operator new(size_t);
    static void operator delete(void *, size_t);
    double datum;
};

union Node {			// Not a class, not a struct: a union!
    Node *next;
    char pad[sizeof(Foo)];
};
static Node *freelist;

void *Foo::operator new(size_t) {
    if (freelist == nullptr) {				// Out of free nodes?
	constexpr int NODES_PER_PAGE = 8192/sizeof(Node);  // A bunch of them
	Node *n = new Node[NODES_PER_PAGE];		// Allocate many
	// Link all the new free nodes into the freelist
	freelist = n;
	for (int i=0; i<NODES_PER_PAGE-1; i++, n++)
	    n->next = n+1;
	n->next = nullptr;
    }
    void *result = freelist;	// Get the first node
    freelist = freelist->next;	// Remove it from the free list
    return result;
}

void Foo::operator delete(void *p, size_t) {
    if (!p) return;				// Pesky null pointer!
    // Return this node to the list of free nodes.
    Node *n = reinterpret_cast<Node *>(p);
    n->next = freelist;
    freelist = n;
}

int main() {
    cout << "sizeof(double) = " << sizeof(double) << '\n'
	 << "sizeof(Bar) = " << sizeof(Foo) << '\n';
    Foo *r = new Foo;
    Foo *s = new Foo;
    cout << "r=" << r << '\n'
	 << "s=" << s << '\n';
    delete r;
    delete s;

    for (int i = 0; i < 10000000; i++){
      Foo *r = new Foo();
      //cout << r;
    }    


    return 0;
}
