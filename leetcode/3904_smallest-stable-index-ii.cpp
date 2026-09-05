class Solution {
public:
    int firstStableIndex(const vector<int>& nums, int k) {
        if (nums.empty()) {
            return -1;
        }
        int n = static_cast<int>(nums.size());
        vector<int> minres(n);
        minres[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < minres[i + 1]) {
                minres[i] = nums[i];
            } else {
                minres[i] = minres[i + 1];
            }
        }

        int max_val = nums[0];
        for (int i = 0; i < n; ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
            if (max_val - minres[i] <= k) {
                return i;
            }
        }
        return -1;
    }
};
