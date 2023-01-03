/**
 *  @author  Andrew Lyon
 *  alyon@colostate.edu
 *  5/23/2021
 */

#include <stdio.h>

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 *
 * compile: gcc -std=c11 -g -Wall numconv.c testConv.c -o testConv
 * test i2c: ./testConv i2c 2 6
 * test c2i: ./testConv c2i 2 6
 * test ascii2int: echo "ABCD" | ./testConv a2i 16
 * test int2ascii: ./testConv i2a 16 51170
 * 
 */
char int2char (int radix, int value) {
 
 //check bounds
 if((radix < 2) | (radix > 36) | (value >= radix)) return '?'; 
 if(value < 10){
    return value + 48;
 }
 if(value > 9){

    return value + 55;
 }
 else return '?';
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 '*  in <code>numconv.h</code>.
 */
int char2int (int radix, char digit) {
  if((radix < 2) | (radix > 36)) return -1;
  if ((digit >= 'A')&(digit <= 'Z')) return digit - 55;
  if ((digit >= 'a')&(digit <= 'z')) return digit - 87;
  if ((digit >= '0')&(digit <= '9')) return digit - 48;
  
  return -1;
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void divRem (int numerator, int divisor, int* quotient, int* remainder) {
  if((divisor > 0) & (numerator >= 0)){
  int quo = numerator / divisor;
  int rem = numerator % divisor;
  
  *quotient = quo;
  *remainder = rem;
  }

}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
int ascii2int (int radix, int valueOfPrefix) {

  char curr = getchar();

  if(curr != '\n'){
  valueOfPrefix = radix * valueOfPrefix + char2int(radix, curr);
  //printf("%d", valueOfPrefix);
  return ascii2int(radix, valueOfPrefix); 
  
  }
  else{
    return valueOfPrefix;
  }
}



/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
void int2ascii (int radix, int value) {
  int quotient;
  int remainder;

  divRem(value, radix, &quotient, &remainder);
  
  if(quotient == 0){ 
    putchar(int2char(radix, remainder));
    }
  else {
    int2ascii(radix, quotient);
    putchar(int2char(radix, remainder));
  }
  
}

/** @todo implement in <code>numconv.c</code> based on documentation contained 
 *  in <code>numconv.h</code>.
 */
double frac2double (int radix) {
  return -1.0;
}
