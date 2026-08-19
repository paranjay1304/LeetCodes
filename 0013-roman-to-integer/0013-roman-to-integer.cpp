class Solution {
public:
    int romanToInt(string s) {
        int total = 0;

        for (int i = 0; i < s.size(); i++) {
            int value = getValue(s[i]);

            if (i + 1 < s.size() && value < getValue(s[i + 1])) {
                total -= value;
            } else {
                total += value;
            }
        }

        return total;
    }

private:
    int getValue(char c) {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        return 1000; // M
    }
};