class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
     vector<vector<int>>g(n);
     for(int i=0;i<invocations.size();i++){
        int x=invocations[i][0];
        int y=invocations[i][1];
        g[x].push_back(y);
     }
     vector<bool>jud(n,false);
     queue<int> q;
     q.push(k);
     jud[k]=true;
     while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(!jud[v]){
                jud[v]=true;
                q.push(v);
            }

        }
     }
        bool judespcial=false;
        for(int i=0;i<invocations.size();i++){
            int x=invocations[i][0];
            int y=invocations[i][1];
            if(!jud[x]&&jud[y]){
                judespcial=true;
                break;
            }
        }
        vector<int>ans;
        if(judespcial){
            for(int i=0;i<n;i++){
              ans.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!jud[i]){
                    ans.push_back(i);
                }
            }
        }

     
    return ans;      
    }
};
