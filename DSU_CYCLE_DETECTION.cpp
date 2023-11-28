class Solution
{
    private:
        unordered_map<int, int> rank;
        unordered_map<int, int> parent;
    
    public:
    
        int findParent(int x) {
            if (parent.count(x) == 0) {
                return parent[x] = x;
            }
    
            if (parent[x] != x)
                parent[x] = findParent(parent[x]);
    
            return parent[x];
        }

        void UnionRank(int u, int v) {
            int x_parent = findParent(u);
            int y_parent = findParent(v);
    
            if (x_parent == y_parent)
                return;
    
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
                
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
                
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent] = rank[y_parent] + 1;
            }
        }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    for(int u = 0; u < V; ++u){
	        for(auto &v : adj[u]){
	            /* There is no point of checking on an bidrectional basis :) */
	            if(u < v){
	               int parent_u = findParent(u);
	               int parent_v = findParent(v);
	               
	               if(parent_u == parent_v){
	                   return true;
	               }
	               
	               UnionRank(u, v);
	            }
	        }
	    }
	    
	    return false;
	}
};
