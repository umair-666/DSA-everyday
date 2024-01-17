// 1207.Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

// Approach 1 : TC = O(N*N) SC= O(N)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;

        for (auto it : arr)
            mp[it]++;

        for (auto it : mp) {
            int num = it.first;
            int occ = it.second;

            for (auto i = mp.begin(); i != mp.end(); ++i) {
                if (num != i->first && occ == i->second)
                    return false;
            }
        }
        return true;
    }
};

// Approach 2 : TC = O(N) SC = O(N)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto x : m ){
            int freq = x.second;
            if(s.find(freq) != s.end()) return false;
            else{
                s.insert(freq);
            }
        }
        return true;
    }
};
