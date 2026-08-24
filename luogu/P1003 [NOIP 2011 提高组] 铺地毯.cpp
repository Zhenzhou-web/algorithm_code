#include<iostream>
#include<vector> 

using namespace std;

int main(){
    int n, x, y;
    cin >> n;

    vector<vector<long long> > a(n, vector<long long>(2, 0));
    vector<vector<long long> > b(n, vector<long long>(2, 0));
    vector<vector<long long> > c(n, vector<long long>(2, 0));

    for(int i=0; i<n; i++){

        cin >> c[i][0] >> c[i][1] >> b[i][0] >> b[i][1];
        a[i][0] = c[i][0] + b[i][0];
        a[i][1] = c[i][1] + b[i][1];
    }
    
    cin >> x >> y;
    
    
    int max_idx = -1; 
    
    for(int j = n - 1; j >= 0; j--){
        if(x >= c[j][0] && x <= a[j][0] && y >= c[j][1] && y <= a[j][1]){
            max_idx = j + 1; 
            break; 
        } 
    }
    

    cout << max_idx << endl;
    return 0;
}
