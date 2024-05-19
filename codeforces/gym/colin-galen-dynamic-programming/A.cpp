#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << (ll)pow(2, n / 2) << endl;
    } else
        cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
