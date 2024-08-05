#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    bool odd = 1, even = 1;
    ll mx = 0, mxEven = 0;
    FORR(x, a) {
        cin >> x;
        if (x % 2 == 0) {
            odd = 0;
            mxEven = max(mxEven, x);
        }
        else { 
            even = 0;
            mx = max(mx, x);
        }
    }

    if (odd || even) {
        cout << 0 << endl;
        return;
    }

    sort(ALL(a));
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 1) continue;
        if (a[i] <= mx && a[i] % 2 == 0) { 
            ans++; 
            mx += a[i];
            continue; 
        }
        
        mx += mxEven;
        ans += 2;
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
