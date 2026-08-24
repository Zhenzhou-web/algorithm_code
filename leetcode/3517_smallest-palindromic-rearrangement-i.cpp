class Solution {
public:
    string smallestPalindrome(string s) {
        int len=s.length();
        int position=len/2;
        sort(s.begin(),s.begin()+position);
        for(int i=0;i<position;i++){
            s[len-1-i]=s[i];
        }
        return s;
    }
};
