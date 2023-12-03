// Brothers From Different Roots
// https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

// Approach 1:

 class Solution
{  
    void inorder(Node* root, vector<int> &bst){
        if(!root)   return;
        
        inorder(root->left, bst);
        bst.push_back(root->data);
        inorder(root->right,bst);
    }
    
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>  bst1 , bst2;
        inorder(root1,bst1);
        inorder(root2,bst2);
        
        int cnt = 0;
        
        int s = 0, e = bst2.size()-1;
        while(s < bst1.size() && e >= 0){
            int sum = bst1[s] + bst2[e];
            if(sum == x){
                cnt++;
                s++,e--;
            }
            else if(sum < x)
                s++;
            else e--;
        }
        return cnt;   
    }
};


***********----------------***************

// Approach 2 :

class Solution
{  
     void inorder(Node* root, vector<int> &bst){
        if(!root)   return;
        
        inorder(root->left, bst);
        bst.push_back(root->data);
        inorder(root->right,bst);
    }
    
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>  bst1 , bst2;
        inorder(root1,bst1);
        inorder(root2,bst2);
        
        int cnt = 0;
        unordered_map<int,int> mp1, mp2;
        
        for(int i=0;i<bst1.size();i++){
                mp1[ x - bst1[i] ]++;
            }
        for(int a = 0;a<bst2.size();a++){
            int moreNeeded = bst2[a];
           if(mp1.find(moreNeeded) != mp1.end())
                cnt++;
        }
        return cnt;
    }
};
