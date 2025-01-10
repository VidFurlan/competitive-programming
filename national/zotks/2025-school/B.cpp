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
    vector<pll> a;
    for (int i = 0; i < 3; i++) {
        pll p;
        cin >> p.fi >> p.se;
        a.push_back(p);
    }
	ll minX = LLINF, maxX = -LLINF;
	ll minY = LLINF, maxY = -LLINF;
    for (auto p : a) {
        minX = min(minX, p.fi);
        maxX = max(maxX, p.fi);
        minY = min(minY, p.se);
        maxY = max(maxY, p.se);
    }
    ll x = maxX - minX;
    ll y = maxY - minY;
 	ll ans = max(x*x, y*y);
	cout << ans << endl;
	return 0;
}