class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=0;
        auto head=height.begin();
        auto tail=height.end()-1;
        while(head!=tail){
            int kd=tail-head;
            int area=min(*head,*tail)*kd;
            maxarea=max(area,maxarea);
            if(*head<*tail)head++;
            else tail--; 
            
        }
        return maxarea;

    }
};
