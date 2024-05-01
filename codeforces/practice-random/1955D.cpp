#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int &i : a) cin >> i;
    for (int &i : b) cin >> i;

    map<int, int> mp_a, mp_b;
    for (int i : b) mp_b[i]++;

    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++) {
        mp_a[a[i]]++;
        if (mp_a[a[i]] <= mp_b[a[i]]) 
            cnt++;
    }
    if (cnt >= k) ans++;

    for (int i = m; i < n; i++) {
        mp_a[a[i - m]]--;
        if (mp_a[a[i - m]] < mp_b[a[i - m]])
            cnt--;
        mp_a[a[i]]++;
        if (mp_a[a[i]] <= mp_b[a[i]])
            cnt++;
        if (cnt >= k) ans++;
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
