// 2149. Rearrange Array Elements by Sign
//  https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p, n, res;

        for(auto it : nums){
            if(it < 0)
                n.push_back(it);
            else
            p.push_back(it);
        }

        for(int i=0;i<nums.size()/2;i++){
            res.push_back(p[i]);
            res.push_back(n[i]);
        }

        return res;
        
    }
};
