/* Binary Search Tree Class
*  Made by Toby Patterson for CS165 at CSU
*  6/25/2020
*  A basic binary search tree of integers, without a remove method.
*/

public class BST implements Tree<Integer> {

    private TreeNode <Integer> root;
    private int size;
    private int timer;


    public class TreeNode<Integer> {
        public Integer element;
        public TreeNode <Integer> rightChild;
        public TreeNode <Integer> leftChild;

        /*
        *  Think: what needs to be initialized, there are three member variables */
        public TreeNode(Integer element) {
            this.element = element;
            this.rightChild = null;
            this.leftChild = null;

        }
    }

    public BST() {
        this.root = null;
        size = 0;
    }

    public BST(Integer item) {
        super();
        insert(item);

    }

    public BST(Integer[] items) {
        for(Integer x : items){
            insert(x);
        }
        /*  Insert all of items into this tree */
    }

    /* Does a binary search.
    *   */
    @Override
    public boolean search(Integer item) {
        if(getRoot() == null){
            return false;
        }
        else{
            return searchRecursive(root, item);
        }
    }

    public boolean searchRecursive(TreeNode<Integer> current, Integer item){
        if(current.element.equals(item)){
            return true;
        }
        else if (hasLeft(current)){
            return searchRecursive(current.leftChild, item);
        }
        else if (hasRight(current)){
            return searchRecursive(current.rightChild, item);
        }
        return false;
    }



    /* Inserts item into tree, return false if item is already in tree.
    *  Order of the tree is: root.element > left.element &&
    *                        root.element < right.element
    *
    */
    @Override
    public boolean insert(Integer item) {
        TreeNode<Integer> current;
        if(getRoot() == null){
            root = new TreeNode<>(item);
            size++;
            return true;
        }
        else if(search(item)){
            return false;
        }
        else{
            current = getRoot();
            while(current != null){
                if(current.element > item){
                    if(!hasLeft(current)){
                        current.leftChild = new TreeNode<>(item);
                        size++;
                        current = null;
                    }
                    else{
                        current = current.leftChild;
                    }
                }
                else{
                    if(!hasRight(current)){
                        current.rightChild = new TreeNode<>(item);
                        size++;
                        current = null;
                    }
                    else{
                        current = current.rightChild;
                    }
                }
            }
        }
        return true;
    }

    /*  was going to do this recursively, but its late and beer is good.
    public boolean traverse(TreeNode<Integer> current, Integer item){
        if(current.element.equals(item)){
            return false;
        }
        else if (hasLeft(current)){
            if(!AddIn(current)) {
                return traverse(current.leftChild, item);
            }
        }
        else if (hasRight(current)){
            return traverse(current.rightChild, item);
        }
        return false;
    }

    public boolean AddIn(TreeNode<Integer> current){
        return false;
    }
    */


    public boolean hasRoot(TreeNode<Integer> current){
        return (getRoot() != null);
    }

    public boolean hasLeft(TreeNode<Integer> current){
        return (current.leftChild != null);
    }

    public boolean hasRight(TreeNode<Integer> current){
        return (current.rightChild != null);
    }

    // for the next lab
//    @Override
//    public boolean remove(Integer item) {
//        return false;
//    }

    /* Getter method for the size of the tree
    *  TODO: complete this method
    */
    @Override
    public int size() {
        return size;
    }

    /* Does an inorder traversal of the tree, printing each visited node
    *  TODO: Complete this method
    */
    @Override
    public void inorder() {
        timer = size;
        inHelper(getRoot());
    }

    public void inHelper(TreeNode<Integer> current){

        if(timer < 0){
            return;
        }
        if(hasLeft(current)){
            inHelper(current.leftChild);
        }
        System.out.print(current.element + " ");
        timer--;
        if(hasRight(current)){
            inHelper(current.rightChild);
        }

    }

    /* Does a postorder traversal of the tree, printing each visited node
     *  TODO: Complete this method
     */
    @Override
    public void postorder() {
        timer = size;
        postHelper(getRoot());
    }

    public void postHelper(TreeNode<Integer> current){
        if(timer < 0){
            return;
        }

        if(hasLeft(current)){
            postHelper(current.leftChild);
        }
        if(hasRight(current)){
            postHelper(current.rightChild);
        }
        System.out.print(current.element + " ");
        timer--;
    }


    /* Does a preorder traversal of the tree, printing each visited node
     *  TODO: Complete this method
     */
    @Override
    public void preorder() {
        timer = size;
        preHelper(getRoot());
    }

    public void preHelper(TreeNode<Integer> current){
        if(timer < 0){
            return;
        }
        System.out.print(current.element + " ");
        timer--;
        if(hasLeft(current)){
            preHelper(current.leftChild);
        }
        if(hasRight(current)){
            preHelper(current.rightChild);
        }
    }

    /* Prints true on empty tree, false otherwise
     *
     */
    @Override
    public boolean isEmpty() {
        return(size == 0);

    }

    /* Returns the root node of the tree */
    public TreeNode<Integer> getRoot() {
        return root;
    }
}
