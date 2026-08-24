class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;

        int n=s.size();
        vector<vector<char>>a(numRows,vector<char>(n,'\0'));
        int key=1;
        int i=0,j=0;
        for(int m=0;m<n;m++){
            a[i][j]=s[m];
            if(key==1){
                i++;
                if(i==numRows){
                    key=0;
                    i-=2;
                    j++;
                }
            }
            else{
                i--;
                j++;
                if(i<0){
                    key=1;
                    i+=2;
                }
            }
        }
        string l;
        for(int p=0;p<numRows;p++){
            for(int q=0;q<n;q++){
                if(a[p][q]!='\0')
                    l.push_back(a[p][q]);
            }
        }
        return l;
    }
};
