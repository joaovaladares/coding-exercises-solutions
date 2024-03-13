class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token.size() > 1 || isdigit(token[0])) {
                st.push(stoi(token));
                continue;
            }

            int num1 = st.top();
            st.pop(); 
            int num2 = st.top();
            st.pop();
            int res = 0;

            if (token == "+") res = num1 + num2;
            else if (token == "-") res = num2 - num1;
            else if (token == "*") res = num1 * num2;
            else res = num2 / num1;
            st.push(res);
        }

        return st.top();
        
    }
};