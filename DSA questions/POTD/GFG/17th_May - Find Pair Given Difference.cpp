// Find Pair Given Difference
// https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        
        unordered_set<int>st;
        for(int i=0; i<n; i++){
            if(st.find(x+arr[i])!=st.end() || st.find(arr[i]-x)!=st.end()) return 1;
            st.insert(arr[i]);
        }
        return -1;
    }
};
