import java.util.LinkedList;

/** Linked List Lab
 * Made by Toby Patterson 5/29/2020
 * For CS165 at CSU
 */

public class MyLinkedList implements MiniList<Integer>{
    /* Private member variables that you need to declare:
     ** The head pointer
     ** The tail pointer
     */

    private Node head;
    private Node tail;
    private int size;


    public class Node {
        // declare member variables (data and next)
        public int data;
        public Node next;


        // finish these constructors
        public Node(int data, Node next) {
            this.data = data;
            this.next = next;

        }

        public Node(int data) {
            new Node(data, null);
        } // HINT: use this() with next = null
    }

    // Initialize the linked list (set head and tail pointers)
    public MyLinkedList() {
        this.head = null;
        this.tail = null;
        size = 0;
    }

    @Override
    public boolean add(Integer item) {
        add(size, item);
        return true;
    }

    @Override
    public void add(int index, Integer element) {
        Node addme = new Node (element, null);

        if(outOfBoundsCheck(index) && (index != size)){
            throw new IndexOutOfBoundsException("Hey, you messed up your index");
        }

        //is list empty
        if (head == null){
            head = addme;
            tail = addme;
            size++;

        }

        //prepending (add index 0)
        else if(index == 0){
            addme.next = head;
            head = addme;
            size++;

        }

        //appending (add at end)
        else if(index == size){
            tail.next = addme;
            tail = tail.next;
            size++;

        }

        // adding in center
        else {
            Node prev = head;

            for (int i = 0; i < index-1; i++){
                prev=prev.next;
            }

            addme.next = prev.next;
            prev.next = addme;
            size ++;
        }

    }

    //                       \/
    //   [head]-[1]-[2]-[3]-[4]-[5]-[6]-[7]-[8]-[tail]
    //      0    1   2   3   4   5   6   7   8    9

    public Node iterator(int index){

        if(outOfBoundsCheck(index)){
            throw new IndexOutOfBoundsException();
        }

        Node start = head;
        for (int i = 0; i < index; i++){
            start = start.next;
        }return start;
    }

    public boolean outOfBoundsCheck(int index){
        if((index >= 0 ) && (index < size )) {
            return false;
        }return true;       //returns true if were out of bounds to make sure this can run
    }

    //do all these in regard to the index. Use indexOf line109 to get
    @Override
    public Integer remove() {
        Integer snippet = head.data;
        head = head.next;
        size--;
        return snippet;
    }

    @Override
    public Integer remove(int index) {

        if (index == 0) {
            return remove();
        }

        //removing tail
        else if (index == size - 1) {
            Node prev = iterator(index - 1);
            Integer snippet = tail.data;
            prev.next = prev.next.next;
            tail = prev;     //set to prev instead of prev.next because we want the tail here to fix removing integer 2
            size--;
            return snippet;
        }

        //removing in the middle somewhere
        else {
            Node cut = iterator(index);
            Node prev = iterator(index - 1);
            Integer snippet = cut.data;
            prev.next = cut.next; // could also use       prev.next = prev.next.next;
            size--;
            return snippet;

        }
    }

    @Override
    public boolean remove(Integer item) {
        int findMe = indexOf(item);
//        System.out.println("found the Integer at: " + findMe);

        if(findMe >= 0) {
            remove(findMe);
        }

        /*
        if(findMe >= 0){
            Node cut = iterator(findMe );
            Node prev = iterator(findMe -1);
            prev.next = cut.next;
            tail = prev;        //  <----------------  only way to keep nullPointer from occuring. will fail with Integer in middle
            size--;

        }
        */

        return false;
        }

/*
        if (findme >= 0){
            Node cut = iterator(findme);
            Node prev = iterator(findme - 1);
//            Integer snippet = cut.data;
            prev.next = cut.next;
            size--;

/*            if(findme == 0){
                cut.next = head;    //was thinking if this was the 0 index
            }
*/



    @Override
    public void clear() {           //keep an eye on size here
        head = null;
        tail = null;
        size = 0;

    }

    @Override
    public boolean contains (Integer item) {

        return( indexOf(item) != -1);
    }        // use indexOf to check

    @Override
    public Integer get(int index) {

        if(outOfBoundsCheck(index)){
            throw new IndexOutOfBoundsException();
        }

        return iterator(index).data;
    }


    @Override
    public int indexOf(Integer item) {
        Node lookie = head;
        for (int i = 0; i < size; i++){

            if ((item == lookie.data)){

                return i;
            }
            lookie = lookie.next;
        }
        return -1;
    }


    @Override
    public boolean isEmpty() {
        return(size == 0);
    }

    @Override
    public int size() {
        return size;
    }

//     Uncomment when ready to test
    @Override
    public String toString() {
        String ret = "";
        Node curr = head;
        while (curr != null) {
            ret += curr.data + " ";
            curr = curr.next;
        }
        return ret;
    }

}