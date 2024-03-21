// ZigZag Tree Traversal
// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root){
        vector<int>res;
    	  if(!root)   return res;
    	
        queue<Node*> q;
        q.push(root);
        
        bool leftToRight = true;
        
        while(!q.empty()){
            
            int size = q.size(); //size of  nth level
            vector<int>ans(size);
            
            //level process
            for(int i=0;i<size;i++){
                Node* frontNode = q.front();
                q.pop();
                
                //normal insert or reverse insert
               int index = leftToRight ? i : size-i-1;
                ans[index] = frontNode->data;
                
                if(frontNode->left)
                    q.push(frontNode->left);
                   
                if(frontNode->right)
                    q.push(frontNode->right);
            }
                //change direction
                leftToRight = !leftToRight;
                
                for(auto x:ans)
    	            res.push_back(x);
            }
        
    	return res;
    	
    }
};
