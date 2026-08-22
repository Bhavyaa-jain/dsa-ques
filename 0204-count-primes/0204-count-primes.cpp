class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // Remove even numbers
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }

        // Sieve only odd numbers
        for (int i = 3; i <= n / i; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};