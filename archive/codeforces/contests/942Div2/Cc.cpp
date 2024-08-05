#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iterator>
#include <vector>
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
        cout << "ans: " << a[0] + k << endl;
        return;
    }

    vector<ll> diffs(n - 1);
    for (ll i = 1; i < n; i++)
        diffs[i - 1] = a[i] - a[i - 1];

    ll mn = a[0];
    ll sz = 1;
    for (ll i = 0; i < n && k > 0;) {
        while (sz + 1 < n && a[sz + 1] == a[sz]) sz++;

        if (sz * diffs[i] <= k) {
            mn += diffs[i];
            k -= sz * diffs[i];
        }
        else {
            mn += k / sz;
            k = k %sz;
            break;
        }

        cout << i << " sz: " << sz << " k: " << k << "  -> "<< mn << endl;
        i += sz + 1;
    }

    cout << mn << " -> " << (n - sz + k) << " -> ";
    cout << mn + (mn - 1) * (n - 1) + (n - sz + k - 1) << endl << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        cout << "----------------------------" << endl;
    }

    return 0;
}
