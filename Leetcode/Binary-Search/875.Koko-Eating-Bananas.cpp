class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;

        while (left < right) {
            int mid = left + (right - left) / 2; 
            long total = 0;

            for (int pile : piles) total += ceil(pile*1.0/mid);

            if (total > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};