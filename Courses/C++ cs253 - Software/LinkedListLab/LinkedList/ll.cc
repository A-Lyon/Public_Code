#include "ll.h" 
#include <cstdlib>

void LinkedList::Link::initialize(unsigned uiData, Link *pNext) {
    m_uiData = uiData;
    m_pNext = pNext;
}

void LinkedList::initialize() {
    m_pHead = nullptr;			// This linked list is empty.
}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link;			// Get a new node.

    new_link->initialize(uiData, this->m_pHead); // Fill it with data.
    m_pHead = new_link;			// Put it at the head.

    return true;				// Indicate success.
}

bool LinkedList::remove(unsigned *pData) {
    if (!m_pHead)				// Empty list?
	return false;				// Indicate failure.

    Link *temp = m_pHead;			// Point to the first node.
    m_pHead = m_pHead->m_pNext;	// Remove the first node.
    *pData = temp->m_uiData;			// Obtain first node’s data.
    delete temp;
    return true;				// Indicate success.
}
