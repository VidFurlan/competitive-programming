#include <atomic>
#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<int> a(n), b(n);
    int mn = 0, mx = 0;
    int minus = 0, plus = 0;

    FORR(i, a) cin >> i;
    FORR(i, b) cin >> i;
    
    FOR(i, n)
        if (a[i] > b[i])
            mn += a[i];
        else if (b[i] > a[i])
            mx += b[i];
        else if (a[i] == b[i] && a[i] == 1)
            plus++;
        else if (a[i] == b[i] && a[i] == -1)
            minus++;
    
    if (mn > mx)
        swap(mn, mx);

    //cout << "mn: " << mn << " mx: " << mx << " plus: " << plus << " minus: " << minus << endl;
    int diff = mx - mn;
    
    if (diff > plus)
        mn += plus;
    else {
        mn += diff;
        plus -= diff;
        mn += plus / 2;
        mx += plus / 2;
        mx += plus % 2;
    }

    diff = mx - mn;

    if (diff > minus)
        mx -= minus;
    else {
        mx -= diff;
        minus -= diff;
        mx -= minus / 2;
        mn -= minus / 2;
        mn -= minus % 2;
    }

    cout << min(mn, mx) << endl;
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
