// Candy
// https://www.geeksforgeeks.org/problems/candy/1

class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int>a(N,1);
        int ans=0;
        for(int i=1;i<N;i++){
            if(ratings[i]>ratings[i-1]){
                a[i]=a[i-1]+1;
            }
        }
        for(int i=N-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]&&a[i]<=a[i+1]){
                a[i]=a[i+1]+1;
            }
        }
        
        for(int i=0;i<N;i++) 
            ans+=a[i];
            
        return ans;
        
    }
};
