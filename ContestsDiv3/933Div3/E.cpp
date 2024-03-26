#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int ans = INT_MAX;
        int n, m, k, d;
        cin >> n >> m >> k >> d;

        vector<vector<int>> map (n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> map[i][j];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= n - k + 1; i++) {
            for (int j = 1; j <= n; j++) {
                int max_d = 0;
                for (int r = 1; r <= k && i - r >= 0; r++) {
                    max_d = max(max_d, map[i - r][0]);
                    if (j - r < 0)
                        continue;
                    max_d = max(max_d, map[i - r][m - 1]);
                    for (int l = 0; l <= j - r + 1; l++)
                        dp[i][j] = min(dp[i][j], dp[i - r][l] + max_d);
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }

        for (int i = 1; i <= n; i++)
            ans = min(ans, dp[n][i]);

        cout << ans << endl;
    }
}
