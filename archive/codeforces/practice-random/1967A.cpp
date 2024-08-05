#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    unsigned ll n, k; cin >> n >> k;
    vector<unsigned ll> a(n);
    FORR(i, a) cin >> i;
    sort(ALL(a));
    for (unsigned ll sz = 1; sz <= n; sz++) {
        if (k == 0) break;
        unsigned ll m = (sz == n) ? INF : a[sz];
        if (sz * (m - a[0]) <= k) {
            k -= sz * (m - a[0]);
            FOR(i, sz) a[i] = m;
        } 
        else {
            unsigned ll t = a[0];
            FOR(i, sz) a[i] = t + k / sz;
            k = k % sz;
            for (unsigned ll i = sz - 1; i >= 0; i--) {
                if (k == 0) break;
                a[i]++;
                k--;
            }
        }
    }
    // FORR(i, a) cout << i << " ";
    // cout << "\n";
    
    unsigned ll ans = a[0] * n, i;
    // cout << "Answer: " << ans << " ";
    for (i = n - 1; i >= 0; i--)
        if (a[i] == a[0]) 
            break;
    ans -= i % n;
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
