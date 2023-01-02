import java.util.Arrays;
import java.util.NoSuchElementException;

public class PriorityQueue {

    /* This class is finished for you.
     */
    public static class Customer implements Comparable<Customer> {
        private double donation;

        public Customer(double donation) {
            this.donation = donation;
        }

        public double getDonation() {
            return donation;
        }

        public void donate(double amount) {
            donation += amount;
        }


        public int compareTo(Customer other) {
            double diff = donation - other.donation;
            if (diff < 0) {
                return -1;
            } else if (diff > 0) {
                return 1;
            } else {
                return 0;
            }
        }

        public String toString() {
            return String.format("$%.2f", donation);
        }
    }

    private Customer[] data;
    private int size;

    public PriorityQueue(int capacity) {
        data = new Customer[capacity];
        size = 0;
    }

    public PriorityQueue() {
        this(10);
    }

    /* Add a customer to the queue.
     * Remember to do so in a way that keeps the queue in sorted order!
     */
    public void push(Customer customer) {
        //add to full
        if(size == data.length){
            throw new IllegalStateException();
        }

        // add to empty or non-full is same
        else {
            int where = getIndex(customer);
            System.arraycopy(data, where, data,where+1, size - where);
            data[where] = customer;
            size++;
        }
    }

    public int getIndex(Customer dick){
        for (int i = 0; i < size; i++) {
            if (data[i].compareTo(dick) < 0) {
                return i;
            }

        }return size;

    }

    /* Remove and return the highest priority customer from the queue.
     */
    public Customer pop() {
        if (size <= 0){
            throw new NoSuchElementException();
        }
        else{
            Customer out = data[0];
            System.arraycopy(data,1,data, 0, size-1);
            size--;
            return out;
        }
    }

    /* Return, but don't remove, the highest priority item from the queue.
     */
    public Customer peek() {
        if (size <= 0){
            throw new NoSuchElementException();
        }else return data[0];
    }

    /* Given the index of a customer, increase their donation amount, letting
     * them cut in line if necessary.
     *
     * Refer to the Customer class to remind yourself the operations you can do
     * on a customer.
     */
    public void bump(int customerIndex, double amount) {
        if(size <= 0){
            throw new NoSuchElementException();
        }
        else{
            Customer dude = data[customerIndex];
            System.arraycopy(data, customerIndex+1, data, customerIndex, size - customerIndex);
            size--;
            dude.donate(amount);
            push(dude);
        }

        /*

        could also add the money here and then call Arrays.sort on it

        data[customerIndex].donate(amount);
        Arrays.sort(data);
        */


    }

    public String toString() {
        return Arrays.toString(data);
    }

    public int getSize() {
        return size;
    }

    public static void main(String[] args) {
        PriorityQueue line = new PriorityQueue(6);

        System.out.println("Testing push");

        line.push(new Customer(5.00));
        line.push(new Customer(10.00));
        line.push(new Customer(1.00));

        System.out.println("Line should be:\n[$10.00, $5.00, $1.00, null, null, null]");
        System.out.println(line);

        System.out.println("Line size should be 3 is: " + line.getSize());

        System.out.println();

        System.out.println("Testing pop");

        System.out.println(line.pop());
        System.out.println(line.pop());

        System.out.println();

        System.out.println("Testing bump");

        line.push(new Customer(20.00));
        line.push(new Customer(15.00));
        line.push(new Customer(2.00));

        line.bump(1, 30.00);
        line.bump(3, 60.00);
        System.out.println(line.pop());
        System.out.println(line.peek());
        System.out.println(line.pop());
        System.out.println(line.pop());
        System.out.println(line.pop());

        System.out.println();

        line.push(new Customer(7.00));
        line.push(new Customer(8.00));
        line.push(new Customer(9.00));
        line.push(new Customer(7.00));
        line.push(new Customer(10.00));

        System.out.println("Line should be:\n[$10.00, $9.00, $8.00, $7.00, $7.00, null]");
        System.out.println(line);
    }
}