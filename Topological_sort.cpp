// Depth First Search -  DFS Algorithm Approach
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> st;
	    vector<bool> visited(V, false);
	    
	    auto DFS = [&](auto &DFS, int node) -> void{
	        
	        visited[node] = true;
	        for(auto x : adj[node]){
	            if(!visited[x])
	                DFS(DFS, x);
	        }
	        // Since the DFS is done now so we can add into stack
	        // And linearity order is maintained.
	        st.push(node);
	    };
	    
	    
	    for(int i = 0; i < V; ++i){
	        if(!visited[i])
	            DFS(DFS, i);
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
