// Power Set
// https://www.geeksforgeeks.org/problems/power-set4302/1

//Approach 1 -
class Solution{
	void fun(int i, string p, string s, vector<string> &v){
	    if(i==s.length()){
               v.push_back(p);
               return ;
	    }
	    
	    fun(i+1, p, s, v); // include
	    fun(i+1, p+s[i], s, v); // exclude
	}
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> v;
            for(int i=0;i<s.length();i++){
                string p;
                p.append(1,s[i]);
                fun(i+1, p, s,v);
            
            }
            
            sort(v.begin(),v.end());
            return v;
		}
};

// Approach 2 - 
class Solution{
	public:
	    vector<string> AllPossibleStrings(string s){
		    vector<string> v;
		    int n = s.length();
		    for (int i = 0; i < pow(2,n); i++) {
		        string sub;
		        for (int j = 0; j < n; j++) {
		            if (i & 1 << j) {
		                sub += s[j];
		            }
		        }
		        if (!sub.empty()) v.push_back(sub);
		    }
		    sort(v.begin(), v.end());
		    return v;
		}
};
