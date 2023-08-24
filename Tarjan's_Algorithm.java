// Following Code is basically The solution of LEETCODE Question: Critical Connections in a Network
// The Tarjan's Algorithm is used to find the bridges in an graph using DFS.
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
