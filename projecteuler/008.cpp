#include <bits/stdc++.h>
#include <string>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    ifstream in("008.in");
    string s;
    getline(in, s);
    ll ans = 0;

    for (int i = 12; i < s.size(); i++) {
        ll mult = 1;
        for (int j = 0; j < 13; j++)
            mult *= s[i - j] - '0';
        ans = max(ans, mult);
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
