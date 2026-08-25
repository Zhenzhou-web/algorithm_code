class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            if (s.count(x - 1)) continue;

            int len = 1;
            while (s.count(x + len)) {
                len++;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};
