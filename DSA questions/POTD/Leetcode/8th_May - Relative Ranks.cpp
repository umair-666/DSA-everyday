// 506.  Relative Ranks
// https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);
        int maxi = 0;
        for(int i : score){
            maxi = max(maxi , i);
        }
        int rank = 0;
        vector<int> v(maxi+1 , -1);
        for(int i=0; i<n; i++){
            v[score[i]] = i;
        }
        for(int i=maxi; i>=0; i--){
            if(v[i] != -1){
                switch(rank){
                    case 0:
                        res[v[i]] = "Gold Medal";
                        break;
                    case 1:
                        res[v[i]] = "Silver Medal";
                        break;
                    case 2:
                        res[v[i]] = "Bronze Medal";
                        break;
                    default:
                        res[v[i]] = to_string(rank+1);
                        break;
                }
                rank++;
            }
        }
        return res;
    }
};
