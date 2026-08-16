#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int number = 0;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Read sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Read digits
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';

            // Prevent 32-bit integer overflow
            if (number > INT_MAX / 10 ||
                (number == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            number = number * 10 + digit;
            i++;
        }

        return sign * number;
    }
};