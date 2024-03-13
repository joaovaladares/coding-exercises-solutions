class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto num : nums) {
            mp[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto x : mp) {
            bucket[x.second].push_back(x.first);
        }

        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (auto num : bucket[i]) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};