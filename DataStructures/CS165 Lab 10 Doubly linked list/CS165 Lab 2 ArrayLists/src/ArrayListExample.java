import java.lang.reflect.Array;
import java.util.List;
import java.util.ArrayList;

public class ArrayListExample {
    public static void main(String[] args){
        //Arrays vs. ArrayLists
        String[] students = new String[15];
        for(String s: students){
            s = "John Doe";
        }
        //new student (16th student) - ERROR
        students[15] = "Jane Doe";
        //new array
        String[] students2 = new String[16];
        //copy over students and add new one

        //EASIER WAY
        ArrayList<String> students3 = new ArrayList<String>();
        for(int i = 0; i < 15; i++){
            students3.add("John Doe");
        }
        //new student
        students3.add("Jane Doe");


        //List Interface - Note
        List<String> list = new ArrayList<String>();
        ArrayList<String> list2 = new ArrayList<String>();
        //Won't work -why?
        //List<String> list3 = new List<String>();
        
        
    }
}
