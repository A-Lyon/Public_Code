/* CS270 
 *
 * Author: Andrew Lyon
 * Date:   6/30/2021
 */
 
/********** STRUCTURE DEFINITION **********************************************/

// Structure that represents a student
typedef struct
{
  // TODO: Add required members
  char firstname[80];
  float qualityPoints;
  int numCredits; 	  
} Student;

// Structure that represents a class roster
// TODO: Declare this structure

typedef struct{
  int numStudents;
  Student **students;
} ClassRoster;

/********** FUNCTION PROTOTYPES ***********************************************/

void readStudentAndEnroll(Student **slot);

void displayStudent(Student s);
