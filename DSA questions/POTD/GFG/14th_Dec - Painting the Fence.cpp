// Painting the Fence
// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

//Most optimised code:

class Solution{
public:
    int mod = 1e9+7;
    long long countWays(int n, int k){
        long long res=1;
        long long prev=1;
        for(int i=1;i<n;i++){
            long long temp=(k-1)*res;
            res=(prev+temp)%mod;
            prev=temp;
        }
        return (res*k)%mod;
    }
};
