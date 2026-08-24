class Solution {
public:
    long long gcd(long long a, long long b) {
        a = abs(a);
        b = abs(b);
        while(b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long maxPairStrength(vector<int>& nums) {
        long long res = LLONG_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long mul = (long long)nums[i] * nums[j];
                long long ma = gcd(nums[i], nums[j]);
                long long strength = mul / (ma * ma);
                if(strength > res) res = strength;
            }
        }
        return res;
    }
};
