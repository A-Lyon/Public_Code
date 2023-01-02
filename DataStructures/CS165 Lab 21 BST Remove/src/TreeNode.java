public class TreeNode<E> {
    public E element;
    public TreeNode rightChild;
    public TreeNode leftChild;

    /* TODO: finish this constructor
     *  Think: what needs to be initialized, there are three member variables */
    public TreeNode(E element) {
        this.element = element;
        this.rightChild = null;
        this.leftChild = null;

    }
}
