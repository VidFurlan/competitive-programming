#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    int sum = 0, mult = 0;
    for (int i = 1; i <= 100; i++) {
        mult += i * i;
        sum += i;
    }
    cout << sum * sum - mult << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
