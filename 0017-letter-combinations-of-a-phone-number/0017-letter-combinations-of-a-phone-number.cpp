class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> ans = {""};
        vector<string> letters = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        for (char digit : digits) {
            vector<string> next;

            for (string s : ans) {
                for (char ch : letters[digit - '0']) {
                    next.push_back(s + ch);
                }
            }

            ans = next;
        }

        return ans;
    }
};