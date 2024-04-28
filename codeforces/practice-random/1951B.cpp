#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    ll n, k; cin >> n >> k; k--;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;

    swap(a[0], a[k]);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[0])
            ans++;
        else 
            break;
    }

    swap(a[0], a[k]);
    ll m = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] >= a[k]) {
            m = i;
            break;
        }
    }

    swap(a[m], a[k]);
    for (ll i = m + 1; i < n; i++) {
        if (a[i] > a[m]) {
            ans = max(ans, i - m - 1 + ((m > 0) ? 1 : 0));
            break;
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
