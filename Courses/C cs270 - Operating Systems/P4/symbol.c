#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Debug.h"
#include "symbol.h"

/** @file symbol.c
 *  @brief You will modify this file and implement the symbol.h interface
 *  @details Your implementation of the functions defined in symbol.h.
 *  You may add other functions if you find it helpful. Added functions
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. The reference implementation added approximately
 *  110 lines of code to this file. This count includes lines containing
 *  only a single closing bracket (}).
 * <p>
 * @author <b>Your name</b> goes here
 */

/** size of LC3 memory */
#define LC3_MEMORY_SIZE  (1 << 16)

/** Provide prototype for strdup() */
char *strdup(const char *s);

/** defines data structure used to store nodes in hash table */
typedef struct node {
  struct node* next;     /**< linked list of symbols at same index */
  int          hash;     /**< hash value - makes searching faster  */
  symbol_t     symbol;   /**< the data the user is interested in   */
} node_t;

/** defines the data structure for the hash table */
struct sym_table {
  int      capacity;    /**< length of hast_table array                  */
  int      size;        /**< number of symbols (may exceed capacity)     */
  node_t** hash_table;  /**< array of head of linked list for this index */
  char**   addr_table;  /**< look up symbols by addr                     */
};

/** djb hash - found at http://www.cse.yorku.ca/~oz/hash.html
 * tolower() call to make case insensitive.
 */

static int symbol_hash (const char* name) {
  unsigned char* str  = (unsigned char*) name;
  unsigned long  hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

  c = hash & 0x7FFFFFFF; /* keep 31 bits - avoid negative values */

  return c;
}

/** @todo implement this function */
sym_table_t* symbol_init (int capacity) {
  
  sym_table_t* t = (sym_table_t*) malloc(sizeof(sym_table_t));
  
  // set initial capacity
  t -> capacity = capacity;
  t -> size = 0;
  char **u = (char**) calloc(65535, sizeof(node_t*));  //2^16 from symTab.html
  t -> addr_table = u;
  node_t** n = (node_t**) calloc(capacity, sizeof(node_t*)); 
  t -> hash_table = n;
  return t;
  
}

/** @todo implement this function */

/** Remove all symbols from the symbol table, and free all allocated memory.
 *  This function is a destructor for a symbol table.
 *  There must not be any memory leaks. After executing this function, the
 *  opaque pointer to the symbol table is no longer valid.
 */

void symbol_term (sym_table_t* symTab) {
      symbol_reset(symTab);
      
      //free hash table
      free(symTab->hash_table);
      symTab->hash_table = NULL;

      //free address table
      free(symTab-> addr_table);
      symTab->addr_table = NULL;
      
      //free symTab
      free(symTab);
      symTab = NULL;
}

/** @todo implement this function */

/** Remove all the symbols from the symbol table. After this call the opaque
 *  symbol table pointer is still valid and new symbols may be added to it. 
 *  If needed, clear the <code>addr_table</code>.
 *  @param symTab - pointer to the symbol table
 */

void symbol_reset(sym_table_t* symTab) {

  for(int i = 0; i < symTab->capacity; i++){
      if(symTab->hash_table[i] == NULL){
        continue;
      }
      else if ((symTab->hash_table[i] != NULL) && (symTab->hash_table[i]->next != NULL)) {
        node_t* n = symTab->hash_table[i];
        node_t* next;
          while(n != NULL){
            next = n->next;
            free(n->symbol.name);
            n->symbol.name = NULL;
            free(n);
            n = next;
          }
      symTab->hash_table[i] = NULL;
      }
      else {
        free(symTab->hash_table[i]->symbol.name);
        symTab->hash_table[i]->symbol.name = NULL;
        free(symTab->hash_table[i]);
        symTab->hash_table[i] = NULL;
      }
      symTab->size = 0;
  }
}

