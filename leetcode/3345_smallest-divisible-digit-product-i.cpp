class Solution {
public:
    int smallestNumber(int n, int t) {
        int num;
        bool jud = false;
        while(!jud){
            int tmp = n;
            num = 1;
            while(tmp != 0){
                int digit = tmp %10;
                num *= digit;
                tmp = tmp /10;
            }
            if(num % t != 0)
                n++;
            else
                jud = true;
        }
        return n;
    }
};
