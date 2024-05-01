#include <bits/stdc++.h>
#include <functional>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void dfs(vector<string> &g, vector<vector<bool>> &dp, int &n, int r, int c, bool &ans);

void mv(vector<string> &g, vector<vector<bool>> &dp, int &n, int r, int c, bool &ans) { 
    if (r >= 2 || r < 0) return;
    if (c >= n || c < 0) return;

    if (g[r][c] == '>')
        dfs(g, dp, n, r, c + 1, ans);
    else
        dfs(g, dp, n, r, c - 1, ans);
}

void dfs(vector<string> &g, vector<vector<bool>> &dp, int &n, int r, int c, bool &ans) {
    if (r >= 2 || r < 0) return;
    if (c >= n || c < 0) return;
    if (dp[r][c] == 1) return;
    if (ans == true) return;
    if (r == 1 && c == n - 1) {
        ans = true;
        return;
    }

    dp[r][c] = 1;
    
    mv(g, dp, n, r + 1, c, ans);
    mv(g, dp, n, r, c + 1, ans);
    mv(g, dp, n, r - 1, c, ans);
    mv(g, dp, n, r, c - 1, ans);
}

void solve() {
    int n; cin >> n;
    vector<string> g(2);
    vector<vector<bool>> dp(2, vector<bool>(n, 0));
    cin >> g[0] >> g[1];
    bool ans = false;
    dfs(g, dp, n, 0, 0, ans);
    cout << (ans ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
