class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> st;

        st.push({temperatures[0], 0});

        for (int i = 1; i < temperatures.size(); i++) {
            while(!st.empty() && temperatures[i] > st.top().first) {
                int index = st.top().second;
                st.pop();
                ans[index] = i - index;
            }

            st.push({temperatures[i], i});
        }

        return ans;
    }
};