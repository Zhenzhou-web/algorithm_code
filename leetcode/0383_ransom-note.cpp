class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        int num=magazine.size();
        int n=ransomNote.size();
        int j=0;
        for(int i=0;i<num;i++){
            if(j < n && j==n-1&&ransomNote[j]==magazine[i])return true;
            if(j < n && ransomNote[j]==magazine[i])j++;
        }
        return j == n;
    }
};
