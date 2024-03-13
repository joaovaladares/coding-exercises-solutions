class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') st1.push(ch);
            else {
                if (st1.empty()) return false;
                if ((ch == ')') && (st1.top() == '(')) st1.pop();
                else if ((ch == ']') && (st1.top() == '[')) st1.pop();
                else if ((ch == '}') && (st1.top() == '{')) st1.pop();
                else return false;
            }
        }
        return st1.empty();
    }
};