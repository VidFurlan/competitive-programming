#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int ans = 0;
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> p1 (n), p2 (m);
        for (int i = 0; i < n; i++) 
            cin >> p1[i];
        for (int i = 0; i < m; i++) 
            cin >> p2[i];

        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (p1[i] + p2[j] <= k)
                    ans++;
                else
                    break;
            }

        cout << ans << endl;
    }

    return 0;
}
