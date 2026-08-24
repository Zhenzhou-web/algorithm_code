#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int a = 0; a <= 6; a++) {
        for (int b = 0; b <= 6; b++) {
            int sum = (4 * a + 6) + (4 * b + 6);
            int root = 0;
            while (root * root < sum) {
                root++;
            }
            if (root * root == sum) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
