#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int, int> pos;
    FOR(i, n) { cin >> a[i]; pos[a[i]] = i; }
    FORR(i, b) cin >> i;

    int cnt = 0, j;
    FOR(i, n) {
        if (a[i] == b[i]) continue;
        j = pos[b[i]];
        swap(a[i], a[j]);
        pos[a[j]] = j;
        pos[b[i]] = i;
        cnt++;
    }

    sort(ALL(a));
    sort(ALL(b));

    if (cnt % 2 || a != b)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
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
