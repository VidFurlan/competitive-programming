#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    vector<ll> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> b[i];

    //FORR(x, a) cout << x << " "; cout << endl;
    //FORR(x, b) cout << x << " "; cout << endl;

    while (q--) {
        ll d; cin >> d;
        // for (; i < k && a[i] < d; i++);
        // cout << "i: " << i << " \ta[i]: " << a[i] << " \td:" << d << endl;
        int l = 1, r = k;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < d) l = m + 1;
            else r = m;
        }
        int i = r;
        //cout << l << " " << r << " -> " << i << endl;
        if (a[i - 1] == d) {
            cout << b[i - 1] << " ";
            continue;
        }
        cout << b[i - 1] + (d - a[i - 1]) * (b[i] - b[i - 1]) / (a[i] - a[i - 1]) << " ";
    }
    cout << endl;
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
