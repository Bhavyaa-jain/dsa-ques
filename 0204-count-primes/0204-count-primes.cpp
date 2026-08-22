class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        
        vector<bool> isPrime(n, true);
        
        int count = 1; 

        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
                
                if (i <= (n - 1) / i) {
                    for (int j = i * i; j < n; j += 2 * i) {
                        isPrime[j] = false;
                    }
                }
            }
        }

        return count;
    }
};