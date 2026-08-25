class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int m=1;
        for(auto &num:nums){
            if(num==k*m)m++;
        }
        return k*m;
    }
};