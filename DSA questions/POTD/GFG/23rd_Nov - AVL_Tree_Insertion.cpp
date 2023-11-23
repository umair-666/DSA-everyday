class Solution{
   
    int getBalance(Node *N){  
        if (N == NULL)  
            return 0;  
        return height(N->left) - height(N->right);  
    }  
    
    int height(Node *N)  {  
        if (N == NULL)  
            return 0;  
        return N->height;  
    }
    
    Node *rightRotate(Node *y){  
        Node *x = y->left;  
        Node *T2 = x->right;  
      
        // Perform rotation  
        x->right = y;  
        y->left = T2;  
      
        // Update heights  
        y->height = max(height(y->left), 
                        height(y->right)) + 1;  
        x->height = max(height(x->left), 
                        height(x->right)) + 1;  
      
        // Return new root  
        return x;  
    }  
      
// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
    Node *leftRotate(Node *x){  
        Node *y = x->right;  
        Node *T2 = y->left;  
      
        // Perform rotation  
        y->left = x;  
        x->right = T2;  
      
        // Update heights  
        x->height = max(height(x->left),     
                        height(x->right)) + 1;  
        y->height = max(height(y->left),  
                        height(y->right)) + 1;  
      
        // Return new root  
        return y;  
    }  
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(!node)   return new Node(data);
        
        if(data<node->data)
            node->left = insertToAVL(node->left,data);
        else if(data > node->data)
            node->right = insertToAVL(node->right,data);
        else return node;
        
        node->height = 1 + max(height(node->left) , height(node->right));
        
        int balance = getBalance(node);
        
        
        //left left case
        if(balance > 1 && data < node->left->data)
            return rightRotate(node);
           
        //  right right case
        if(balance < -1 && data > node->right->data)
            return leftRotate(node);
        
        //left right case
        if(balance > 1 && data > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    
        //right left case
        if(balance < -1 && data < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
      
        return node;       
    }
