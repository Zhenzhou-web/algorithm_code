class Solution {
public:
    int myAtoi(string s) {
        string s1;
        bool jud=false;
        int j=0;
        int i=0;
        while(s[j]==' ')j++;
            if(s[j]=='+')j++;
            else if(s[j]=='-'){
                j++;
                jud=true;
                }
        for( i=j;i<s.size();i++){
            if(s[i]>'9'||s[i]<'0')break;   
            else s1.push_back(s[i]);
        }
        long long num=0;
        for( i=0;i<s1.size();i++){
            num=num*10+(s1[i]-'0');
            if(num>INT_MAX)break;
        }
        if(jud)num=(-1)*num;
        if(num>INT_MAX)return INT_MAX;
        if(num<INT_MIN)return INT_MIN;
        return num;

    }
};
