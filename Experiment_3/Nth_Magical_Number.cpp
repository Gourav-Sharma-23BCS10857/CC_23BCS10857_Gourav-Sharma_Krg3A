//Nth Magical Number

class Solution {
public:
    int nthMagicalNumber(long long n, int a, int b) {
        const int MOD = 1e9 + 7;

        auto gcd = [&](long long x, long long y) {
            while (y) {
                long long t = x % y;
                x = y;
                y = t;
            }
            return x;
        };

        long long lcm = (long long)a * b / gcd(a, b);

        auto count = [&](long long x) {
            return x / a + x / b - x / lcm;
        };

        long long left = 1, right = n * min(a, b);
        while (left < right) {
            long long mid = (left + right) / 2;
            if (count(mid) < n)
                left = mid + 1;
            else
                right = mid;
        }

        return left % MOD;
    }
};
