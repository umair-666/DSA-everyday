// Largest Sum Subarray of Size at least K
// https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1


class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int currentSum = 0;
        long long int maxSum = INT_MIN;
        long long int accumulatedNegative = 0;
    
        for (int start = 0, end = 0; end < n;) 
        {
            currentSum += a[end];
    
            if (end - start + 1 < k) 
            {
                ++end;
            } 
            
            else if (end - start + 1 == k) 
            {
                maxSum = max(maxSum, currentSum);
                ++end;
            } 
            
            else 
            {
                maxSum = max(maxSum, currentSum);
                accumulatedNegative += a[start++];
    
                if (accumulatedNegative < 0) 
                {
                    currentSum -= accumulatedNegative;
                    maxSum = max(maxSum, currentSum);
                    accumulatedNegative = 0;
                }
    
                ++end;
            }
        }
    
        return maxSum;
    }
};

