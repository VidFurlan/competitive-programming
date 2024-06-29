#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(m);
    FORR(i, a) cin >> i;
    FORR(i, b) cin >> i;
    FORR(i, c) cin >> i;

    int mx = *max_element(ALL(a));
    vector<int> mnLoss(mx + 1, INF);

    FOR(i, n)
        mnLoss[a[i]] = min(mnLoss[a[i]], a[i] - b[i]);

    FOR(i, mx)
        mnLoss[i + 1] = min(mnLoss[i + 1], mnLoss[i]);

    vector<int> dp(mx + 1);
    FOR(i, mx + 1)
        dp[i] = (mnLoss[i] <= i) ? dp[i - mnLoss[i]] + 1 : 0;

    ll ans = 0;
    FORR(i, c) {
        if (i > mx) {
            int mult = (i - mx - 1) / mnLoss[mx] + 1;
            ans += mult;
            i -= mult * mnLoss[mx];
        }
        ans += dp[i];
    }

    cout << ans * 2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
