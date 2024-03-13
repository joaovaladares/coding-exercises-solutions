class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int ans = 0;
        for (auto num : s) {
            if (!s.count(num - 1)) {
                int currLen = 1;
                while(s.count(num + currLen)) currLen++;
                ans = max(ans, currLen);
            }
        }

        return ans;
    }
};