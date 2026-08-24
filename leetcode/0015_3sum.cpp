class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=n-1;
            while(k>j){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0)k--;
                else if(sum<0)j++;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    while(k>j && nums[j]==nums[j+1]) j++;
                    while(k>j && nums[k]==nums[k-1]) k--;
                    k--;
                    j++;
                }

            }

        }
        return res;
    }
};
