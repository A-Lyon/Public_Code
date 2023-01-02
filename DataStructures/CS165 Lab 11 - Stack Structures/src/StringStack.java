import java.util.*;

/* YOUR CODE HERE
 * This entire class is just a skeleton for your code, plus a main method
 * for testing.
 */
public class StringStack {

    /* You will need some data fields here - at the very least, some kind of
     * String array.
     */

    String[] stack;
    private int size;
    private Object NoSuchElementException;

    /* Puts the stack into a valid state, ready for us to call methods on.
     * The size parameter stores the size of the stack.
     */
    public StringStack(int size) {
        stack = new String[size];
        this.size = 0;
    }

    /* If someone calls the constructor with no argument, they should get a
     * stack with a default size of 10.
     */
    public StringStack() {
        stack = new String[10];
        this.size = 0;
    }

    /* Return true if the stack has no elements, and false otherwise.
     */
    public boolean empty() {
        return (size == 0);
    }

    /* Return the object at the top of the stack, WITHOUT removing it.
     * If there are no elements to peek, throw a NoSuchElementException.
     */
    public String peek() {
        if (empty()){
            throw new NoSuchElementException();
        }
        else {
            return stack[size - 1];
        }

    }

    /* Return the object at the top of the stack, AND ALSO remove it.
     * If there are no elements to pop, throw a NoSuchElementException.
     */
    public String pop() {
        if (empty()){
            throw new NoSuchElementException();
        }
        else {
            String returnme = stack[size - 1];
            size--;
            return returnme;
        }

    }

    /* Add a new object to the top of the stack.
     * If there is no room in the stack, throw a IllegalStateException.
     */
    public String push(String s) {
        if (size == stack.length){
            throw new IllegalStateException();
        }
        else {
            stack[size] = s;
            size++;
        }

        return s;
    }

    /* Return the position of an object on the stack.  The position of an object
     * is just its distance from the top of the stack. So, the topmost item is
     * distance 0, the one below the topmost item is at distance 1, etc.
     * If the item is not found, return -1.
     */
    public int search(String s) {
        int fromTop = 0;
        for (int i = 0; i < size; i++){
            if (stack[size - (1 + i)].equals(s)){
                return fromTop;

            }else fromTop++;
        }


        return -1;
    }

    public static void main(String[] args) {
        StringStack stack_ten = new StringStack();
        StringStack stack_three = new StringStack(3);


        assertEquals(stack_ten.empty(), true,
                "Your stack returned false for empty(), even though it was just "
                        + "created and should be empty.");

        stack_ten.push("Alef");
        stack_ten.push("Bet");
        stack_ten.push("Gimel");

        assertEquals(stack_ten.empty(), false,
                "Your stack returned true for empty(), even though elements were "
                        + "pushed into it.");

        String top = stack_ten.pop();
        assertEquals(top, "Gimel",
                "Didn't get the correct element from a pop()! Should have been \" "
                        + "Gimel\", but was \"" + top + "\".");

        top = stack_ten.peek();
        assertEquals(top, "Bet",
                "Didn't get the correct element from a peek()! Should have been "
                        + "\"Bet\", but was \"" + top + "\".");

        // Making sure a peek doesn't change anything!
        top = stack_ten.peek();
        assertEquals(top, "Bet",
                "Didn't get the correct element from a peek()! Should have been "
                        + "\"Bet\", but was \"" + top + "\".");

        stack_ten.pop();
        stack_ten.pop();

        assertEquals(stack_ten.empty(), true,
                "Your stack returned false for empty, even though all of its "
                        + "elements were popped off.");

        boolean caught = false;
        try {
            stack_ten.pop();
        } catch (NoSuchElementException e) {
            caught = true;
        }
        if (!caught) {
            throw new AssertionError(
                    "Popping an empty stack should have caused a "
                            + "NoSuchElementException, but it did not!");
        }
        caught = false;
        try {
            stack_ten.peek();
        } catch (NoSuchElementException e) {
            caught = true;
        }
        if (!caught) {
            throw new AssertionError(
                    "Peeking an empty stack should have caused a "
                            + "NoSuchElementException, but it did not!");
        }
        caught = false;

        String[] moreLetters = new String[] {
                "Dalet", "He", "Vav", "Zayin", "Het", "Tet", "Yod", "Kaf", "Lamed"
        };
        for (String l : moreLetters) {
            stack_ten.push(l);
        }



        int searched = stack_ten.search("Het");
        assertEquals(searched, 4,
                "Incorrect result from .search(): got " + searched
                        + ", but should have found 4");

        searched = stack_ten.search("Lamed");
        assertEquals(searched, 0,
                "Incorrect result from .search(): got " + searched
                        + ", but should have found 0");

        searched = stack_ten.search("Not in the stack!");
        assertEquals(searched, -1,
                "Incorrect result from .search(): got " + searched
                        + ", but should have found -1");


        stack_three.push("A");
        stack_three.push("B");
        stack_three.push("G");
        try {
            stack_three.push("D");
        } catch (IllegalStateException e) {
            caught = true;
        }
        if (!caught) {
            throw new AssertionError(
                    "Trying to push onto a full stack should have caused an "
                            + "IllegalStateException, but it did not.");
        }

        System.out.println("All tests passed! Now go play some Jenga, because "
                + "you're the stacking master.");
    }


    private static <T1, T2> void assertEquals(T1 e1, T2 e2, String msg) {
        if (!e1.equals(e2)) {
            throw new AssertionError(msg);
        }


    }


}