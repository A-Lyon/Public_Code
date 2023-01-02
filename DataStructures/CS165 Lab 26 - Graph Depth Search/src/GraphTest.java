public class GraphTest {
    public static void main(String[] args) {
        Graph<Integer> graph = new Graph<>();

        graph.addEdge(5, 3);
        graph.addEdge(3, 5);
        graph.addEdge(5, 2);
        graph.addEdge(2, 3);
        graph.addEdge(2, 4);
        graph.addEdge(4, 6);
        //graph.addEdge(5,6); //remember to remove

        graph.neighborCheck();


        System.out.println("Expected: 5 3 2 4 6 ");
        System.out.print("Your result: ");
        graph.depthFirst(5);
        graph.visited.clear();
        System.out.println();
        System.out.println("Expected: 3 5 2 4 6 ");
        System.out.print("Your result: ");
        graph.depthFirst(3);

        // As always, feel free to write more tests to help gain a better understanding.
    }
}
