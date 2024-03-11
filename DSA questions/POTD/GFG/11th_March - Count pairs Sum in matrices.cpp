// Count pairs Sum in matrices
// https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1

// Brute Force (TLE):
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int sum)
	{
	    int count = 0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            int a = mat1[i][j];
	            
	            for(int x=0;x<n;x++){
        	        for(int y=0;y<n;y++){
        	            int b = mat2[x][y];
        	            
        	            if(a+b == sum)
        	                count++;
	                }
	            }
	        }
	    }
	    return count;
	}
};

// Optimise:
class Solution{
public:	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x){
	     int count = 0;
        // Store frequencies of elements in mat1
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                freq[mat1[i][j]]++;
            }
        }
    
        // Check for complement elements in mat2
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int complement = x - mat2[i][j];
                if (freq.find(complement) != freq.end()) {
                    count += freq[complement];
                }
            }
        }
    
        return count;
	}
};
