//131. Palindrome Partitioning
//https://leetcode.com/problems/palindrome-partitioning/description/?envType=daily-question&envId=2024-05-22

class Solution {

    bool isPalin(string s,int start, int end){
        while(start<end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void func(string s, int index, vector<string> &path, vector<vector<string>> &ans){

        if(index == s.length()){    //base case
            ans.push_back(path);
            return;
        }

        for(int i=index;i<s.length();i++){
             if(isPalin(s,index,i)){  //if substr is palin, push into "path" && palin check krna h toh indexes bhejo naki pura substring banakr, aise easy hoga
                 path.push_back(s.substr(index,i-index+1));
                 func(s,i+1,path,ans);
                 path.pop_back();   //backtrack
             }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        func(s,0,path, ans);
        return ans;
    }
};
