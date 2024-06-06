// Max sum in the configuration
// https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        
        long sum =0;
        long prev = 0;
        for(int i=0; i<n; i++){
            prev += (long)i*a[i];
            sum+=a[i];
        }
        long ans =prev;
        
        for(int i=1; i<n; i++){
            long curr = prev - (sum - a[i-1]) + (long)a[i-1]*(n-1);
            prev = curr;
            
            ans = max(ans, curr);
        }
        return ans;
    }
};
