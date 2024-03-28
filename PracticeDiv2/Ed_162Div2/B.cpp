#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ii> m(n); // Monsters {pos, hp}
    for (int i = 0; i < n; cin >> m[i++].second);
    for (int i = 0; i < n; i++) {
        cin >> m[i].first;
        m[i].first = abs(m[i].first);
    }
    
    ll max_dist = max(m[0].first, m[n-1].first);
    vector<int> t_bullets (max_dist + 1);
    for (ii mo : m) {
        t_bullets[mo.first] += mo.second;
    }

    ll b = 0;
    for (ll t = 1; t < max_dist + 1; t++) {
        b += k;
        if (b >= t_bullets[t]) 
            b -= t_bullets[t];
        else {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
