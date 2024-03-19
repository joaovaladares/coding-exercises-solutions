class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int newSlow = 0;

        while (slow != newSlow) {
            slow = nums[slow];
            newSlow = nums[newSlow];
        }

        return slow;
    }
};