// Khan's Algorithm
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V, 0);
	    for(int i = 0; i < V; ++i){
	        for(int x : adj[i])
	            indegree[x]++;
	    }
	    
	    queue<int> q;
	    // Adding those nodes having indegree 0
	    for(int i = 0; i < V; ++i){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        // Node is in topological sort 
	        // so please remove it from the indegree.
	        for(auto x : adj[node]){
	            indegree[x]--;
	            if(indegree[x] == 0){
	               q.push(x);
	            }
	        }
	    }
	    return ans;
	} 
