// Maximum Index
// https://www.geeksforgeeks.org/problems/maximum-index-1587115620/1

class Solution{
    public:
    int maxIndexDiff(int a[], int n) 
    { 
        int i = 0 , j = n-1;
        int res = INT_MIN;
        
        while(i < n){
            if(a[i] > a[j]){
                j--;
            }
            else{
                res = max(res, j-i);
                j = n - 1;
                i++;
            }
        }
        return res;
    }
};
