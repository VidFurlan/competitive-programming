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
const ll MAXN = 2 * 1e5 + 100;

vl devisors(MAXN);
void computeD() {
    for (ll i = 1; i < MAXN; i++) {
        ll sq = sqrt(i);
        for (ll j = 1; j <= sq; j++) {
            if (i % j == 0) {            
                devisors[i]++;
                if (i / j != j) devisors[i]++;
            }
        }
    }
}

int main() {
    ll tt; cin >> tt;
    computeD();
    while (tt--) {
        ll n; cin >> n;
        vl a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ll comb = 1;
            for (int p = 0; p < n; p++) comb = (comb * 2) % MOD;
            ll exclude = 1;
            for (int p = 0; p < n - devisors[i+1]; p++) exclude = (exclude * 2) % MOD;
            ll value = (comb - exclude) % MOD;
            value = (value * a[i]) % MOD;
            ans = (ans + value) % MOD;
        }
        cout << ans << endl;
    }
	return 0;
}
