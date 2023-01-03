 /** @mainpage 
   *  \htmlinclude "STRUCTS.html"
   */
/* CS270 
 * 
 * Author: Andrew Lyon
 * Date:   6/30/2021
 */
#include<stdio.h>
#include <stdlib.h>
#include "struct.h"

int main(int argc, const char **argv)
{
  // TODO: Complete the main function
  
  int numStud;
  scanf("%d", &numStud);
  
  ClassRoster roster;
  roster.numStudents = numStud;
  //printf("%d", roster.numStudents);
  roster.students = (Student **)calloc(roster.numStudents ,  sizeof(Student));
  
  for (int i = 0; i < (numStud); i++){            // add students
    readStudentAndEnroll( &roster.students[i] );
  }
  
  for(int i = 0; i < (numStud); i++){      // print students
	  displayStudent(*roster.students[i]); 
    free(roster.students[i]);
  }
   
  free(roster.students); 
  
  return 0;
}
   