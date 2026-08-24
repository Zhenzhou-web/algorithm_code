class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int cun0=0,cun1=0;
        vector<int>dp;
        int num=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cun0++;
            else cun1++;
            dp.push_back(cun0-cun1);
        }
        for(int i=0;i<n;i++){
            if(abs(dp[i])<=1)num++;
        }
        return num;
    }
    
};
