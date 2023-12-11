// Max Sum Subarray of size K
// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

//Sliding Window Used
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i = 0, j = 0;
        long sum = 0, maxi = -1e9;
        
        while(j < N){
            sum +=Arr[j];
            if(j-i+1 < K)
                j++;
            else if(j-i+1 == K){
                maxi = max(maxi , sum);
                sum -=Arr[i];
                i++;j++;
            }
        }
        return maxi;
    }
};
