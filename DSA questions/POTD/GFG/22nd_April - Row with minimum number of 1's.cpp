// Row with minimum number of 1's
// https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int ans=0,mini=INT_MAX;
        int count=0;
        for(int i=0;i<n;i++) {
            count=0;
            for(int j=0;j<m;j++) {
                if(a[i][j]==1) count++;
            }
            if(count<mini) {
                mini = count;
                ans = i;
            }
        }
        return ans+1;
    }
};
