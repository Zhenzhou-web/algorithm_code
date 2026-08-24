class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>stage;
        stage.assign(nums.begin(),nums.end());
        int n=nums.size();
        if(k>n)return -1;
        sort(stage.begin(),stage.end());
        auto last = unique(stage.begin(), stage.end());
        stage.erase(last, stage.end());

        vector<int>cal(stage.size(),0);
        for(int i=k-1;i<n;i++){
            vector<bool> vis(stage.size(), false);
            for(int j=i-k+1;j<=i;j++){
                for(int l=0;l<stage.size();l++){
                    if(nums[j]==stage[l]){
                        if(!vis[l]){
                            cal[l]=cal[l]+1;
                            vis[l] = true;
                        }
                        break;
                    }
                }
            }
        }
        int max=-1;
        for(int i=0;i<stage.size();i++){
            if(cal[i]==1&&stage[i]>max)max=stage[i];
        }
        return max;
    }
};
