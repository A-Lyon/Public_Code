#include "field.h"
#include <stdio.h>
/** @file field.c
 *  @brief You will modify this file and implement five functions
 *  @details Your implementation of the functions defined in field.h.
 *  You may add other function if you find it helpful. 
 * <p>
 * @author <b>Your name</b> goes here
 */

/** @todo Implement in field.c based on documentation contained in field.h */
int getBit (int value, int position) {
    return ((value >> position) & 1);
}

//use or to change a 0 at position into a 1, return new number
/** @todo Implement in field.c based on documentation contained in field.h */
int setBit (int value, int position) {
    int mask = 1 << position;
    return (value | mask);
}

// we need to set the bit at position to zer0, and return the number after
/** @todo Implement in field.c based on documentation contained in field.h */
int clearBit (int value, int position) {
    int mask = 1; 
    mask = ~(mask << position);
    return value & mask;
}

/** @todo Implement in field.c based on documentation contained in field.h */
// keeping whatever bits are between (including) high and lo; which equals high-low+1 with indexing.


int getField (int value, int hi, int lo, bool isSigned) {
    int shift = hi - lo + 1;
    int mask = ((1 << (shift)) - 1);
    int temp = (value >> lo) & mask;
    if(isSigned & (getBit(value,hi) == 1)){
      return ((~temp) + 1);
    }
    else return temp;
}
