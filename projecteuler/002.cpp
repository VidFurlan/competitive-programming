#include <bits/stdc++.h>
#include <utility>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    vector<ll> dp = {1, 2, 3};
    ll sum = 0;
    do {
        if (dp.front() % 2 == 0)
            sum += dp.front();
        swap(dp[0], dp[1]);
        swap(dp[1], dp[2]);
        dp[2] = dp[0] + dp[1];
    } while (dp.front() < 4000000);
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
