#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    ll n, m; cin >> n >> m; 
    vector<pll> a(m);
    for (pll &i : a) cin >> i.first >> i.second;
    sort(a.begin(), a.end());

    vector<ll> dp(n + 1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    multiset<ll> st;
    ll ans = 0;
    for (ll i = 0, j = 0; i <= n; i++) {
        // cout << endl << i << ":\n";
        for (; j < a.size() && a[j].first == i; j++) {
            pq.push({a[j].second, a[j].first});
            st.insert(a[j].first);
            // cout << "\tpq add: " << a[j].first << " " << a[j].second << endl;
        }

        while (!pq.empty() && pq.top().first < i) {
            auto it = st.find(pq.top().second);
            if (it != st.end())
                st.erase(it);
            // cout << "\tpq remove: " << pq.top().second << " " << pq.top().first << endl;
            pq.pop();
        }

        // cout << "\tpq size: " << pq.size() << endl;
        // cout << "\tmset: ";
        // for (auto i : st) cout << i << ", ";
        // cout << endl;
        // cout << "\tmset min: " << (st.empty()) ? 0 : dp[*st.begin() - 1]) << endl;
        
        dp[i] = max(ans, (int)pq.size() + ((st.empty()) ? 0 : dp[*st.begin() - 1]));
        ans = max(ans, dp[i]);

        // cout << "\tans: " << ans << endl;
        // cout << "\tdp: " << dp[i] << endl;
    }

    // cout << "dp: ";
    // for (int i : dp) cout << i << ", ";
    // cout << endl;

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
