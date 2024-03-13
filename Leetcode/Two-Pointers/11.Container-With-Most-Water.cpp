class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int currMax = 0;

        while(l < r) {
            currMax = max(currMax, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }   

        return currMax;
    }
};