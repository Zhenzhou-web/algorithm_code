class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<=3){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=nums[i];
            }
            return sum;
        }
        sort(nums.begin(),nums.end());
        int sum=0;
        int mincz=10000;
        for(int i=0;i<n-2;i++){
            int m=target-nums[i];
            auto it2=nums.end();
            it2--;
            auto it1= nums.begin()+i+1;
            while(it2>it1){
                int sum1=*it1+*it2;
                int x=abs(m-sum1);
                if(mincz>x) {
                    mincz=x;
                    sum=sum1+nums[i];
                    }
                if(sum1>m){
                    it2--;
                }
                else if(sum1<m){
                    it1++;
                }
                 else return target;

            }
        }
       return sum;
    }
};
