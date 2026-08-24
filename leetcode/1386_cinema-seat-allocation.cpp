#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<bool>> book;
        int m = reservedSeats.size();
        for(int i = 0; i < m; i++){
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1] - 1;
            if(!book.count(row)){
                book[row] = vector<bool>(10, true);
            }
            book[row][seat] = false;
        }
        int res = (n - book.size()) * 2;
        for(auto &p : book){
            auto &tage = p.second;
            bool left  = tage[1] && tage[2] && tage[3] && tage[4];
            bool mid   = tage[3] && tage[4] && tage[5] && tage[6];
            bool right = tage[5] && tage[6] && tage[7] && tage[8];
            if(left && right){
                res += 2;
            }else if(left || mid || right){
                res += 1;
            }
        }
        return res;
    }
};
