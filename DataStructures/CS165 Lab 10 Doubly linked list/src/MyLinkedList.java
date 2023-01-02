/** Linked List Lab
 * Made by Toby Patterson 5/31/2020
 * For CS165 at CSU
 */

public class MyLinkedList<E> implements MiniList<E>{
    /* Private member variables that you need to declare:
     ** The head pointer
     ** The tail pointer
     */

    private Node head;
    private Node tail;
    private int size;


    public class Node {
        // declare member variables (data, prev and next)
        E data;
        private Node prev;
        private Node next;


        // finish these constructors
        public Node(E data, Node prev, Node next) {
            this.prev = prev;
            this.next = next;
            this.data = data;
        }

        public Node(E data) {
            this(data, null, null);
        } // HINT: use this() with next = prev = null
    }

    // Initialize the head and tail pointer
    public MyLinkedList() {
        this.head = null;
        this.tail = head;
        this.size = 0;
    }

    public boolean indexCheck(int index){
        if((index < 0) || (index > size)){
            throw new IndexOutOfBoundsException();
        }else return true;
    }

    @Override
    public boolean add(E item) {
        add(size, item);
        return true;
    }

    @Override
    public void add(int index, E element) {
        Node curr = new Node(element);

        indexCheck(index);

        //Empty list
        if((head == null) && (index == 0)){
            head = curr;
            tail = curr;
            size ++;
        }

        //Prepend list
        else if((head != null) && (index == 0)){
            head.prev = curr;
            curr.next = head;
            curr = head;
            size++;
        }

        //Append List
        else if(index == size){
            tail.next = curr;
            curr.prev = tail;
            tail = curr;
            size++;
        }

        //Add in center
        else {
            Node predecessor = iterator(index - 1);
            Node successor = predecessor.next;

            curr.next = successor;
            curr.prev = predecessor;
            successor.prev = curr;
            predecessor.next = curr;

            size ++;

        }



    }

    public Node iterator(int index){
        indexCheck(index);
        Node find = head;

        for (int i = 0; i < index; i++){
            find = find.next;
        }
        return find;
    }

    @Override
    public E remove() {
        E deleted = head.data;
        head = head.next;
        head.prev = null;
        size--;
        return deleted;

    }

    @Override
    public E remove(int index) {

        //index 0 remove head
        if((head != null) && (index == 0)){
            return remove();
        }

        //index == size, remove tail
        else if(index == size - 1){
            Node predecessor = iterator(index - 1);
            Node successor = iterator(index);
            E deleted = successor.data;
            predecessor.next = null;
            tail = predecessor;
            size--;
            return deleted;
        }

        //remove somewhere in middle
        else {
            Node predecessor = iterator(index - 1);
            Node successor = predecessor.next.next;
            E deleted = predecessor.next.data;
            successor.prev = predecessor;
            predecessor.next = successor;

            size--;
            return deleted;
        }
    }

    @Override
    public boolean remove(E item) {
        int where = indexOf(item);
        System.out.println(where);
        if(where >= 0){
            remove(where);
            return true;
        }

        return false;
    }

    @Override
    public void clear() {
        head = null;
        tail = null;
        size = 0;
    }

    @Override
    public boolean contains(E item) {
        return (indexOf(item) >= 0);
    }

    @Override
    public E get(int index) {
        indexCheck(index);

        return iterator(index).data;

    }

    @Override
    public int indexOf(E item) {
        for (int i = 0; i < size; i++){
            if(get(i).equals(item)){
                return i;
            }
        }
        return -1;
    }

    @Override
    public boolean isEmpty() {
        return (size == 0);
    }

    @Override
    public int size() {
        return size;
    }

    // Uncomment when ready to test
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