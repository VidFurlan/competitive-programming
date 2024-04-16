#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <stack>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;

    vector<ll> l(n);
    vector<ll> r(n);
    vector<ll> c(n);
    
    for (ll &i : l) cin >> i;
    for (ll &i : r) cin >> i;
    for (ll &i : c) cin >> i;

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    sort(c.begin(), c.end(), greater<ll>());

    stack<ll> st;
    vector<ll> v;

    for (int i = 0, j = 0; i <= n && j < n;) {
        if (i < n && l[i] < r[j])
            st.push(l[i++]);
        else {
            v.push_back(r[j] - st.top());
            st.pop();
            j++;
        }
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += v[i] * c[i];
    }

    cout << ans << "\n";
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
