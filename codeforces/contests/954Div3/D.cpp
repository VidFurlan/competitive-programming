#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    function<ll(string, int, int)> dfs = [&](string s, int i, int c) -> ll {
        if (c == 0) return stol(s.substr(i));
        if (dp[i][c] != -1) return dp[i][c];

        ll mn = inf;
        for (int j = i; j < s.size() - c; j++) {
            ll cur = stol(s.substr(i, j - i + 1)), _dfs = dfs(s, j + 1, c - 1);
            mn = min({mn, cur + _dfs, cur * _dfs});
        }

        return dp[i][c] = mn;
    };

    ll ans = dfs(s, 0, n - 2);
    cout << ans << endl;
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

