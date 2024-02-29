// Sum of bit differences
// https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	     long long ans = 0;
	    
	    for(int bit = 1; bit < 32; bit++) {
	        long long one = 0, zero = 0;
	        
	        for(int i = 0; i < n; i++) {
	            if(arr[i] & 1) one++;
	            else zero++;
	            
	            arr[i] = arr[i] >> 1;
	        }
	        
	        ans = ans + (one * zero);
	    }
	    
	    ans = ans * 2;
	    return ans;
	}
};
