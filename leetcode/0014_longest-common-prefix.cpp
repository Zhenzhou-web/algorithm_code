class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        string a;
        string base=strs[0];
        int n=strs.size();
        for(int i=0;i<base.size();i++){
            char c=base[i];
            bool ok=true;
            for(int j=1;j<n;j++){
                if(strs[j].size()<=i||strs[j][i]!=c) {
                  ok=false;
                  break;
                }
               
            }
            if(!ok)break;
            a.push_back(c);

        }
        return a;
    }   
};
