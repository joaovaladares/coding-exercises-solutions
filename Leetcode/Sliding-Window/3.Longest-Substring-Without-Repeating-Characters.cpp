class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return 1;

        unordered_set<char> st;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            if (st.count(s[r])) {
                while (st.count(s[r])) {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            } else {
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};