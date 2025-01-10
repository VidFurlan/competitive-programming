#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long  ll ;
typedef unsigned long long  ull;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;

const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;

int main() {
    ll n; cin >> n;
    vl a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll q; cin >> q;
    vl k(q), x(q);
    for(int i = 0; i < q; i++) { cin >> k[i] >> x[i]; k[i]--; }
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        mp[i] = b[i] - a[i];
    }

    vl ans(n);
    for (int d = 0; d < q; d++) {
        ll i = k[d];
        ll y = x[d];
        auto it = mp.lower_bound(i);
        while (it != mp.end() && y > 0) {
            if (it->se - y > 0) {
                it->se -= y;
                y = 0;
            }
            else {
                ans[it->fi] = b[it->fi];
                y -= it->se;
                ll idx = it->fi;
                it = next(it);
                mp.erase(idx);
            }
        }
    }
    
    for (auto &[k, v] : mp) {
        ans[k] = b[k] - v;
    }
    
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    
	return 0;
}