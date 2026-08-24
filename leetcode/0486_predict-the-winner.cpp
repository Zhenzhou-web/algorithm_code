class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                dp[i][j]=max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        bool judge=false;
        if(dp[0][n-1]>=0)judge=true;
        return judge;

    }
};
