#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<pii> lr(m);
    for (pii &p : lr)
        cin >> p.first >> p.second;

    vector<int> lv(n), rv(n);
    lv[0] = -1;
    for (int i = 0; i < n; i++) {
        if (i > 0)
            lv[i] = lv[i - 1];
        if (s[i] == '0') 
            lv[i] = i;
    }

    rv[n - 1] = n;
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n) 
            rv[i] = rv[i + 1];
        if (s[i] == '1') 
            rv[i] = i;
    }

    set<pii> ans;
    for (pii p : lr) {
        int cl = rv[p.first - 1], cr = lv[p.second - 1];
        if (cl > cr)
            ans.insert({-1, -1});
        else
            ans.insert({cl, cr});
    }

    cout << ans.size() << "\n";
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
