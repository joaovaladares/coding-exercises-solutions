class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (auto str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            mp[sorted].push_back(str);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }

        return ans;
    }
};