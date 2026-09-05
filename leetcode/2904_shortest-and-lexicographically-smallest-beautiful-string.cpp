class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, oneCnt = 0;
        string ans = "";
        for (int r = 0; r < n; r++) {
            if (s[r] == '1') oneCnt++;
            while (oneCnt == k) {
                string cur = s.substr(l, r - l + 1);
                if (ans.empty() || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }
                if (s[l] == '1') oneCnt--;
                l++;
            }
        }
        return ans;
    }
};
