// Exit Point in a Matrix
// https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
         vector<char>dir={'r','d','l','u'};
       int k=0;
       int i=0,j=0;
       vector<int>ans(2,0);
       
       while(i>=0 && j>=0 && i<n && j<m)
       {
           ans[0]=i;
           ans[1]=j;
           if(matrix[i][j]==1)
           {
               k++;
               k=k%4;
               matrix[i][j]=0;
           }
          if(dir[k]=='r')
                   j++;
          else if(dir[k]=='d')
                  i++;
          else if(dir[k]=='l')
                     j--;
          else
                   i--;
       }
       return ans;
    }
};
