// Subarray with 0 sum
// https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution{
    public:
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n){
        int i = 0 , j = 0;
        int sum = 0;
        while(j<n){
            if(arr[j] == 0)     return true;
            
            sum +=arr[j];
            
            if(sum == 0)
                return true;
            else j++;
        
            if(j==n){
                i++;
                j = i;
                sum = 0;
            }
        }
        return false;
    }
};
