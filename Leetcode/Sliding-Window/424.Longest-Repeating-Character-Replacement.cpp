class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int l = 0;
        int ans = 0;
        int mostFrequent = 0;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;

            for (auto x : mp) mostFrequent = max(mostFrequent, x.second);
            if ((r - l + 1) - mostFrequent <= k) {
                ans = max(ans, r - l + 1);
            } else {
                while ((r - l + 1) - mostFrequent > k) {
                    mp[s[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};