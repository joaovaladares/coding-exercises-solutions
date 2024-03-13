class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};

        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                if (board[i][j] == '.') continue;

                int index = board[i][j] - '0' - 1;
                int area = (i/3) * 3 + (j/3);

                if (row[i][index] || col[j][index] || sub[area][index]) return false;

                row[i][index] = true;
                col[j][index] = true;
                sub[area][index] = true;
            }
        }

        return true;
    
    }
};