import java.util.LinkedList;

public class LLTest {
    public static void main(String args[]) {
        MyLinkedList ll = new MyLinkedList();

        LinkedList <Integer>blob = new LinkedList <Integer>();
        blob.add(4);
        System.out.println(blob);

        ArrayList

        // Testing add methods
        System.out.println("Testing Add-------------------------------------------");
        ll.add(40);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.add(10);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.add(20);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.add(1, 30);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.add(3, 100);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

//        ll.add(0, 23); //TODO remove this line adding at index 0 test. works!
        ll.add(65);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.add(2);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        System.out.println("Expected: 40 30 10 100 20 65 2");
        System.out.println("Actual: " + ll);
        System.out.println();

        // Testing remove methods
        System.out.println("Testing Remove--------------------------------------");

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.remove();

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.remove(2);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        ll.remove(3);

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

//        ll.add(58);
//        ll.add(23);

        ll.remove((Integer)2);

//       ll.remove((Integer)10);             //size is decrimented, but element stays
                                            // only passes if (Integer(2)) is given, nullPointer if i give it (10)

        System.out.println(ll);
        System.out.println("size is: " + ll.size());

        System.out.println("Expected: 30 10 20");
        System.out.println("Actual: " + ll);
        System.out.println("Size should be 3 -> " + ll.size());
        System.out.println();

        // Testing Contains
        System.out.println("Testing Contains----------------------------------------------------------");
        ll.add(2); // to make it a little bigger

        System.out.println("Current list is: " + ll);   //TODO: remove this line

        System.out.println("Should be true -> " + ll.contains(2));
        System.out.println("Should be false -> " + ll.contains(65));
        System.out.println("Should be true -> " + ll.contains(30));
        System.out.println();

        // Testing Get
        System.out.println("Testing Get");
        System.out.println("Actual list: " + ll);
        System.out.print("List using get: ");
        for (int i = 0; i < ll.size(); i++) {
            System.out.print(ll.get(i) + " ");
        }
        System.out.println("\n");

        // Testing indexOf
        System.out.println("Testing indexOf--------------------------------------------------------");
        System.out.println("Should be 2 -> " + ll.indexOf(20));
        System.out.println("Should be 3 -> " + ll.indexOf(2));
        System.out.println("Should be -1 -> " + ll.indexOf(65));

        // You can write more tests (these are not all encompassing)
        // When should these methods fail/throw exceptions?
        // Have all of the edge cases been tested?
        // Not quite all of the methods have been tested here (e.g. clear())

    }
}