class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maximumWater = 0;

        while (left < right) {
            int width = right - left;
            int containerHeight = min(height[left], height[right]);

            maximumWater = max(maximumWater, width * containerHeight);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maximumWater;
    }
};