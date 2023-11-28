// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
class DISJOINT_SET_UNION {
    private:
        int components;
        unordered_map<int, int> rank;
        unordered_map<int, int> parent;

    public: 
        DISJOINT_SET_UNION(int n) : components(n){
            for(int i = 1; i < (n + 1); ++i)
                parent[i] = i;
        }

        int findParent(int x){
            if(x == parent[x])
                return x;
            
            return parent[x] = findParent(parent[x]);
        }

        void UnionRank(int u, int v){
            int x_parent = findParent(u);
            int y_parent = findParent(v);

            if(x_parent == y_parent)
                return;
            
            if(rank[x_parent] > rank[y_parent])
                parent[y_parent] = x_parent;

            else if(rank[x_parent] < rank[y_parent])
                parent[x_parent] = y_parent;

            else{
                parent[x_parent] = y_parent;
                rank[y_parent] += 1;
            }

            this -> components -= 1; 
            /* Since we are doing union so that No. Components will also Decreases */
        }

        bool SingleComponent(){
            return this -> components == 1 ? true : false;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /* Sorting the edges w.r.t Type-3 Edge because that are common in Alice and Bob :) */
        sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b){
            return a.at(0) > b.at(0);
        });

        DISJOINT_SET_UNION Alice(n);
        DISJOINT_SET_UNION Bob(n);

        int Edge_Count = 0;

        for(auto &x : edges){
            int T = x[0];
            int U = x[1];
            int V = x[2];

            if(T == 3){
                bool Edge_Added = false;

                if(Alice.findParent(U) != Alice.findParent(V)){
                    Alice.UnionRank(U, V);
                    Edge_Added = true;
                }
                
                if(Bob.findParent(U) != Bob.findParent(V)){
                    Bob.UnionRank(U, V);
                    Edge_Added = true;
                }

                Edge_Count += Edge_Added ? 1 : 0;
            }
            else if(T == 2){
                if(Bob.findParent(U) != Bob.findParent(V)){
                    Bob.UnionRank(U, V);
                    Edge_Count += 1;
                }
            }
            else {
                if(Alice.findParent(U) != Alice.findParent(V)){
                    Alice.UnionRank(U, V);
                    Edge_Count += 1;
                }
            }
        }

        return Alice.SingleComponent() && Bob.SingleComponent() ? edges.size() - Edge_Count : -1;
    }
};
