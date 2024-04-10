// Party of Couples
// https://www.geeksforgeeks.org/problems/alone-in-couple5507/1

class Solution{
    public:
    int findSingle(int n, int arr[]){
        int xorr = 0;
        for(int i=0;i<n;i++){
            xorr ^= arr[i];
        }
        return xorr;
    }
};
