// Minimize the Difference
// https://www.geeksforgeeks.org/problems/minimize-the-difference/1

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
         int maxSuffix[n + 1];
        int minSuffix[n + 1];
        maxSuffix[n] = -1e9;
        minSuffix[n] = 1e9;
        maxSuffix[n - 1] = arr[n - 1];
        minSuffix[n - 1] = arr[n - 1];
        
        for(int i = n - 2; i >= 0; i--){
            maxSuffix[i] = max(maxSuffix[i + 1], arr[i]);
            minSuffix[i] = min(minSuffix[i + 1], arr[i]);
        }
        
        int maxPrefix = arr[0];
        int minPrefix = arr[0];
        int minDiff = maxSuffix[k] - minSuffix[k];
        for(int i = 1; i < n; i++){
            if(i + k <= n){
                int maxi = max(maxSuffix[i + k], maxPrefix);
                int mini = min(minSuffix[i + k], minPrefix);
                minDiff = min(minDiff, maxi - mini);
            }
            maxPrefix = max(maxPrefix, arr[i]);
            minPrefix = min(minPrefix, arr[i]);
        }
        return minDiff;
    }
};
