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
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    FORR(i, a) cin >> i;
    ll h = *max_element(ALL(a)) + k, l = 0;
    ll ans = 0;

    while (l <= h) {
        ll m = (l + h) / 2;
        bool f = 0;

        for (int i = 0; i < n; i++) {
            vector<ll> b(n);
            b[i] = m;

            ll k_used = 0;
            for (int j = i; j < n; j++) {
                if (b[j] <= a[j]) break;

                if (j + 1 >= n) {
                    k_used  = k + 1;
                    break;
                }

                k_used += b[j] - a[j];
                b[j + 1] = max(0ll, b[j] - 1);
            }

            if (k_used <= k) {
                f = 1;
                break;
            }
        }

        if (f) {
            l = m + 1;
            ans = m;
        }
        else {
            h = m - 1;
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
