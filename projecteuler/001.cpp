#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    ll sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
