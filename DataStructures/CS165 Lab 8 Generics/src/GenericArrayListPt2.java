import java.util.List;
import java.util.ArrayList;


public class GenericArrayListPt2 <T extends Comparable <Point>>{

    private T[] data;


    /* Storing the amount of valid Strings that are in the array turns out to be
     * fairly useful. This variable is for that.
     */
    private int size;
    private int length;

    @SuppressWarnings("unchecked")
    private void resizeData(int newSize) {
        T[] newData = (T[]) new Comparable[newSize];
        System.arraycopy(data,0,newData,0,data.length); //use this in place of a for loop that iterates over the arrays
        data = newData;


    }


    @SuppressWarnings("unchecked")
    public GenericArrayListPt2(int initialCapacity) {
        data = (T[]) new Comparable[initialCapacity];
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

        data [index] = str;
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
       

        /* PART 2:
         * Now, modify your GenericArrayList again so that it can only store
         * things that are comparable to a Point.
         *
         * If you don't know how to do this, reference zybooks and your textbook
         * for help.
         *
         * When you are ready to test it, uncomment the code above and run the
         * code below.
         */

        /* Uncomment me! *\

         */
        GenericArrayListPt2<Point> pointList = new GenericArrayListPt2<Point>(2);
        GenericArrayListPt2<Point3D> pointList3D = new GenericArrayListPt2<Point3D>(3);

        pointList.add(new Point(0, 0));
        pointList.add(new Point(2, 2));
        pointList.add(new Point(7, 0));
        pointList.add(new Point(19.16f, 22.32f));

        pointList3D.add(new Point3D(1.0f, 2.0f, 3.0f));
        pointList3D.add(new Point3D(7.3f, 4, 0));

        Point p = pointList.get(2);
        Point3D p3 = pointList3D.get(0);

        // You should get a compilation error on this line! - Why?
        //GenericArrayListPt2<Point> floatList = new GenericArrayList<Point>(2);


    }
}

