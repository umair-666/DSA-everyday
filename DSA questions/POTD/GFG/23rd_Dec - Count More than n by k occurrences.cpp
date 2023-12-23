// Count More than n/k occurences
// https://www.geeksforgeeks.org/problems/count-element-occurences/1

//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        int lim = n/k;
        unordered_map<int,int> mp;
        
        for(int i = 0;i<n;i++){
            mp[arr[i]]++;
        }
            
        
        int cnt = 0;
        for(auto i : mp){
            if(i.second > lim)
                cnt++;
        }
        return cnt;
    }
};
