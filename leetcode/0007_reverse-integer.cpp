class Solution {
public:
    int reverse(int x) {
        long long ars=0;
        while(x!=0){
            int temp=x%10;
            ars=ars*10+temp;
            x=x/10;
        }
        if(ars > INT_MAX || ars < INT_MIN) return 0;
        return (int)ars;

    }
};
