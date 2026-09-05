class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        bool jud=true;
        int mn=nums1[0];
        for(auto x:nums1){
            int m=x%2;
            if(x<mn)mn=x;
            if(m!=nums1[0]%2)jud=false;
        }
        if(mn & 1)return true;
        else if(jud)return true;
        return false; 
        
    }
};
