#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    sort(a.begin(), a.end());
    if (n == 1) {
        //cout << "ans: " << a[0] + k << endl;
        cout << a[0] + k << '\n';
        return;
    }
    // for (int i : a)
    //     cout << i << " ";
    // cout << endl;

    vector<ll> diffs(n - 1);
    for (ll i = 1; i < n; i++)
        diffs[i - 1] = a[i] - a[i - 1];

    ll mn = a[0];
    ll sz = 1;
    while (k > 0 && sz <= n) {
        while (sz - 1 < n && (mn == a[sz] || diffs[sz - 1] == 0)) sz++;

        bool f = false;
        if (k >= sz * diffs[sz - 1]) {
            k -= sz * diffs[sz - 1];
            mn += diffs[sz - 1];
        } 
        else {
            mn += k / sz;
            k = k % sz;
            f = 1;
        }

        while (sz - 1 < n && (mn == a[sz] || diffs[sz - 1] == 0)) sz++;
        sz = min(sz, n);
        // cout << "> mn: " << mn << "   k: " << k << "   sz: " << sz << "   diff: " << diffs[sz - 1] << endl;
        if (f) break;
    }

    // cout << "mn: " << mn << "   k: " << k << "   sz: " << sz << endl;
    // cout << "ans: " << mn + (mn - 1) * (n - 1) + (n - sz) + k << endl;
    cout << mn + (mn - 1) * (n - 1) + (n - sz) + k << '\n';
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