/** @todo implement this function */
int symbol_add (sym_table_t* symTab, const char* name, int addr) {
  int index = symbol_hash(name) % symTab -> capacity;
    int hash = symbol_hash(name);
    
    //add to empty table
    if(symTab -> hash_table[index] == NULL){
      node_t* newnode = (node_t*) malloc(sizeof (node_t));
      char* sym = strdup(name);
      newnode -> symbol.name = sym;
      newnode -> symbol.addr = addr;
      newnode -> next = NULL;
      newnode -> hash = symbol_hash(name);
      symTab -> hash_table[index] = newnode;
      symTab -> size++;
      symTab -> addr_table[addr] = sym;    //addr or sym??
      return 1;
    }
    //add node to head and beyond
    else{
      //check if element exists in table
      if(symbol_search(symTab, name, &hash, &index) == NULL){
        // check index bounds
        if(symTab -> capacity > index){
          node_t* newnode = (node_t*) malloc(sizeof(node_t));
          char* sym = strdup(name);
          newnode -> symbol.name = sym;
          newnode -> symbol.addr = addr;
          newnode -> next = symTab -> hash_table[index];
          newnode -> hash = symbol_hash(name);
          symTab -> hash_table[index] = newnode;
          symTab -> size++;
          symTab -> addr_table[addr] = sym;
          return 1;
        }
      }
      //table contains element already return 0
      else{
        return 0;
      }
    }
    
    //add fails return 0
    return 0;
}

/** @todo implement this function */

/** This function is only used internally and should be declared static. It is
 *  a useful support function for the <code>add()/find()</code> functions.
 *  It is declared here for documentation purposes. The function returns
 *  <b>three</b> values: one in the return value, and the other two using
 *  the pointers to the hash and index values.
 *  @param symTab - pointer to the symbol table
 *  @param name - the name of the symbol
 *  @param hash - pointer to location where hash value will be stored 
 *  @param index - pointer to location where index will be stored 
 *  @return  the nodes information or NULL if no symbol is associated with
 *   the name.
 */

struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index) {
  *hash = symbol_hash(name);
  *index = *hash % (symTab->capacity);
      if(symTab->hash_table[*index] == NULL){
         return NULL;
      }
      
    for(int i = 0; i <symTab->capacity; i++){
      node_t* n = symTab->hash_table[i];
      while(n != NULL){
         int result = strcasecmp(name, n->symbol.name);  //compare with strcasecomp
            if(result == 0){
             return n;
            }
            else{
              n = n->next;
            }
      }

     }
      return NULL;
}

/** @todo implement this function */

/** Find a symbol by its name
 *  @param symTab - pointer to the symbol table
 *  @param name - the symbols name
 *  @return  the symbols information or NULL if no symbol is associated with
 *   the name.
 *  Most of the work is done by <code>symbol_search()</code>. That routine
 *  returns a <code>node_t*</code>, but this routine returns a 
 *  <code>symbol_t*</code>. Study
 *  <a href="http://stackoverflow.com/questions/5767973/getting-the-address-of-a-struct-member">this</a> posting to understand how you might solve this.
 */

symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name) {
  int hash = symbol_hash(name);
  int index = hash % symTab->capacity;
  
  node_t* n = symbol_search(symTab, name, &hash, &index);
  hash = n->hash;
  return &(symTab->hash_table[index]->symbol);
}

/** @todo implement this function */

/** Find a name by its LC3 address, use must use the addr_table to perform
 *  the lookup.
 *  @param symTab - pointer to the symbol table
 *  @param addr - an LC3 address
 *  @return the <b>label</b> at that address or NULL if no symbol is
 *  associated with the adddress. 
 */

char* symbol_find_by_addr (sym_table_t* symTab, int addr) {
  if (symTab->addr_table[addr] == NULL)
  return NULL;
  else{
  return symTab->addr_table[addr];
  }
  return NULL;
}


/** @todo implement this function */

