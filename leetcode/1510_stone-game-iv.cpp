class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> judge(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                int s = k * k;
                if (!judge[i - s]) {
                    judge[i] = true;
                    break;
                }
            }
        }
        return judge[n];
    }
};
