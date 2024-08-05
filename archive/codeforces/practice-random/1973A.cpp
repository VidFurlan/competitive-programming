#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if ((a + b + c) % 2 != 0) {
        cout << -1 << endl;
        return;
    }

    cout << min(a + b, (a + b + c) / 2) << endl;
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
