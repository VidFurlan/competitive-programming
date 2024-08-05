#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x, to) for(int x = 0; x < (to); x++)
#define FORR(x, arr) for(auto& x : arr)
#define FORR2(x, y, arr) for(auto& [x, y] : arr)
#define ALL(a) (a.begin()), (a.end())

const ll MOD = 1e9 + 7;

vector<vector<int>> dp;
vector<int> a;

int dpCalc (int i, int j) {
    if (dp[i][j] != INT_MIN) 
        return dp[i][j];

    int dp1 = (j < 1) ? -1 : ((i == 1) ? ((j == 1) ? 0 : -1) : dpCalc(i - 1, j - 1));
    int dp2 = (j < 0) ? -1 : ((i == 1) ? ((j == 0) ? 0 : -1) : dpCalc(i - 1, j));

    dp[i][j] = (a[i]) ? dp1 : dp2;

    if (dp2 != -1 && dp2 + a[i] <= j && (dp[i][j] == -1 || dp2 + a[i] < dp[i][j]))
        dp[i][j] = dp2 + a[i];

    return dp[i][j];
};

void solve() {
    int n; cin >> n;
    int ans = n;

    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)); 
    a = vector<int>(n + 1, 0);
    
    FOR(i, n) {
        int x; cin >> x;
        a[x]++;
    }

    for (int i = n; i >= 0; i--) {
        if (dpCalc(n, i) != -1)
            ans = i;
        // FORR(r, dp) {
        //     FORR(c, r)
        //         cout << c << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        // cout << "-------------------" << endl;
    }

    return 0;
}
