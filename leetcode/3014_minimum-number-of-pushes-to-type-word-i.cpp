class Solution {
public:
    int minimumPushes(string word) {
        int m=word.size();
        int k=m/8;
        int t=1;
        int num=0;
        int fol=m%8;
        num=fol*(k+1);
        while(k>0){
          num+=8*t;
          t++;
          k--;
        }
        return num;
    }
};
