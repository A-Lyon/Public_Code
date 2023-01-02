/* Binary Search Tree Class
 *  A binary search tree of generic type which extends Comparable
 */

public class BST<E extends Comparable<E>> implements Tree<E> {

    private TreeNode root;
    private int size;

    public BST() {
        this.root = null;
        size = 0;
    }

    public BST(E item) {
        this();
        insert(item);
    }

    public BST(E[] items) {
        for(E item: items){
            insert(item);
            //size++;
        }

    }
/*
    @Override      //working search algorithm with while loop
    public boolean search(E item) {
        if(getRoot() != null) {
            TreeNode<E> current = getRoot();

            while (current != null) {
                if (current.element.equals(item)) {
                    return true;
                } else if (current.element.compareTo(item) > 0) {
                    current = current.leftChild;
                } else current = current.rightChild;
            }
        }
        return false;
    }
*/


    @Override                            //now this works, had to check if the left/right is >/< to the current
    public boolean search(E item) {
        if(getRoot() == null){
            return false;
        }
        else{
            return searchRecursive(getRoot(), item);
        }
    }

    public boolean searchRecursive(TreeNode<E> current, E item){
        if(current.element.equals(item)){
            return true;
        }
        if (hasLeft(current) && (current.element.compareTo(item) > 0)){
            return searchRecursive(current.leftChild, item);
        }
        if (hasRight(current) && (current.element.compareTo(item) < 0)){
            return searchRecursive(current.rightChild, item);
        }
        return false;
    }

    public boolean hasLeft(TreeNode<E> current){
        return (current.leftChild != null);
    }

    public boolean hasRight(TreeNode<E> current){
        return (current.rightChild != null);
    }




