#include <algorithm>
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
    int n, c; cin >> n >> c;
    vector<ll> a(n), sum(n);
    FORR(i, a) cin >> i;
    sum[0] = c;
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i - 1];

    ll maxNum = *max_element(a.begin(), a.end());
    ll maxNumC = max(a.front() + c, maxNum);
    int win = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == maxNumC || (i == 0 && a[i] + c == maxNum)) {
            win = i;
            break;
        }

    for (int i = 0; i < n; i++) {
        if (i == win)
            cout << 0 << " ";
        else if (sum[i] + a[i] >= maxNum)
            cout << i << " ";
        else 
            cout << i + 1 << " ";
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
