/*
ChatGpt Generated Simpliest Intution go through once for clearity of algortihm's functionality :)

The algorithm consists of two main steps:

=====================First Pass (DFS and Stack):========================================================================================================================
* Perform a Depth-First Search (DFS) traversal on the original graph.
* While traversing, push nodes onto a stack in the order they finish their DFS.
* This step identifies the nodes that are part of SCCs.

===================Second Pass (DFS on Transposed Graph):===============================================================================================================
* Transpose the graph by reversing the directions of all edges.
* Pop nodes from the stack obtained in the first pass.
* For each node popped from the stack, perform a DFS on the transposed graph.
* Each DFS run in this step will cover one strongly connected component.

The intuition behind this algorithm lies in the fact that the first pass of DFS identifies the "source" nodes of SCCs, 
and the second pass starting from these sources traverses the entire SCC they belong to.
========================================================================================================================================================================
                  Here's how the algorithm works:
========================================================================================================================================================================
* The first pass identifies nodes that are not reachable from each other, so they can't be part of the same SCC.
* The second pass ensures that each SCC is explored completely, as starting from any node within a SCC, you will be able to reach all other nodes within that SCC.
* By tracking SCCs, you can partition the graph into distinct connected components
========================================================================================================================================================================
*/
class Solution
{
    public void DFS(int node, ArrayList<Boolean> visited, ArrayList<ArrayList<Integer>> adj, 
                    Stack<Integer> st){
        
        visited.set(node, true);
        for(int x : adj.get(node)){
            if(!visited.get(x)){
                DFS(x, visited, adj, st);
            }
        }
        st.push(node);
    }
    
    public void DFS_(int node, ArrayList<Boolean> visited, ArrayList<ArrayList<Integer>> adjT){
        visited.set(node, true);
        
        for(int x : adjT.get(node))
            if(!visited.get(x))
                DFS_(x, visited, adjT);
                
    }
    
    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj)
    {
        ArrayList<Boolean> visited = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        
        IntStream.range(0, V).forEach(i -> visited.add(false));
        
        for(int i = 0; i < V; ++i){
            if(!visited.get(i))
                DFS(i, visited, adj, st);
        }
        
        ArrayList<ArrayList<Integer>> adjT = new ArrayList<>();
        IntStream.range(0, V).forEach(i -> adjT.add(new ArrayList<>()));
        
        for(int i = 0; i < V; ++i){
            visited.set(i, false);
            
            for(int x : adj.get(i))
                adjT.get(x).add(i);
            
        }
        
        int scc = 0;
        while(!st.isEmpty()){
            int node = st.peek();
            st.pop();
            
            if(!visited.get(node)){
                scc++;
                DFS_(node, visited, adjT);
            }
        }
        return scc;
    }
}
