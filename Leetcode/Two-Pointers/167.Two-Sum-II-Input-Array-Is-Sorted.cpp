class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0; 
        int r = numbers.size() - 1;
        vector<int> ans;
        while (l < r) {
            if ((numbers[l] + numbers[r]) == target) {
                ans = {l + 1, r + 1};
                break;
            }
            else if ((numbers[l] + numbers[r]) < target) l++;
            else r--;
        }

        return ans;
    }
};