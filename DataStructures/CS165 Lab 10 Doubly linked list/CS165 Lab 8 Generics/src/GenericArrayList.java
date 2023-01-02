import java.util.List;
import java.util.ArrayList;


public class GenericArrayList <T>{
    /* YOUR CODE HERE
     * Copy your code from your ArrayStringList class, and place it within 
     * this class.
     *
     */

    private T[] data;
    private int size;
    private int length;

    @SuppressWarnings("unchecked")
    private void resizeData(int newSize) {

        T[] newData = (T[]) new Object[newSize];
        System.arraycopy(data,0,newData,0,data.length); //use this in place of a for loop that iterates over the arrays
        data = newData;

    }

@SuppressWarnings("unchecked")
    public GenericArrayList(int initialCapacity) {
        data = (T[]) new Object[initialCapacity];
        this.size = 0;
    }

    /* This method should add a string to the END of your ArrayList.
     * For instance, if there are 5 elements, this should go into index 5 (the
     * sixth spot).
     */
    public void add(T str) {
//        System.out.println("str is " + str);
        add(size, str);
    }


    public void add(int index, T str) {
        if ((index > size) || (index < 0)) {
            return;
        }

        if (size == data.length) {
            resizeData(data.length * 2);
            //          System.out.println("data was resized to " + data.length);
        }
        if (data[index] != null) {
            System.arraycopy(data, index, data, index + 1, size - index);
        }

        data[index] = str;
        size++;
    }

    public T get(int index) {
        if((index > size)||(index < 0)){
            return null;
        }else{
            return data[index];
        }
    }


    public void remove(int index) {
        if(index > size) {
            return;                     // index   0  1 -2- 3  4  5  6
        }                  //                            -  +  +  +  +  length = 7 - (2+1) = 4
        else {                                  //[1, 2, 3, 4, 5, 6,   ]
            System.arraycopy(data, index + 1, data, index, data.length-(index+1));

        }
        --size;
    }


    public int size(){
        return this.size;
    }


    public boolean contains(T str) {

        for (int i = 0; i < size; i++){
            if(data[i].equals(str)){
                return true;
            }
        }


        return false;
    }



    public static void main(String[] args) {
        /* PART 1:
         * Modify the GenericArrayList above so that it can store *any* class,
         * not just strings.
         * When you've done that, uncomment the block of code below, and see if
         * it compiles. If it does, run it. If there are no errors, you did
         * it right!
         */

    //     Uncomment me when you're done

        GenericArrayList<Point> pointList = new GenericArrayList<Point>(2);

        pointList.add(new Point(0, 0));
        pointList.add(new Point(2, 2));
        pointList.add(new Point(7, 0));
        pointList.add(new Point(19.16f, 22.32f));

        pointList.remove(0);
        Point p = pointList.get(2);

        if (p.x != 19.16f && p.y != 22.32f) {
            throw new AssertionError("Your GenericArrayList compiled properly "
            + "but is not correctly storing things. Make sure you didn't "
            + "accidentally change any of your ArrayStringList code, aside "
            + "from changing types.");
        }

        GenericArrayList<Float> floatList = new GenericArrayList<Float>(2);

        for (float f = 0.0f; f < 100.0f; f += 4.3f) {
            floatList.add(f);
        }

        float f = floatList.get(19);

        System.out.println("Hurray, everything worked!");



       

    }
}

