#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(i,to) for(i=0;i<(to);x++)
#define FORR(i,arr) for(auto& i:arr)
#define FORR2(i,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;
const ll inf = 1e18;

void solve() {
    int n, k; 
    cin >> n >> k;
    vector<int> v(n);
    FORR(i, v) cin >> i;

    map<int, set<int>> mp;
    for(int i : v) {
        int m = i % k;
        if (mp[m].find(i) != mp[m].end())
            mp[m].erase(i);
        else
            mp[m].insert(i);
    }

    bool f = false;
    int ans = 0, off = -1;
    FORR2(x, y, mp) {
        if (y.size() % 2 == 0) continue;
        if (f) {
            cout << -1 << endl;
            return;
        }
        f = true;
        off = x;
    }

    FORR2(x, y, mp) {
        if (x == off) continue;
        while (!y.empty()) {
            int t = *y.begin();
            y.erase(t);
            if (!y.empty()) {
                ans += (*y.begin() - t) / k;
                y.erase(y.begin());
            }
        }
    }

    if (!f || mp[off].size() == 1) {
        cout << ans << endl;
        return;
    } 

    vector<int> voff;
    int m = voff.size();
    vector<int> prefix(m, 0), suffix(m, 0);
    prefix[1] = voff[1] - voff[0];
    for(int i = 3; i < m; i += 2) {
        prefix[i] = voff[i] - voff[i - 1] + prefix[i - 2];
    }
    suffix[m - 2] = voff[m - 1] - voff[m - 2];
    for(int i = m - 4; i >= 0; i -= 2) {
        suffix[i] = voff[i + 1] - voff[i] + suffix[i + 2];
    }
    int temp = LLONG_MAX;
    for(int i = 0; i < m; i += 2) {
        int x = 0;
        if(i > 0) x += prefix[i - 1];
        if(i + 1 < m) x += suffix[i + 1];
        temp = min(temp, x);
    }
    ans += temp / k;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;
    while (t--) {
        solve();
        cout << "-------------------\n"; // Debug separator for output clarity
    }

    return 0;
}
