// Two Repeated Elements
// https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
       
       vector<int> v;
       unordered_map<int,int> mp;
       
        for(int i=0;i<n+2;i++){
            mp[arr[i]]++;
                if(mp.count(arr[i]) !=0 && mp[arr[i]] == 2){
                    v.push_back(arr[i]);
                }
        }
       
       return v;
    }
};
