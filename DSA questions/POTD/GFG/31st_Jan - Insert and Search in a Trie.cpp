// Insert and Search in a Trie
// https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

// Approach 1: two line code :-

class Solution{
    public:
        unordered_map<string , bool> mp;

        void insert(struct TrieNode *root, string key){
            mp[key] = 1;
        }
        
        bool search(struct TrieNode *root, string key) {
            return mp[key];
        }
};

// Approach 2:

class Solution{
    public:
        unordered_map<string , bool> mp;

        void insert(struct TrieNode *root, string key){
            TrieNode* x = root;
            for(int i=0;i<key.size();i++){
                char ch = key[i];
                if(x->children[ch-'a']==NULL){
                    TrieNode* y = getNode();
                    x->children[ch-'a'] = y;
                    x = y;
                }
                else{
                    x = x->children[ch-'a'];
                }
            }
            x->isLeaf = true;
        }
        
        bool search(struct TrieNode *root, string key) {
            TrieNode* x = root;
            for(int i=0;i<key.size();i++){
                char ch = key[i];
                if(x->children[ch-'a']==NULL){
                    return false;
                }
                x = x->children[ch-'a'];
            }
            return x->isLeaf;
        }
};
