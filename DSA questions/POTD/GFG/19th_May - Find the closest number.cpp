// Find the closest number
// https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int low = 0;
        int high = n-1;
        int ans = 0;
        int ans2 = 0;
        while(low <= high){
            int mid = low + (high -low)/2;
            if(arr[mid] <= k){
                ans = arr[mid];
                low = mid+1;
            }
            else{
                ans2 = arr[mid];
                high = mid - 1;
            }
        }
        
        if(abs(ans-k) < abs(ans2-k)){
            return ans;
        }
        return ans2;
    } 
};
