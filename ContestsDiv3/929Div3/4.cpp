#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, ans = 0;
        cin >> n;
        while (n--) {
            int num;
            cin >> num;
            ans += abs(num);
        }
        cout << ans << endl;
    }
}
