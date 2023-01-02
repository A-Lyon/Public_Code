/* BSTTest class
 *  Some tests for the Binary Tree of <extends Comparable> lab. */

public class BSTTest {
    public static void main(String[] args) {
        Integer[] bst1Arr = {50, 112, 20, 30, 2, 6, 53, 140, 155, 130, 122};
        BST<Integer> bsTree1 = new BST<>(bst1Arr);

        Integer[] testTArr = {50, 112, 20};
        BST<Integer> testT = new BST<>(testTArr);

        bsTree1.inorder();
        System.out.println("");
        bsTree1.remove(130);
        bsTree1.inorder();
        System.out.println("");
        bsTree1.remove(30);
        bsTree1.inorder();

        /*    bsTree1.inorder();         //Tests for removing leafs
        System.out.println("");
        bsTree1.postorder();
        System.out.println("");
        bsTree1.preorder();
        System.out.println("");
        bsTree1.remove(6);
        bsTree1.remove(6);
        bsTree1.remove(53);
        bsTree1.remove(112);
        bsTree1.remove(2);
        bsTree1.remove(30);
        bsTree1.remove(20);
        bsTree1.remove(50);
        bsTree1.inorder();
        bsTree1.postorder();
        bsTree1.preorder();
    */



    //    System.out.println(testT.getNode(10).element.toString());                         //testing node not present
    //    System.out.println(testT.getParent(testT.getNode(10)).element.toString());        //testing getParent simple//
    //    System.out.println(bsTree1.getParent(bsTree1.getNode(112)).element.toString());   //testing getParent on right branch
    //    System.out.println(bsTree1.getParent(bsTree1.getNode(2)).element.toString());     //testing getParent on element in left subtree 2 height
    //    System.out.println(bsTree1.getParent(bsTree1.getNode(10)).element.toString());    //test getParent of non-existent node


    /*    System.out.println("Testing Search");
        System.out.println("tree1 is currently: ");
        bsTree1.inorder();
        System.out.println("bsTree1(50) should be true -> " + bsTree1.search(50));
        System.out.println("bsTree1(112) should be true -> " + bsTree1.search(112));
        System.out.println("bsTree1(3) should be false -> " + bsTree1.search(3));
        System.out.println("bsTree1(20) should be true -> " + bsTree1.search(20));
        System.out.println("bsTree1(6) should be true -> " + bsTree1.search(6));
        System.out.println("bsTree1(53) should be true -> " + bsTree1.search(53));



        System.out.println("inorder should be 2 6 20 30 50 53 112 ->");
        System.out.print("Your result: ");
        bsTree1.inorder();
        System.out.println();



        System.out.print("inorder, postorder, preorder for bsTree1: \n");
        System.out.println("inorder should be 2 6 20 30 50 53 112 ->");
        System.out.print("Your result: ");
        bsTree1.inorder();
        System.out.println();
        System.out.println("postorder should be 6 2 30 20 53 112 50 ->");
        System.out.print("Your result: ");
        bsTree1.postorder();
        System.out.println();
        System.out.println("preorder should be 50 20 2 6 30 112 53 ->");
        System.out.print("Your result: ");
        bsTree1.preorder();
        System.out.println("\n");

        String[] bst2Arr = {"hello", "I", "Am", "here"};
        BST<String> bsTree2 = new BST<>(bst2Arr);

        System.out.print("inorder, postorder, preorder for bsTree2: \n");
        System.out.println("inorder should be Am I hello here ->");
        System.out.print("Your result: ");
        bsTree2.inorder();
        System.out.println();
        System.out.println("postorder should be Am I here hello ->");
        System.out.print("Your result: ");
        bsTree2.postorder();
        System.out.println();
        System.out.println("preorder should be hello I Am here ->");
        System.out.print("Your result: ");
        bsTree2.preorder();
        System.out.println("\n");

        System.out.println("Testing Search");
        System.out.println("bsTree1(50) should be true -> " + bsTree1.search(50));
        System.out.println("bsTree1(112) should be true -> " + bsTree1.search(112));
        System.out.println("bsTree1(3) should be false -> " + bsTree1.search(3));
        System.out.println("bsTree2(\"hello\") should be true -> " + bsTree2.search("hello"));
        System.out.println("bsTree2(\"I\") should be true -> " + bsTree2.search("I"));
        System.out.println("bsTree2(\"explosion\") should be false -> " + bsTree2.search("explosion"));
        System.out.println();

        // Test Code for remove is going to be dependent on implementation.
        // For this lab, you will swap the node to be deleted with its inorder successor.


        System.out.println("Testing Remove");
        System.out.println("inorder after calling bsTree2.remove(\"hello\") should be Am I here ->");
        bsTree2.remove("hello");
        System.out.print("Your result: ");
        bsTree2.inorder();
        System.out.println('\n');

        System.out.println("root of bsTree2 after bsTree2.remove(\"hello\") should be here -> ");
        System.out.println("Your result: " + bsTree2.getRoot().element);
        System.out.println();

        System.out.println("inorder after calling bsTree2.remove(\"I\") should be Am here ->");
        bsTree2.remove("I");
        System.out.print("Your result: ");
        bsTree2.inorder();
        System.out.println("\n");

        System.out.println("inorder after calling bsTree2.remove(\"Am\") should be here ->");
        bsTree2.remove("Am");
        System.out.print("Your result: ");
        bsTree2.inorder();
        System.out.println("\n");
*/

    }
}
