class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        if (nums[0] > 0) return {};

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) l++;
                else if (sum > 0) r--;
                else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    r--;
                    while(r > l && nums[r] == nums[r + 1]) r--;
                }  
            } 
        }
        return ans;
    }
};