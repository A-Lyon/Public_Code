import java.util.Scanner;

public class DescendingOrder {
    // TODO: Write a void method selectionSortDescendTrace() that takes
    //       an integer array and the number of elements in the array as arguments,
    //       and sorts the array into descending order.
    public static void selectionSortDescendTrace(int [] numbers, int numElements) {

        for (int i = 0; i < numElements - 1; i++){

            int high = i;

            for (int j = i + 1; j < numElements; j++){
                if (numbers[j] > numbers[high]){
                    high = j;
                }
            }

            if (numbers[high] > numbers[i]){
                int temp = numbers[i];
                numbers[i] = numbers[high];
                numbers[high] = temp;
            }

            for (int e = 0; e <numElements; e++){
                System.out.print("" + numbers[e] + " ");
            }
            System.out.println("");
        }
    }


    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);

//        int input, i = 0;
        int numElements = 0;
        int [] numbers = new int[10];

        for (int i = 0; i < numbers.length; i++){
            int temp = scnr.nextInt();
            if (temp < 0){
                break;
            }
            else {
                numbers[i] = temp;
                numElements ++;
            }
        }

        selectionSortDescendTrace(numbers, numElements);

        // TODO: Read in a list of up to 10 positive integers; stop when
        //       -1 is read. Then call selectionSortDescendTrace() method.

    }
}
