#include <bits/stdc++.h> 
using namespace std;
struct Node{
    public:
        Node* links[26];
        bool flag = false;

    public:

        void put(char ch, Node* node){
           links[ch - 'a'] = node;
        }
    
        Node* get(char ch){
            return this -> links[ch - 'a'];
        }
        bool containsKey(char ch){
            return links[ch - 'a'] != NULL;
        }
        
        void setEnd(){
            this -> flag = true;
        }
        
        bool isEnd(){
            return this -> flag;
        }
    
};
// Time Complexity: O(N) * O(Length)
// Space Compleity: unpredictable because there is set 26 character and \ 
// for those 26 individually have another 26 charcters we having and it goes upto infinity :(/).

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* node = this -> root;
            for(int i = 0; i < word.size(); ++i){
                if(!node -> containsKey(word[i]))
                    node -> put(word[i], new Node());
                node = node -> get(word[i]);
            }
            node -> setEnd();
        }

        bool search(string word){
            Node* node = root;
            for(int i = 0; i < word.size(); ++i){
                if(!node -> containsKey(word[i]))
                    return false;
                
                node = node -> get(word[i]);
            }
            return node -> isEnd();
        }

        bool startsWith(string prefix){
            Node* node = root;
            for (int i = 0; i < prefix.size(); ++i) {
                if (!node->containsKey(prefix[i]))
                    return false;

                node = node->get(prefix[i]);
            }
            return true;
        }

        bool checkIfPrefixExists(string word){
            bool flag = true;
            Node* node = this -> root;
            
            for(int i = 0; i < word.size(); ++i){
                if(node -> containsKey(word[i])){
                    node = node -> get(word[i]);
                    flag = flag & node -> isEnd();
                }
                else
                    return false;
            }
            return flag;
        }

};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &x : a)
        trie.insert(x);
    
    string longest = "";

    for(auto &x : a){
        if(trie.checkIfPrefixExists(x)){
            if(x.length() > longest.length())
                longest = x;
            else if(x.length() == longest.length() && x < longest)
                longest = x;
        }
    }

    return longest == "" ? "None" : longest;
}
