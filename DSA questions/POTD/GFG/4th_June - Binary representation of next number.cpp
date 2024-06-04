// Binary representation of next number
// https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

class Solution {
  public:
    string binaryNextNumber(string s) {
        int j=0;
        while(s[j]=='0'&& j<s.size()){
            j++;
        }
        string ans="";
        int carry=1;
        for(int i=s.size()-1;i>=j;i--){
            int sum=carry+(s[i]-'0');
            if(sum==2){
                
                ans='0'+ans;
                carry=1;
            }
            else {
                char ch=sum+'0';
                ans=ch+ans;
                carry=0;
                
            }
            
        }
        if(carry){
            ans='1'+ans;
        }
        return ans;
    }
};
