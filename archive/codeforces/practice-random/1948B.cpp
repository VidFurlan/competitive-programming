#include <bits/stdc++.h>
#include <vector>
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
    int n, m = 0; cin >> n;
    bool f = 0;

    vector<int> a(n);
    FORR(i, a) cin >> i;

    for(int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            f = 1;
            if (a[i] / 10 > a[i] % 10 || a[i] % 10 >= m) {
                cout << "NO" << endl;
                return;
            }
            m = a[i] % 10;
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
