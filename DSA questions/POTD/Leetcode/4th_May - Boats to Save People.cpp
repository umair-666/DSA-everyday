// 881. Boats to Save People
// https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int cnt = 0;
        sort(people.begin(), people.end());
        int i=0;int j = people.size()-1;
            while(i<=j){
            if(people[i] + people[j] <= limit)
                i++;
            j--;
            cnt++;
        }

        return cnt;
    }
};
