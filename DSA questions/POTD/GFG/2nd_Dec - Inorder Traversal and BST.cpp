// Inorder Traversal and BST
// https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1

class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        //sorted hona chaiye array
        
        for(int i=1;i<N;i++){
            if(arr[i] < arr[i-1])
                return 0;
        }
        return 1;
    }
};

