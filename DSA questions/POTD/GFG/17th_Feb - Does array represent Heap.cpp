// Does array represent Heap
// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // last node is at (n/2)-1
        for(int i=0;i<=(n/2)-1;i++){
            if(2*i+1 < n){ //left child
                if(arr[2*i+1] > arr[i])
                    return false;
            }
            if(2*i+2 < n){ //right child
                if(arr[2*i+2] > arr[i])
                    return false;
            }
        }
        return true;
    }
};
