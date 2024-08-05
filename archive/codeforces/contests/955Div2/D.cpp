#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll sum = 0;
    vector<vector<ll>> mp(n, vector<ll>(m));
    vector<string> ty(n);
    FORR(i, mp) FORR(j, i) cin >> j;
    FOR(i, n) { 
        cin >> ty[i];
        FOR(j, m) {
            ty[i][j] -= '0';
            sum += (ty[i][j] == 1) ? mp[i][j] : -mp[i][j];
        }
    }

    vector<vector<ll>> psum((n + 1), vector<ll>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + ((ty[i - 1][j - 1] == 1) ? 1 : -1);

    ll g = 0;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            ll w = psum[i + k][j + k] - psum[i][j + k] - psum[i + k][j] + psum[i][j];
            g = __gcd(g, abs(w));
        }
    }

    if ((g == 0 && sum == 0) || (g > 0 && sum % g == 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        //cout << "====================\n";
    }

    return 0;
}
