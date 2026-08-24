class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(int i = 0; i < 2; i++){ 
            for(int j = 1; j < n - i; j++){
                if(nums[j] < nums[j-1]){
                    int temp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        int ans = (nums[n-1]-1) * (nums[n-2]-1);
        return ans;
    }
};
