class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()){
            return vector<int>();
        }
        sort(nums.begin(),nums.end());
        vector<int>f;
        int x=*(nums.end()-1);
        int begi=*nums.begin();
        int j=0;
        for(int i=begi;i<x;i++){
            if(nums[j]!=i)f.push_back(i);
            else j++;
        }
        return f;
    }
};
