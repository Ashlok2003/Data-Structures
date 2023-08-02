class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> graph(K, vector<int>());
        
        for(int i = 0; i < (N - 1); ++i){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.length(), s2.length());
            
            for(int ptr = 0; ptr < len; ++ptr){
                if(s1[ptr] != s2[ptr]){
                    // If both the characters are different then there 
                    // we should we build directed edge between them
                    // to denote that the chracter is smaller than the another one.
                    graph[s1[ptr] - 'a'].emplace_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        // since we already form the directed graph uptil now so simply
        // perform the topological sort further using [Khan's algorithm].
        vector<int> indegree(K, false);
        for(int i = 0; i < K; ++i){
            for(auto &x : graph[i])
                indegree[x]++;
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < K; ++i){
            if(indegree[i] == 0)
                q.emplace(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.emplace_back(node);
            for(auto &x : graph[node]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.emplace(x);
            }
        }
        string ans = "";
        for(auto &x : topo){
            ans.push_back(char(x + 'a'));
        }
        return ans;
        // When the order is not possible
        /*
            *when the larger string is put before the smaller one
                eg:     abcd  --> The correct       abc
                        abc        must be          abcd
                        
            *where there is no linear dependency means cycle exists.
        */
    }
};
