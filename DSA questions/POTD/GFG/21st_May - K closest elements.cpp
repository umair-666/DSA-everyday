// K closest elements
// https://www.geeksforgeeks.org/problems/k-closest-elements3619/1

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> ans;
        
        map<int, priority_queue<int>>m;
        
        for(int i=0;i<n;i++){
            if(arr[i]!=x) m[abs(arr[i]-x)].push(arr[i]);
        }
        
        for(auto it:m){
            if(k==0) return ans;
            
            auto pq = it.second;
            while(k>0 && !pq.empty()){
                ans.push_back(pq.top());
                pq.pop();
                k--;
            }
        }
        
        return ans;
    }
};
