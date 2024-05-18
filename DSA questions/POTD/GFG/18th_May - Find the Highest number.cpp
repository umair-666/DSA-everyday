// Find the Highest number
// https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1

// Approach 1:
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
         int ans = INT_MIN;
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] > ans){
                ans = a[i];
            }
        }
        return ans;
    }
};

// Approach 2:
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
       return *max_element(a.begin(), a.end());
    }
};

