// Sum of bit differences
// https://www.geeksforgeeks.org/problems/sum-of-bit-differences2937/1

class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	     long long res = 0;
	    
	    for(int bit = 1; bit < 32; bit++) {
	        long long one = 0, zero = 0;
	        
	        for(int i = 0; i < n; i++) {
	            if(arr[i] & 1) one++;
	            else zero++;
	            
	            arr[i] = arr[i] >> 1;
	        }
	        
	        res = res + (one * zero);
	    }
	    
	    res = res * 2;
	    return res;
	}
};