/** This function calls the function for every entry in the symbol table.
 *  The assigment will define the order in which the entries should be visited.
 *  @param symTab - pointer to the symbol table
 *  @param fnc - the function to be called on every element
 *  @param data - any additional information to be passed on to fnc. The called
 *  function will cast this to whatever type was actually passed.
 */

void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data) {
    if(symTab->capacity == 1){
        node_t* n = symTab->hash_table[0];
            while(n != NULL){
                (*fnc)(&(n->symbol),data);
                if(n->next == NULL){
                    break;
                }
                else {
                    n = n->next;
                }
            }
    }
    else {
       for(int i = 0; i < symTab->capacity; i++){
          node_t* n = symTab->hash_table[i];  
          while(n != NULL){
             (*fnc)(&(n->symbol),data);
             if(n->next == NULL){
                 break;
             }
             else {
                n = n->next;
             }
          }
        }
    }

}

/** @todo implement this function */

/** Return the number of elements currently in the symbol table
 *  @param symTab - pointer to the symbol table
 *  @return number of elements
 */
int symbol_size (sym_table_t* symTab) {
  return symTab -> size;
}

/** @todo implement this function */

/** A callback function for <code>qsort</code> to order by name in a case
 *  insensative way.
 *  @param vp1 pointer to first element
 *  @param vp2 pointer to second element
 *  @ return a number representing the correct ordering (neg, 0, pos)
 */
int compare_names (const void* vp1, const void* vp2) {
   symbol_t* sym1 = *((symbol_t**) vp1);
   symbol_t* sym2 = *((symbol_t**) vp2);
   
   char* a = (sym1->name);
   char* b = (sym2->name);
   
   return strcasecmp(a, b);
    
}

/** @todo implement this function */

/** A callback function for <code>qsort</code> to order by address
 *  <b>NOTE</b>: If two elements have the same address, then return the result
 *  of comparing by name, so that name becomes the secondary sort key.
 *  @param vp1 pointer to first element
 *  @param vp2 pointer to second element
 *  @ return a number representing the correct ordering (neg, 0, pos)
 */
int compare_addresses (const void* vp1, const void* vp2) {
  symbol_t* sym1 = *((symbol_t**) vp1); // study qsort to understand this
  symbol_t* sym2 = *((symbol_t**) vp2);
  int a = (sym1->addr) - (sym2->addr);
  
  if(a != 0){
    return a;
  }
  else { 
    return compare_names(&sym1, &sym2);
  }
}

/** @todo implement this function */

/** This function returns an ordered, dymanically allocated array of
 *  <code>symbol_t*</code>. You may wish to use <code>qsort()</code> to order
 *  it. The caller will <code>free()</code> the return value.
 *  For order HASH: the order is the order of the hash table.
 *  For order NAME: the order is alphabetical by name.
 *  For order ADDR: the order is smallest to largest address.
 *  @param symTab - pointer to the symbol table
 *  @param order - defines the sorting order for the list (HASH, NAME, ADDR)
 *  @return pointer to an array of <code>symbol_t*</code>  
 */ 
symbol_t** symbol_order (sym_table_t* symTab, int order) {
  // will call qsort with either compare_names or compare_addresses
    symbol_t** s = (symbol_t**)calloc(symTab->size, sizeof(symbol_t*));
    int j = 0;

    for(int i = 0; i < symTab->capacity; i++){
        node_t* n = symTab->hash_table[i];
       if(symTab->hash_table[i] == NULL){
           continue;
        }
       else {  
          while(n != NULL){
             s[j] = &(n->symbol);
             j += 1;
             if(n->next == NULL){
                 break;
             }
             else {
                n = n->next;
             }
          }
        }
   }
   
    if(order == 0 && s[0] != NULL){
      return s;
    }
    else if(order == 1 && s[0] != NULL){
      qsort(s, symTab->size, sizeof(symbol_t*), compare_names);
      return s;
    }
    else if(order == 2 && s[0] != NULL){
      qsort(s, symTab->size, sizeof(symbol_t*), compare_addresses);
      return s;
    }
    else
      return NULL;

return NULL;
}

