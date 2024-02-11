// Recamans sequence
//  https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

class Solution{
public:
    vector<int> recamanSequence(int n){
        
        if(n == 1)  return {0};
        
        set<int> s; s.insert(0);
        vector<int> res; res.push_back(0);
      
        for(int i=1;i<=n;i++){
            int ele = res[i-1] - i;
            int num = res[i-1] + i;
            if( ele > 0 && s.find(ele) == s.end()){
                res.push_back(ele);
                s.insert(ele);
            }
            else{
                res.push_back(num);
                s.insert(num);
            }
        }
        
        return res;
    }
};
