class Solution {
public:
    int missingInteger(vector<int>& nums) {
        if(nums.size()==1)return nums[0]+1;
        auto it=nums.begin()+1;
        while(*it-1==*(it-1)){
            if(it==nums.end()-1)break;
            it++;
        }
        if(*it-1!=*(it-1))it--;
        int sum=(it-nums.begin()+1)*(nums[0]+*it)/2;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i!=nums.size()){
            if(nums[i]==sum)sum++;
            i++;
        }
        return sum;
    }
};
