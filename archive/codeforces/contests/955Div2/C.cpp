#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    FORR(i, a) cin >> i;
    int ans = 0, sum = 0;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        dq.push_back(a[i]);
        while (sum > r) {
            sum -= dq.front();
            dq.pop_front();
        }
        if (sum >= l) {
            ans++;
            dq.clear();
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
