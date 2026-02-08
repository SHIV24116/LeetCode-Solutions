class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int points = 0;
        for(int i = 0; i < k; i++)
            points += cardPoints[i];

        int ans = points;

        int l = k - 1;   // remove from the end of prefix

        for(int i = n - 1; i >= n - k; i--) {
            points += cardPoints[i] - cardPoints[l];
            l--;
            ans = max(ans, points);
        }

        return ans;
    }
};
