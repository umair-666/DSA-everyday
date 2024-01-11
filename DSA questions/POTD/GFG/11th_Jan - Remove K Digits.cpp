// Remove K Digits
// https://www.geeksforgeeks.org/problems/remove-k-digits/1

 // User function Template for C++

class Solution {
     string removeZero(string str) { 
    int i = 0; 
    while (str[i] == '0') 
        i++; 
    str.erase(0, i); 
  
    return str; 
} 
  public:
    string removeKdigits(string S, int K) {
        stack<char>st;
        int n=K;
        int i=0;
        while(i<S.size()){
            
            if(st.empty()){
                st.push(S[i]);
            }
            else if(st.top()>S[i] && K>0){
                while(!st.empty() && st.top()>S[i] && K>0){
                    // cout<<st.top()<<"->";
                    st.pop();
                    K--;
                }
                st.push(S[i]);
            }else{
                st.push(S[i]);
            }
            i++;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()+n>S.size())
        ans.resize(S.size()-n);
        ans=removeZero(ans);
        if(ans=="")return "0";
        return ans;
    }
};
