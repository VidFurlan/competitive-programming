#include <bits/stdc++.h>
#include <cmath>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int n, t; cin >> n;
    ll sum = 0;
    while (n--) {
        cin >> t;
        sum += t;
    }
    double sq = sqrt(sum);
    if ((int)sq == sq)
        cout << "YES\n";
    else 
        cout << "NO\n";
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
