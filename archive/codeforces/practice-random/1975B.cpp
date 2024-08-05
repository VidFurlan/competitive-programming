#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    FORR(i, a) cin >> i;
    sort(ALL(a));
    int mn1 = a[0], mn2 = a[1];
    int i = 1;
    while (mn2 % mn1 == 0 && i < n) mn2 = a[i++];
    bool f = 1;
    while (i < n) {
        if (a[i] % mn1 != 0 && a[i] % mn2 != 0) {
            f = 0;
            break;
        }
        i++;
    }

    if (f) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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
