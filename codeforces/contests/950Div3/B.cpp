#include <bits/stdc++.h>
#include <functional>
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
    int n, f, k; cin >> n >> f >> k;
    vector<int> a(n);
    FORR(i, a) cin >> i;
    int num = a[f - 1];
    sort(ALL(a), greater<int>());
    if (k == n || a[k] < num) {
        cout << "YES" << endl;
        return;
    } 
    else if (a[k] > num) {
        cout << "NO" << endl;
        return;
    } 
    else {
        if (a[k - 1] == num) {
            cout << "MAYBE" << endl;
            return;
        }
        else {
            cout << "NO" << endl;
            return;
        }
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
