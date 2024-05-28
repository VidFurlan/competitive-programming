#include <bits/stdc++.h>
#include <cmath>
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
    unsigned ll a, b, l; cin >> a >> b >> l;
    unsigned ll ans = 0;
    set<ll> ks;
    FOR(i, 20)
        FOR(j, 20) {
            double k = l / (double)(pow(a, i) * pow(b, j));
            if (k == (unsigned ll)k)
                ks.insert((unsigned ll)k);
        }
    cout << ks.size() << endl;
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
