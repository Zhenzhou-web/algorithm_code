class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,false));
        int st,maxl;
         maxl=1;
         st=0;
         for(int i=0;i<n;i++){
            f[i][i]=true;
         }

        for(int len=2;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                if(s[i]!=s[j])continue;
                 if(len>2&&!f[i+1][j-1])continue;
                    f[i][j]=true;
                    maxl=len;
                    st=i;
                
            }
        }
        return s.substr(st,maxl);
        
    }
};
