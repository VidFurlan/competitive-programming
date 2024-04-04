#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    ll ans = m/a + m/b + 2;
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
