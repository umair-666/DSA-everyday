// Gray to Binary equivalent
// https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n){
        int ans=0,k=n,t=0;
        for(int i=32;i>=0;i--){
            if(k>=pow(2,i)){
                if(n>=pow(2,i)){
                    if(t==0){
                        ans+=pow(2,i);
                        t=1;
                    }
                    else{
                        t=0;
                    }
                        
                n-=pow(2,i);
                }
            else{
                if(t==1)
                    {
                        ans+=pow(2,i);
                        t=1;
                  }
                else{
                    t=0;
                }
            }
        }
    }
        return ans;
    }
};
