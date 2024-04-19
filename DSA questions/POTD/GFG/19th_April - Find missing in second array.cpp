// Find missing in second array
// https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

class Solution{
public:
	vector<int> findMissing(int a[], int b[], int n, int m) {
        vector<int> v;
        // map to store elements of b
        unordered_set<int> hash;
        for (int i = 0; i < m; i++) {
            hash.insert(b[i]);
        }
    
        // Iterate through a and check if element exists in hash table
        for (int i = 0; i < n; i++) {
            if (hash.find(a[i]) == hash.end()) {
            v.push_back(a[i]);
            }
        }
        return v;
}
};

	
