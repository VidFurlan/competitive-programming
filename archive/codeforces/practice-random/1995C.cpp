#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n);
    FORR(x, a) cin >> x;
    
    bool f = 0;
    FORR(x, a) {
        if (x == 1 && f) {
            cout << -1 << endl;
            return;
        }
        else if (x != 1) {
            f = 1;
        }
    }

    ll ans = 0, total = 0;
    for (ll i = 1; i < n; i++) {
        ll prevNum = a[i - 1];
        if (prevNum < a[i] && total != 0) {
            ll power = 0;
            bool f = 0;
            while (power < total && prevNum < a[i]) {
                prevNum *= prevNum;
                power++;
            }

            if (prevNum > a[i]) power--;
            total -= power;
            ans += total;
        }
        else {
            ll cur = 0, curNum = a[i];
            while (curNum < a[i - 1]) {
                curNum *= curNum;
                cur++;
            }

            total += cur;
            ans += total;
        }
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
