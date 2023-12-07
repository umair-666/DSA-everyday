// Number of subarrays with maximum values in given range
// https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1

class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long long cnt = 0, ans = 0;
        int i = 0 , j = 0;
        while(j<n){
            if(a[j] >= L && a[j] <= R){
                cnt = j-i+1;
                ans +=cnt;   
            }
            else if(a[j] < L){
                ans += cnt;
            }
            else{
                i = j + 1;
                cnt = 0;
            }
            j++;
        }
        
        return ans;
    }
};
