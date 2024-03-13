class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1, mid = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (target < matrix[mid][0]) high = mid - 1;
            else if (target > matrix[mid][matrix[0].size() - 1]) low = mid + 1;
            else if (target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size() - 1]) {
                int l = 0, r = matrix[mid].size() - 1, m = 0;

                while (l <= r) {
                    m = l + (r - l) / 2;

                    if (matrix[mid][m] == target) return true;
                    else if (matrix[mid][m] > target) r = m - 1;
                    else l = m + 1; 
                }

                return false;
            }
        }

        return false;
    }
};