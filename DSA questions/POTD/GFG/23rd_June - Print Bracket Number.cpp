// Print Bracket Number
// https://www.geeksforgeeks.org/problems/print-bracket-number4058/1?timeMachineDate=2024-06-23

class Solution {
  public:

    vector<int> bracketNumbers(string str) {
       stack<int>s;
        
        vector<int>v;
        int cnt=1;
        for(int i=0;i<str.length();i++){
            
            if(str[i]=='('){
                s.push(cnt);
                v.push_back(cnt);
                cnt++;
            }
            if(str[i]==')'){
                int x=s.top();
                s.pop();
                v.push_back(x);
            }
        }
        
        return v;
    }
};
