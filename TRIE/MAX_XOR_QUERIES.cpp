struct Node {
    Node* links[2];
    
    bool containsKey(int x) {
        return links[x] != NULL;
    }

    void put(int x, Node* node) {
        this->links[x] = node;
    }

    Node* get(int x) {
        return this->links[x];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        this->root = new Node();
    }

    void insert(int num) {
        Node* node = this->root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
                node->put(bit, new Node());

            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = this->root;
        int maxxor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit)) {
                maxxor |= (1 << i);
                node = node->get(!bit);
            }
            else
                node = node->get(bit);
        }
        return maxxor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<array<int, 3>> DS;
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            DS.push_back({ u, v, i });
        }

        auto comparator = [&](array<int, 3>& a, array<int, 3>& b) {
            return a[1] < b[1];
        };
        sort(DS.begin(), DS.end(), comparator);
        sort(nums.begin(), nums.end());

        vector<int> ans(queries.size(), 0);
        int index = 0;
        Trie trie;

        for (int i = 0; i < queries.size(); ++i) {
            while (index < nums.size() && nums[index] <= DS[i][1])
                trie.insert(nums[index++]);

            if (index == 0)
                ans[DS[i][2]] = -1;
            else
                ans[DS[i][2]] = trie.getMax(DS[i][0]);
        }
        return ans;
        /* Paved it :) */
    }
};
