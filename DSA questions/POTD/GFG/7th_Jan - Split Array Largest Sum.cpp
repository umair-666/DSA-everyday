// Split Array Largest Sum
// https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

 class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < N; i++) {
            start = std::max(start, arr[i]);
            end += arr[i];
        }
        
         // Binary search
        while (start < end) {
            // Try the middle element as a potential answer
            int mid = start + (end - start) / 2;

            // Calculate how many pieces you can divide this into with the max sum
            int sum = 0;
            int pieces = 1; // At least 1 is allowed

            for (int j = 0; j < N; j++) {
                int n = arr[j];

                if (sum + n > mid) {
                    // You cannot add this to the subarray, make a new one
                    // If you add this n to a new subarray, then sum = n
                    sum = n;
                    pieces++;
                } else {
                    sum += n;
                }
            }

            if (pieces > K) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return end; // Here start == end
    }
};
