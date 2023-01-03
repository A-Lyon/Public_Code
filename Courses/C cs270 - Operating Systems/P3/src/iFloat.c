#include "Debug.h"
#include "iFloat.h"

/** @file iFloat.c
 *  @brief You will modify this file and implement nine functions
 *  @details Your implementation of the functions defined in iFloat.h.
 *  You may add other function if you find it helpful. Added function
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file.
 *  <p>
 *  @author <b>Your name</b> goes here
 */

/* declaration for useful function contained in testFloat.c */
const char* getBinary (iFloat_t value);

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetSign (iFloat_t x) {
  return ((x >> 15) & 0x0001);               // return shift 15 to isolate first bit
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetExp (iFloat_t x) {
  return ((x & 0x7C00) >> 10);         // return bits 10-14
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatGetVal (iFloat_t x) {
  int sign = floatGetSign(x);
  int fraction = ((x | 0x0400) & 0x07FF);
  if(!sign){                         // return number if positive
    return fraction;
  }
  return (~fraction + 1);            // return twos comp if it was negative
}

/** @todo Implement based on documentation contained in iFloat.h */
void floatGetAll(iFloat_t x, iFloat_t* sign, iFloat_t*exp, iFloat_t* val) {
  *sign = floatGetSign(x);
  *exp = floatGetExp(x);
  *val = floatGetVal(x); 
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatLeftMost1 (iFloat_t bits) {
for(int i = 15; i >= 0; i--){
   int bitVal = (bits & (1 << i)) != 0;
   if(bitVal == 1){
       return i;
   }
}
return -1;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAbs (iFloat_t x) {
  return (x & 0x7FFF);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatNegate (iFloat_t x) {
  if (x == 0){
    return 0;
  }
  return (x ^ 0x8000);
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatAdd (iFloat_t x, iFloat_t y) {
  debug("%s: bits of x (IEEE 754)", getBinary(x)); // example only
  debug("%s: bits of y (IEEE 754)", getBinary(y)); // example only
  
  
  if( ( x == 0 ) || ( y == 0) ){       // handle zero cases , might need to rewrite to 
    if ( x != 0 ) return x;
    if ( y != 0 ) return y;
    else return 0;
    }
      
                                        // extract values, sign, exponents
  iFloat_t signX, expX, valX;
  floatGetAll(x, &signX, &expX, &valX);
  
  iFloat_t signY, expY, valY;
  floatGetAll(y, &signY, &expY, &valY);
  
                                        //equalize exponents                                     
                                        
  if ( expX > expY ){
    int difference = expX - expY;
    expY += difference;
    valY = valY >> difference;
    
  }
  else if( expX < expY ){
    int difference = expY - expX;
    expX += difference;
    valX = valX >> difference;
  }
  //iFloat_t signR, expR, valR;
  //valR = valX + valY;
  //signR = floatGetSign(valR);
  //floatGetAll(r, &signR, &expR, &valR);
  
  iFloat_t expR = expY;
  iFloat_t valR = valX + valY;
  iFloat_t signR = floatGetSign(valR);
  
                                          // Step 4, 2's xomp if neg
  iFloat_t magR = valR;
  if(signR == 1){                        //negative number needs 2's comp
    magR = ~valR + 1;           //2's comp
  }
                                        //Step 5, Normalize result
   int shift =  floatLeftMost1( magR );   
                                          
   if( shift < 10){        //shift left
   shift = 10 - shift;
   magR = magR << shift;
   expR -= shift;    
   }
    else if( shift > 10 ){   //shift right
    shift = shift - 10;
    magR = magR >> shift;
    expR += shift;
    }
    
                                  // Step 6 re-assemble
    magR = (magR ^ 0x0400);        //remove explicit 1
    iFloat_t result = ((signR << (BITS - 1)) | (expR << 10) | (magR));
  
  return result;
}

/** @todo Implement based on documentation contained in iFloat.h */
iFloat_t floatSub (iFloat_t x, iFloat_t y) {
  return floatAdd(x, floatNegate (y));
}

