#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll ans = 0;
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            if (k / (i * j) <= z && k % (i * j) == 0)
                ans = max(ans, (x - i + 1) * (y - j + 1) * (z - (k / (i * j)) + 1));
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
