class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);

        ans[0] = 1;
        ans[nums.size() - 1] = 1;
        int postfix = 1;

        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) { 
            ans[i] *= postfix;
            postfix *= nums[i];
        }        

        return ans;
    }
};