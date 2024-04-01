// Pairs violating the BST property
// https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1

// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
    int ans = 0;
    int merge(vector<int> &arr, int st, int mid, int end){
        vector<int> temp1,temp2;
        for(int i=st;i<=mid;i++) temp1.push_back(arr[i]);
        for(int i=mid+1;i<=end;i++) temp2.push_back(arr[i]);
      
        int i=0; int j=0; int k= st;
        while(i<temp1.size() && j<temp2.size() && k<=end){
            if(temp1[i]<=temp2[j]){
                arr[k]=temp1[i];
                i++;
                k++;
            }
            else {
                ans += (temp1.size()-i);
                arr[k]= temp2[j];
                j++;
                k++;
            }
        }
        while(i<temp1.size() && k<=end){
            arr[k]=temp1[i];
            i++;
            k++;
        }
        while(j<temp2.size() && k<=end){
            arr[k]=temp2[j];
            j++;
            k++;
        }  
    }
    
    // function for mergeSort
    void mergeSort(vector<int> &arr, int st, int end){
        if(st>=end) return;
        int mid = (st+end)/2;
        mergeSort(arr,st,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,st,mid,end);
    }
    void inorder(vector<int> &arr,Node* root){
        if(root==NULL) return;
        inorder(arr,root->left);
        arr.push_back(root->data);
        inorder(arr,root->right);
    }
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        
        vector<int> arr;
        inorder(arr,root);
        mergeSort(arr,0,n-1);
        return ans;
        
    }
};
