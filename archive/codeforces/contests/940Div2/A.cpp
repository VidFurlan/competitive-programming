#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        mp[m]++;
    }

    int ans = 0;
    for (auto &m : mp)
        ans += m.second / 3;
    cout << ans << '\n';
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
