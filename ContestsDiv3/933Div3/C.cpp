#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int ans = 0;
        int n;
        string s;
        cin >> n >> s;

        for (int i = 0; i < n - 2; i++) {
            if (i < n - 4 && s.substr(i, 5) == "mapie") {
                ans++;
                i += 4;
            }
            else if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") {
                ans++;
                i += 2;
            }
        }

        cout << ans << endl;
    }
}
