// Count the elements
// https://www.geeksforgeeks.org/problems/count-the-elements1529/1

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
          vector<int> v;
       sort(b.begin(), b.end());
       for(int i = 0; i < q; i++) {
           int index = query[i];
           int target = a[index];
           int l = 0;
           int r = n - 1;
           while(l <= r) {
               int mid = (l + r) / 2;
               if(b[mid] <= target) {
                   l = mid + 1;
               } else {
                   r = mid - 1;
               }
           }
           v.push_back(l);
       }
       return v;
    }
};
