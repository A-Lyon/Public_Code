import java.util.Scanner;
import java.util.HashMap;

public class StudentGrades {

    public static void main (String[] args) {
        Scanner scnr = new Scanner(System.in);
        String studentName;
        double studentGrade;
        double newGrade;

        HashMap<String, Double> studentGrades = new HashMap<String, Double>();

        // Students's grades (pre-entered)
        studentGrades.put("Harry Rawlins", 84.3);
        studentGrades.put("Stephanie Kong", 91.0);
        studentGrades.put("Shailen Tennyson", 78.6);
        studentGrades.put("Quincy Wraight", 65.4);
        studentGrades.put("Janine Antinori", 98.2);

        // TODO: Read in new grade for a student, output initial
        //       grade, replace with new grade in HashMap,
        //       output new grade

        /*

        Quincy Wraight
        73.1
        the output is:
                Quincy Wraight's original grade: 65.4
                Quincy Wraight's new grade: 73.1

        */



        studentName = scnr.nextLine();
        newGrade= scnr.nextDouble();

        if(studentGrades.containsKey(studentName)) {
            studentGrade = studentGrades.get(studentName);
            System.out.printf("%s's original grade: %.1f%n", studentName, studentGrade);
            studentGrades.put(studentName, newGrade);
            System.out.printf("%s's new grade: %.1f%n", studentName, newGrade);
        }
        else {
            System.out.println("Please enter valid student name and rerun.");

        }

    }
}
