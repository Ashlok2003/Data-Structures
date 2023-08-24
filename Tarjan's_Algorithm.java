/*
=======================================================================================================================================================
                                            Algorithm Intutution & Implementation
=======================================================================================================================================================
The algorithm is based on the idea that a bridge is an edge that, if removed, will disconnect the graph into two or more disjoint components.

The code first constructs an adjacency list from the input list of connections con. It then initializes some data structures used in the algorithm,
such as visited, tin, low, and brides. (tin = inertion time timer basically).

The algorithm starts by visiting each node in the graph, and for each node node, it performs a depth-first search 
to find all the nodes that can be reached from node while avoiding cycles. In this search, timer is used to keep track
of the time when each node is first visited, disc[node], and low[node] is the lowest disc value that can be reached from node via a back edge.

If a neighbor neigh of node has not been visited before, the search continues recursively from neigh, and low[node] is updated 
with the minimum of low[node] and low[neigh]. If low[neigh] > tinc[node], then the edge from node to neigh is a bridge, and it is added to the res vector.

If neigh has already been visited and is not the parent of node, then it is a back edge, and low[node] is updated with 
the minimum of low[node] and tin[neigh].

Time complexity: The algorithm performs a depth-first search starting from each node in the graph. 
Since each edge is traversed at most twice (once for each endpoint), the time complexity of the algorithm is O(V+E), 
where V is the number of vertices and E is the number of edges in the graph.

Space complexity: The space complexity is O(V+E), where V is the number of vertices and E is the number of edges in the graph. 
This is because the algorithm uses the adjacency list to store the graph, and it also uses some additional data structures, 
such as visited, tin, low, and bridges, which all have size O(V).
===========================================================================================================================================================
*/
// Following Code is basically The solution of LEETCODE Question: Critical Connections in a Network 
//                which use Trajan's Algorithm to find the critical edges coordinates. :)
class Solution {
    private int Timer = 1;
    public void DFS(int node, int parent, ArrayList<Boolean> visited, ArrayList<ArrayList<Integer>> graph, int[] tin, int[] low, List<List<Integer>> bridges){
        
        visited.set(node, true);
        tin[node] = low[node] = Timer;
        Timer++;

        for(int x : graph.get(node)){
            if(x == parent)
                continue;

            if(!visited.get(x)){
                DFS(x, node, visited, graph, tin, low, bridges);
                low[node] = Math.min(low[node], low[x]);

                if(low[x] > tin[node])
                    bridges.add(Arrays.asList(x, node));
            }
            else{
                low[node] = Math.min(low[node], low[x]);
            }
        }
    }
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> bridges = new ArrayList<>();

        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> graph.add(new ArrayList<>()));

        for(List<Integer> x : connections){
            int u = x.get(0);
            int v = x.get(1);
            graph.get(u).add(v);
            graph.get(v).add(u);
        }

        ArrayList<Boolean> visited = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> visited.add(false));

        int[] tin = new int[n];
        int[] low = new int[n];

        DFS(0, -1, visited, graph, tin, low, bridges);
        return bridges;
    }
}
// Thanks for Reading and Checking out............................. :)
