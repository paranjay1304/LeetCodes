class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long a = dividend;
        long long b = divisor;

        bool negative = (a < 0) != (b < 0);

        a = (a < 0) ? -a : a;
        b = (b < 0) ? -b : b;

        long long quotient = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};