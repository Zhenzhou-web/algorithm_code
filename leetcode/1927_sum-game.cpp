class Solution {
    pair<int, int> calc(string_view s) {
        int q = 0, sum = 0;
        for (char ch : s) {
            if (ch == '?') {
                q++;
            } else {
                sum += ch - '0';
            }
        }
        return {q, sum};
    }

public:
    bool sumGame(string num) {
        int n = num.size();
        string_view s(num); // string_view 的 substr 是 O(1) 切片
        auto [ql, sum_l] = calc(s.substr(0, n / 2));
        auto [qr, sum_r] = calc(s.substr(n / 2));
        return (ql + qr) % 2 || (ql - qr) / 2 * 9 != sum_r - sum_l;
    }
};
