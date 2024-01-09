// Search Pattern (KMP-Algorithm) Search Pattern (KMP-Algorithm)
// https://www.geeksforgeeks.org/problems/search-pattern0205/1

class Solution{
public:
    vector <int> search(string pat, string txt){
        int p=pat.length();
        int t=txt.length();
        vector<int>ans;
        int i=0;
        int j=1;
        int lps[p+1];
        for(int k=0 ; k<=p ; k++){
            lps[k]=0;
        }
        while(j<p){
            if (pat[i]==pat[j]){
                i++;
                lps[j]=i;
                j++;
            }
            else{
                if(i!=0){
                   i=lps[i-1];
                }
                else{
                    lps[j]=0;
                    j++;
                }
            }
        }
            
        i=0;
        j=0;
      
        while(i<t){
            if(pat[j]==txt[i]){
                i++;
                j++;
            }
            if(j==p){
                ans.push_back(i-j+1);
                j=lps[j-1];
            }
            
            else if(i<t && pat[j]!=txt[i]){
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        
        return ans;
    }
    
};
