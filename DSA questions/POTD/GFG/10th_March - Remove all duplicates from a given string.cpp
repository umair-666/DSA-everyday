// Remove all duplicates from a given string
// https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

class Solution{
public:
	string removeDuplicates(string str) {
	    unordered_set<char> seen;
	    string res;
	    for (char c : str) {
            if (seen.find(c) == seen.end()) { // If c is not in the set
                res += c; // Add c to the result string
                seen.insert(c); // Add c to the set
            }
	    }
	    return res;
	}
};
