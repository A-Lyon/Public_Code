#include <stdio.h>

int main() {
  int a = 0xABCD0123;           // Negative number
  a = a >> 4;                   // Arithmetic shift
  printf("%08X\n", a);          // Print in hexadecimal

  int b = 0x7BCD0123;           // Positive number
  b = b >> 4;                   // Arithmetic shift
  printf("%08X\n", b);          // Print in hexadecimal

  unsigned int c = 0xFBCD0123;  // Unsigned number
  c = c >> 4;                   // Logical shift
  printf("%08X\n", c);          // Print in hexadecimal

  return 0;
}
