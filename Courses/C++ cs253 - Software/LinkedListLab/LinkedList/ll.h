#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
  public:
    void initialize();
    bool insert(unsigned uiData);
    bool remove(unsigned *pData);

  private:
    struct Link {
	    unsigned m_uiData;
	    Link* m_pNext;
	    void initialize(unsigned uiData, Link *pNext);
      } * m_pHead;
};

#endif /* LINKED_LIST_H */ 
