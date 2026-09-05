class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
     int n=nums.size();
     int max=nums[0];
     int min;
     for(int i=0;i<n;i++){
        int min=nums[i];
        for(int j=i;j<n;j++){
            if(nums[j]<min)min=nums[j];
        }
        if(nums[i]>max)max=nums[i];
     
     if(max-min<k||max-min==k)return i;
     }
    return -1;
    }
};
