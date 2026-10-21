class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> count(n * n + 1, 0);

        for (auto& row : grid) {
            for (int value : row) {
                count[value]++;
            }
        }

        int repeated = -1, missing = -1;

        for (int i = 1; i <= n * n; i++) {
            if (count[i] == 2) repeated = i;
            else if (count[i] == 0) missing = i;
        }

        return {repeated, missing};
    }
};