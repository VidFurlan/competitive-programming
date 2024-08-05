#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll ans = 0;
    ll w = abs(a - c), h = abs(b - d);
    vector<ll> col(4);
    bool voff = (abs(b) % 2 == 1) ? 1 : 0;
    col[0] = 2 * ((h + 1) / 2) + (h / 2); 
    col[1] = ((h + 1) / 2) + 2 * (h / 2);
    if (voff) swap(col[0], col[1]);
    col[2] = h * 2 - col[0];
    col[3] = h * 2 - col[1];
    if (voff) swap(col[2], col[3]);
    // cout << col[0] << " " << col[1] << " " << col[2] << " " << col[3] << endl;
    int hoff = abs(a) % 4;
    if (a < 0) hoff = 4 - hoff;
    // cout << hoff << endl;
    ans += col[(0 + hoff) % 4] * ((w + 3) / 4);
    // cout << col[(0 + hoff) % 4] * ((w + 3) / 4) << endl;

    ans += col[(1 + hoff) % 4] * ((w + 2) / 4);
    // cout << col[(1 + hoff) % 4] * ((w + 2) / 4) << endl;

    ans += col[(2 + hoff) % 4] * ((w + 1) / 4);
    // cout << col[(2 + hoff) % 4] * ((w + 1) / 4) << endl;

    ans += col[(3 + hoff) % 4] * (w / 4);
    // cout << col[(3 + hoff) % 4] * (w / 4) << endl;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
