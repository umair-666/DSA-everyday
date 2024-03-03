// Largest Number formed from an Array
// https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

class Solution{
public:
static bool cmp(string &s1,string &s2){
        return s1+s2>s2+s1;
    }
    string printLargest(int n, vector<string> &arr) {
        // code here
        sort(arr.begin(),arr.end(),cmp);
        string ans="";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
        }return ans;
    }
};
