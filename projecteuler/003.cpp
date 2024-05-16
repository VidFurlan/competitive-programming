#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    vector<long long> fact;
    ll n = 600851475143;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            fact.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        fact.push_back(n);

    cout << fact.back() << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
