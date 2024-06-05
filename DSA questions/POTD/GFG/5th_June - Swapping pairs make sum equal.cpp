// Swapping pairs make sum equal
// https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a, a + n);
        sort(b, b + m);
        int sum1 = accumulate(a, a + n, 0);
        int sum2 = accumulate(b, b + m, 0);
        if ((sum1 - sum2) % 2 != 0)
            return -1;
        int i = 0;
        int j = 0;
        int target = (sum1 - sum2) / 2;
        while (i < n && j < m)
        {
            int diff = (a[i] - b[j]);
            if (diff == target)
                return 1;
            else if (diff < target)
                i++;
            else

                j++;
        }
        return -1;
    }
};
