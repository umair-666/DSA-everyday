// Minimize the Heights II
 // https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        
        sort(arr,arr+n);
        
        int maxi = arr[n-1];
        int mini =arr[0];
        int ans = maxi - mini;  //store the initial diff of maxi - mini
        
        //now go check if there exists a more smaller value for maxi-mini
        for(int i=1;i<n;i++){
            if (arr[i] - k >= 0){
                maxi = max(arr[i-1] + k, arr[n-1] - k);
                mini = min(arr[0] + k , arr[i] - k);
                ans = min(ans, maxi-mini);
            }
        }
        
        return ans;
    }
};
