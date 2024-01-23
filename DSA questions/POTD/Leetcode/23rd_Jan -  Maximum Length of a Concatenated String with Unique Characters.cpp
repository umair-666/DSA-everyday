//1239. Maximum Length of a Concatenated String with Unique Characters
//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

class Solution {
public:
    int maxLength(const vector<string>& arr) {
        int ans = 0;
        dfs(arr, "", 0, ans);
        return ans;
    }

private:
    void dfs(const vector<string>& arr, const string& path, int idx, int& ans) {
        if (isUniqueChars(path)) {
            ans = max(ans, static_cast<int>(path.length()));
        }

        if (idx == arr.size() || !isUniqueChars(path)) {
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, ans);
        }
    }

    bool isUniqueChars(const string& s) {
        unordered_set<char> set(s.begin(), s.end());
        return s.length() == set.size();
    }
};
