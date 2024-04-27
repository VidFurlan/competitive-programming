#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
        int t; cin >> t;
        a += t;
    }

    for (int i = 0; i < 8; i++) {
        int t; cin >> t;
        b += t;
    }

    cout << a - b + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
