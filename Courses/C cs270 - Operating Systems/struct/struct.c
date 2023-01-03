/* CS270 
 *
 * Author: Andrew Lyon
 * Date:   6/30/2021
 */

#include "struct.h"
#include<stdio.h>
#include <stdlib.h>

/********** FUNCTION DEFINITIONS **********************************************/

void readStudentAndEnroll(Student **slot)
{

  Student *newStud = (Student * ) malloc( sizeof( Student ) );

  scanf( "%s", (newStud -> firstname));
  scanf( "%f", &(newStud -> qualityPoints));
  scanf( "%d", &(newStud-> numCredits));
 
  *slot = newStud; 
  
}

void displayStudent(Student s)
{

  float GPA = s.qualityPoints / s.numCredits;
  printf( "%s, %0.2f\n", s.firstname, GPA );

}
