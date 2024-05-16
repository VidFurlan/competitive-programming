#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

map<int, int> trial_division(long long n) {
    map<int, int> factorization;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n > 1)
        factorization[n]++;
    return factorization;
}

void solve() {
    map<int, int> mp;
    for (int i = 2; i <= 20; i++) {
        map<int, int> m = trial_division(i);
        for (pii j : m) 
            mp[j.first] = max(mp[j.first], j.second);
    }
    ll ans = 1;
    for (pii i : mp)
        ans *= pow(i.first, i.second);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
