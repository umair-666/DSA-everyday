// Sum-string
// https://www.geeksforgeeks.org/problems/sum-string3151/1

class Solution{
    void add(string &tf, string &ts) {
        string ans = "";
        int i=tf.size()-1, j=ts.size()-1, c = 0;
        for( ; i>=0 && j>=0 ; i--,j--) {
            int val = (tf[i]-'0' + ts[j]-'0' + c);
            c = val/10;
            char to_push = (val%10)+'0';
            ans.push_back(to_push);
        }
        while(i>=0) {
            int val = (tf[i--]-'0' + c);
            c = val/10;
            char to_push = (val%10)+'0';
            ans.push_back(to_push);
        }
        while(j>=0) {
            int val = (ts[j--]-'0' + c);
            c = val/10;
            char to_push = (val%10)+'0';
            ans.push_back(to_push);
        }
        if(c) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        tf = ts;
        ts = ans;
    }
    bool check(string &f, string &s, string &S, int pos) {
        if(pos>=S.length()) return true;
        add(f,s);
        bool out = s == S.substr(pos,s.length());
        if(out) return check(f,s,S,pos+s.length());
        return false;
    }
public:
    int isSumString(string S){
        // code here 
         int n = S.length();
        for(int i=0 ; i<n-2; i++) {
            string f = S.substr(0,i+1);
            for(int j=i+1 ; j<n-1; j++) {
                int sz = j-i;
                string s = S.substr(i+1,sz);
                string tf = f, ts = s;
                if(check(tf,ts,S,j+1)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};
