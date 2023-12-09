// Smith Number
// https://www.geeksforgeeks.org/problems/smith-number4132/1

class Solution {
    bool isPrime(int num) {
        if (num <= 1) return false;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int sumofDigits(int num) {
        int sum = 0;
        while (num) {
            int d = num % 10;
            sum += d;
            num /= 10;
        }
        return sum;
    }

public:
    int smithNum(int n) {
        // Sum of digits
        if(isPrime(n))  return 0;
        
        int sum1 = sumofDigits(n);

        int psum = 0;
        // Prime factors
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0 && isPrime(i)) {
                psum += sumofDigits(i);
                n /= i;
            }
        }
        if (n > 1 && isPrime(n)) {
            psum += sumofDigits(n);
        }

        return sum1 == psum;
    }
};
