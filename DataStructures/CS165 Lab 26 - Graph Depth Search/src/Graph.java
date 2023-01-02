/* Graph class
 * Template made by Toby Patterson
 * With the help of: https://www.cs.colostate.edu/~cs165/.Spring20/assignments/P8/doc/
 * Completed by: your name here
 * 6/2/2020
 * For cs165 at CSU
 *
 * A basic graph which has a depth first search print method. It uses
 * link references to keep track of edges.
 * */

import java.util.ArrayList;
import java.util.Arrays;

public class Graph<E extends Comparable<E>> extends GraphAbstract<E> {
    ArrayList<GraphNode> visited = new ArrayList<>();

    public Graph() {
        nodes = new ArrayList<GraphNode>();


    }

    /* addEdge
     * Params: data1 & data2, both data items to be added and connected
     * If the either of the data items are not in the nodes ArrayList,
     * add them as new nodes. Otherwise, find the nodes in the ArrayList so
     * you can make them point to each other. Implement so there are no duplicates
     * added to either of the nodes neighbors ArrayList.
     * TODO: implement this method.
     * */

    @Override
    public void addEdge(E data1, E data2) {
        GraphNode d1 = new GraphNode(data1);
        GraphNode d2 = new GraphNode(data2);


//        d1.neighbors.add(d2);
//        d2.neighbors.add(d1);
        if(addCheck(d1) && addCheck(d2)) {
            if(!get(d1).neighbors.contains(d2)){
                get(d1).neighbors.add(d2);
            }
            if(!get(d2).neighbors.contains(d1)) {
                get(d2).neighbors.add(d1);
            }
        }
        else if(addCheck(d1) && !addCheck(d2)) {
            d2.neighbors.add(get(d1));
            nodes.add(d2);
            get(d1).neighbors.add(get(d2));
        }

        else if (!addCheck(d1) && addCheck(d2)) {
            d1.neighbors.add(get(d2));
            nodes.add(d1);
            get(d2).neighbors.add(get(d1));
        }
        else{
            d2.neighbors.add(d1);
            d1.neighbors.add(d2);
            nodes.add(d2);
            nodes.add(d1);
        }
    }

    public boolean addCheck(GraphNode data) {    //true if nodes contains the searched node
        for(GraphNode n: nodes){
            if(n.equals(data)){
                return true;
            }
        }
        return false;

    }

    public GraphNode get(GraphNode current){
        for(GraphNode node: nodes){
            if(current.equals(node)){
                return node;
            }
        }return current;
    }

    public void neighborCheck() {

        System.out.println("Performing neighbor check: ");

        for (GraphNode e : nodes) {
            System.out.println(get(e).data + " has neighbor/s ");
            for (GraphNode r : e.neighbors) {
                System.out.println(r.data);
            }
        }
    }


    /* depthFirst
     * Param: startNode, the node to start the traversal at
     * First, find the startNode based off of startItem (hint: indexOf())
     * I recommend having an ArrayList of GraphNodes called visisted to keep
     * track of the nodes you've visited.
     *
     * Prints all of the nodes in the graph in depth first order (with a space between nodes)
     * TODO: implement this method.
     * */
    @Override
    public void depthFirst(E startItem) {
            depthFirst(get(new GraphNode(startItem)), visited);
            visited.clear();

    }

    // Recursive helper method for depthFirst
    private void depthFirst(GraphNode curr, ArrayList<GraphNode> visited) {
        //System.out.print(curr.data + " ");

        if(!visited.contains(curr)){
            visited.add(curr);
            System.out.print(curr.data + " ");
            for(GraphNode w: curr.neighbors){
                depthFirst(get(w), visited); // <------------when passed "depthFirst(w, visited)" instead of "depthFirst(get(w), visited)" it fails the first traversal, but not the second
            }
        }

    }

    /*        visited.add(curr);
            System.out.print(curr.data + " ");
        for (GraphNode w : curr.neighbors) {
            if (!visited.contains(w)) {
            //    visited.add(w);
                depthFirst(w, visited);
            }
        }

    }

     */
}



