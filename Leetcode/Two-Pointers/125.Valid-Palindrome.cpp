class Solution {
public:
    bool isPalindrome(string s) {
        
        string t = "";
        for (auto ch : s) {
            char chLow = tolower(ch);
            if (isalnum(chLow)) t += chLow;
        }

        int l = 0, r = t.length()-1;

        while (l <= r) {
            if (t[l] != t[r]) return false;
            l++;
            r--;
        } 

        return true;
    }
};