    /*   */ //better increment size bitch!
    @Override
    public boolean insert(E item) {
        TreeNode<E> current;
        if(getRoot() == null){
            root = new TreeNode<E>(item);
            size++;
            return true;
        }
        else if(search(item)){
            return false;
        }
        else{
            current = getRoot();
            while(current != null){
                if(current.element.compareTo(item) > 0){   //check <,>
                    if(!hasLeft(current)){
                        current.leftChild = new TreeNode<E>(item);
                        size++;
                        current = null;
                    }
                    else{
                        current = current.leftChild;
                    }
                }
                else{
                    if(!hasRight(current)){
                        current.rightChild = new TreeNode<E>(item);
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

    public TreeNode<E> getNode(E item) {
        return getNodeHelper(getRoot(), item);
    }

    public TreeNode<E> getNodeHelper(TreeNode<E> current, E item) {

        if (current.element.equals(item))
            return current;
        else if ((hasLeft(current) && current.element.compareTo(item) > 0)) {
            return getNodeHelper(current.leftChild, item);
        } else if ((hasRight(current) && current.element.compareTo(item) < 0)) {
            return getNodeHelper(current.rightChild, item);
        } else {
            System.out.println("that node isnt here, returning current");     //get rid of this before submitting
            return current;
        }
    }

    public TreeNode<E> getParent(TreeNode<E> current){
        if(current.equals(getRoot())){
            System.out.println("Roots dont have parents, dork");
            return null;
        }
        return getParentHelper(getRoot(), current);
    }

    private TreeNode<E> getParentHelper(TreeNode<E> parent, TreeNode<E> child) {
        if((hasLeft(parent) && parent.leftChild.equals(child)) || (hasRight(parent) && parent.rightChild.equals(child))){
            return parent; //double check this
        }if (parent.element.compareTo(child.element) > 0){//double check the above or below zero for <,>
            if(hasLeft(parent)) {
                return getParentHelper(parent.leftChild, child);
            }
        }if (parent.element.compareTo(child.element) < 0){
            if(hasRight(parent)) {
                return getParentHelper(parent.rightChild, child);
            }
        }return null; //if called on the root, because there wouldnt be left or right children
    }

    public boolean isLeaf(TreeNode<E> node){
        return (!hasLeft(node) && !hasRight(node));
    }

    public boolean hasOneChild(TreeNode<E> node){
        return hasRight(node) ^ hasLeft(node);
    }

    public boolean hasTwoKids(TreeNode<E> daddy){
        return hasRight(daddy) && hasLeft(daddy);
    }

    /* TODO: finish this method */
    @Override
    public boolean remove(E item) {
        if(!search(item)){
            System.out.println("it wasnt here"); //remove this before submitting
            return false;
        }
        TreeNode<E> toGo = getNode(item);

        System.out.println(toGo.element.toString());
        if(isLeaf(toGo)){
            return removeLeaf(toGo);
        }
        // if one child
        if (hasOneChild(toGo)){
            return removeOne(toGo);
        }

        if (hasTwoKids(toGo)){
            return removeTwo(toGo);
        }





        return false;

    }


    public boolean removeTwo(TreeNode<E> daddy) {
        TreeNode<E> successor = getSuccessor(daddy);

        System.out.println("the successor before swap: " + successor.element.toString());
        System.out.println("the successor has parent: " + getParent(successor).element.toString());
        System.out.println("daddy before: " + daddy.element.toString());

        if(swap(daddy, successor)){

            System.out.println("the successor after swap: " + successor.element.toString());
            System.out.println("the successor has parent: " + getParent(successor).element);
            System.out.println("daddy after: " + daddy.element.toString());

            removeLeaf(successor);
            return true;
        }return false;


    }

    public TreeNode<E> getSuccessor(TreeNode<E> parent) {
        TreeNode<E> successor;


        if (hasRight(parent)) {
            successor = parent.rightChild;
            while (hasLeft(successor)) {
                successor = successor.leftChild;
            }
            return (successor);
        }
        else if(hasLeft(parent)) {
            successor = parent.leftChild;
            while (hasRight(successor)) {
                successor = successor.rightChild;
            }
            return successor;

        }return null;

    }


    public boolean swap(TreeNode<E> top, TreeNode<E> bottom){
        E temp = top.element;
        top.element = bottom.element;
        bottom.element = temp;
        return true;
    }

    public boolean removeLeaf(TreeNode<E> node){
        if (getParent(node) == null){
            root = null;
            return true;
        }

        TreeNode<E> parent = getParent(node);

        if (parent.element.compareTo(node.element) > 0) {
            parent.leftChild = null;
            return true;
        }
        else {
            parent.rightChild = null;
            return true;
        }
    }

    //remove with one child method
        //need to get the parent node and replacement node in this
        // can use this method in multiple remove cases
    public boolean removeOne(TreeNode<E> toGo){
        if (getParent(toGo) == null) {
            if (hasLeft(toGo)) {
                root = toGo.leftChild;
                return true;
            }
            else{
                root = toGo.rightChild;
                return true;
            }
        }
        TreeNode<E> parent = getParent(toGo);
        TreeNode<E> replacement;
        if (hasLeft(toGo)) {
            replacement = toGo.leftChild;
        }
        else{
            replacement = toGo.rightChild;
        }
        if(replacement.element.compareTo(parent.element) < 0){
            parent.leftChild = replacement;
            return true;
        }else{
            parent.rightChild = replacement;
            return true;
        }
    }

    //remove two children method
        //need to get the parent node and replacement child in this

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
        if(getRoot() == null){
            System.out.println("this sucker is empty");
            return;
        }
        inOrderHelper(getRoot());
    }

    public void inOrderHelper(TreeNode<E> current){
        if(hasLeft(current)){
            inOrderHelper(current.leftChild);
        }
        System.out.print((current.element.toString()) + " ");

        if(hasRight(current)){
            inOrderHelper(current.rightChild);
        }
    }

    /* Does a postorder traversal of the tree, printing each visited node
     *  TODO: Complete this method
     */
    @Override
    public void postorder() {
        postOrderHelper(getRoot());
    }

    public void postOrderHelper(TreeNode<E> current){
        if(getRoot() == null){
            System.out.println("this sucker is empty");
            return;
        }

        if(hasLeft(current)){
            postOrderHelper(current.leftChild);
        }
        if(hasRight(current)){
            postOrderHelper(current.rightChild);
        }
        System.out.print((current.element.toString()) + " ");
    }

    /* Does a preorder traversal of the tree, printing each visited node
     *  TODO: Complete this method
     */
    @Override
    public void preorder() {
        preOrderHelper(getRoot());
    }

    public void preOrderHelper(TreeNode<E> current){

        if(getRoot() == null){
            System.out.println("this sucker is empty");
            return;
        }

        System.out.print((current.element.toString()) + " ");
        if(hasLeft(current)){
            preOrderHelper(current.leftChild);
        }
        if(hasRight(current)){
            preOrderHelper(current.rightChild);
        }
    }

    /* Prints true on empty tree, false otherwise
     *  TODO: Complete this method
     */


    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    /* Returns the root node of the tree */
    public TreeNode<E> getRoot() {
        return root;
    }

    /*StringBuilder attempt = new StringBuilder();

    public String printInOrder(TreeNode<E> current){
        if(current == null) {
            attempt.append("");
            return attempt.toString();
        }
        printInOrder(current.leftChild);
        attempt.append((current.element.toString()) + " ");
        printInOrder(current.rightChild);
        return attempt.toString();
    }
    */

}
