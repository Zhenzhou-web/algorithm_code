class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
     int n=stoneValue.size();
     vector<int>sum(n);
     sum[n-1]=stoneValue[n-1];
     for(int i=n-2;i>=0;i--){
        sum[i]=stoneValue[i]+sum[i+1];
     }
     vector<int> f(n+1);
     f[n]=0;
     for(int i=n-1;i>=0;i--){
        int breast=f[i+1];
        for(int j=i+2;j<=n && j<=i+3;j++){
            breast=min(breast,f[j]);
        }
        f[i]=sum[i]-breast;
     }   
     int total = accumulate(stoneValue.begin(), stoneValue.end(), 0);
     if(f[0]*2==total){
        return "Tie";
     }
     else{
        return f[0]*2>total?"Alice":"Bob";
     }
    }
};
