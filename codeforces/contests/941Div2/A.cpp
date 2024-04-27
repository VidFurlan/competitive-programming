#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, k; cin >> n >> k;
    
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        mp[t]++;
    }

    bool f = 0;
    for (auto &p : mp) 
        if (p.second >= k) 
            f = 1;
    if (f)
        cout << k - 1 << endl;
    else
        cout << n << endl;
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
