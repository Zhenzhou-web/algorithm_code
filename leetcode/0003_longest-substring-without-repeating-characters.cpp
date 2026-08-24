class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>a;
        int num=0,maxl=0;
        int k=0;
        for(int i=0;i<s.size();i++){
            bool repeate=false;
            a.push_back(s[i]);

            for(int j=k;j < a.size()-1;j++){
                if(a[j]==s[i]){
                    repeate=true;
                    k=j+1;
                    break;
                }
               
            }
            num = a.size()-k;
            if(num>maxl) maxl=num;
        }
        return maxl;
    }
};
