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
     int n; cin >> n;
     vector<ll> a(n), b;
     FORR(i, a) cin >> i;

     for (int i = 1; i < n; i++) {
         if (a[i - 1] > a[i]) {
             b.push_back(a[i - 1] - a[i]);
             a[i] = a[i - 1];
         }
     }

     if (b.empty()) {
        cout << 0 << endl;
        return;
    }

    sort(ALL(b));
    
    ll m = b.size();
    ll ans = b.back() + b[0] * m;
    for (int i = 1; i < m; i++) {
        ans += (b[i] - b[i - 1]) * (m - i);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        // cout << "-------------------" << endl;
    }

    return 0;
}
