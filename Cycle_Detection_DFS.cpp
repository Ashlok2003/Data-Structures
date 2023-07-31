class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(), m = graph[0].size();
        vector<bool> visited(n + 1, false);
        vector<bool> path_visit(n + 1, false);
        vector<bool> check(n + 1, false);

        auto DFS = [&](auto &DFS, int node) -> bool{
            visited[node] = true;
            path_visit[node] = true;
            check[node] = false;
            // Traverse for all the adjacent nodes
            for(auto x : graph[node]){
                // When the node is not visited then traversing its adjacent nodes
                if(!visited[x]){
                    if(DFS(DFS, x))
                        return true;
                }
                // If the node has been previously visited 
                // but it has to be visited on the same path
                else if(path_visit[x])
                    return true;
            }
            check[node] = true;
            path_visit[node] = false;
            return false;
        };

        for(int i = 0 ; i < n; ++i){
            if(!visited[i]){
                DFS(DFS, i);
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; ++i)
            if(check[i])
                ans.push_back(i);

        return ans;
            
    }
};
