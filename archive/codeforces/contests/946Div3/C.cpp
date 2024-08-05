#include <bits/stdc++.h>
#include <ostream>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    
    map<vector<int>, int> mp, tr;
    ll ans = 0;
    for (int i = 0; i + 2 < n; i++) {
        // cout << 0 << " " << a[i + 1] << " " << a[i + 2] << " -> " << mp[{0, a[i + 1], a[i + 2]}] << endl;
        // cout << a[i] << " " << 0 << " " << a[i + 2] << " -> " << mp[{a[i], 0, a[i + 2]}] << endl;
        // cout << a[i] << " " << a[i + 1] << " " << 0 << " -> " << mp[{a[i], a[i + 1], 0}] << endl;
        ans -= 3 * tr[{a[i], a[i + 1], a[i + 2]}]++;
        ans += mp[{0, a[i + 1], a[i + 2]}]++;
        ans += mp[{a[i], 0, a[i + 2]}]++;
        ans += mp[{a[i], a[i + 1], 0}]++;
    }
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
