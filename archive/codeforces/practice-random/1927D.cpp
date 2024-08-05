#include <bits/stdc++.h>
#include <vector>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    vector<int> dp(n, -1);
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        if (a[i] != a[i - 1])
            dp[i] = i - 1;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        if (dp[--r] < --l)
            cout << "-1 -1" << endl;
        else 
            cout << dp[r] + 1 << " " << r + 1 << endl;
    }
    cout << endl;
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
