// Maximum occured integer
// https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1

class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {

        unordered_map<int, int> mp;
    
        for (int i = 0; i < n; ++i) {
            mp[l[i]] += 1;
            mp[r[i] + 1] -= 1;
        }
    
        int max_occurrences = 0;
        int max_occurred_element = INT_MIN;
        int current_count = 0;
    
        for (int i = 0; i <= maxx; ++i) {
            current_count += mp[i];
            if (current_count > max_occurrences) {
                max_occurrences = current_count;
                max_occurred_element = i;
            }
        }
    
        return max_occurred_element;

    }
};
