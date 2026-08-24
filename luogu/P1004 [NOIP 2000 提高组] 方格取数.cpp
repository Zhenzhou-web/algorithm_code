#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    
    int a[12][12] = {0};  
    int f[12][12][12][12] = {0};  


    cin >> n;
    while (cin >> x >> y >> z) {  
        if (x == 0 && y == 0 && z == 0) {
            break;
        }
        a[x][y] = z; 
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 1; l <= n; l++) {
                    int max_prev = max(
                        max(f[i-1][k][j-1][l], f[i-1][k][j][l-1]),
                        max(f[i][k-1][j-1][l], f[i][k-1][j][l-1])
                    );
                    f[i][k][j][l] = max_prev + a[i][k] + a[j][l];
              
                    if (i == j && k == l) {
                        f[i][k][j][l] -= a[i][k];
                    }
                }
            }
        }
    }

    cout << f[n][n][n][n] << endl;
    return 0;
}
