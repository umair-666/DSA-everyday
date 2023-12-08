// Transform to prime
// https://www.geeksforgeeks.org/problems/transform-to-prime4635/1

class Solution
{
    bool isPrime(int n){
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int minNumber(int arr[], int N){
        int sum = 0;
        for (int i = 0; i < N; ++i){
            sum += arr[i];
        }

        // Handle special cases
        if (sum <= 1)
            return 1;
        if (isPrime(sum))
            return 0;

        // Find the nearest prime greater than or equal to 'sum'
        int cnt = 0;
        for (int i = sum; !isPrime(i); ++i){
            ++cnt;
        }
        return cnt;
    }
};
