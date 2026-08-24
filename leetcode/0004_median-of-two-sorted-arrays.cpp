class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int pos=0,pos1=0;
       float k;
       vector<int>num3;
       int m = nums1.size();
       int n = nums2.size();
       for(int i=0;i<m+n;i++){
           if(pos >= m){
               num3.push_back(nums2[pos1]);
               pos1++;
           }
           else if(pos1 >= n){
               num3.push_back(nums1[pos]);
               pos++;
           }
           else if(nums1[pos]>nums2[pos1]){
               num3.push_back(nums2[pos1]);
               pos1++;
           }
           else{
               num3.push_back(nums1[pos]);
               pos++;
           }
       }
       int num=num3.size()/2;
       if(num3.size()%2!=0) k=num3[num];
       else k=(num3[num]+num3[num-1])/2.0;
       
       return k;
    }
};
