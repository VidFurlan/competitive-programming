#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int up = 0;
    for (char ch : s)
        if (ch == 'U') 
            up++;

    if (up % 2 == 1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
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
