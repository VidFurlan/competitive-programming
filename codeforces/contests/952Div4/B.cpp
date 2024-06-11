#include <bits/stdc++.h>
#include <iostream>
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
    int n; cin >> n;
    int mi = 2, m = 0;
    for (int i = 2; i <= n; i++) {
        int f = n / i;
        int sum = i * (f * (f + 1)) / 2;

        if (sum > m) {
            m = sum;
            mi = i;
        }
    }
    cout << mi << endl;
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
