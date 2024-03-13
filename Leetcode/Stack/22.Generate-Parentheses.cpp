class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(0, 0, n, "", ans);
        return ans;
    }

private:
    void backtrack(int openN, int closeN, int n, string s, vector<string>&ans) {
        if (s.length() == n * 2) {
            ans.push_back(s);
            return;
        }

        if (openN < n) {
            backtrack(openN + 1, closeN, n, s + '(', ans);
        }

        if (closeN < openN) {
            backtrack(openN, closeN + 1, n, s + ')', ans);
        }
    } 
};
 