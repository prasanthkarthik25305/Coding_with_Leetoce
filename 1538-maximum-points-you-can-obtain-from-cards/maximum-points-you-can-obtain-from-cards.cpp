class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right = 0, miny = 0, sum = 0, totsum = 0;
        for (auto i : cardPoints)
            totsum += i;
        for (int i = 0; i < (n - k); i++)
            sum += cardPoints[i];
        miny=sum;
        for (int i = (n - k); i < n; i++) {
            sum -= cardPoints[i - (n - k)];
            sum += cardPoints[i];
            miny = min(miny, sum);
        }
        return totsum - miny;
    }
};