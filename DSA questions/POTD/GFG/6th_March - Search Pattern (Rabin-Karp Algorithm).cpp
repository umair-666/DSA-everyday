// Search Pattern (Rabin-Karp Algorithm)
// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> v;
             int n = pattern.length();
            int m = text.length();
            for (int i = 0; i <= m - n; ++i) {
                if (text.substr(i, n) == pattern) 
                    v.push_back(i + 1);
            }
            
            return v;
        }
     
};
