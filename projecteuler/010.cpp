#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    const int N = 2000000;
    vector<int> lp(N+1);
    vector<int> pr;

    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j = 0; i * pr[j] <= N; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i])
                break;
        }
    }

    ll sum = 0;
    for (int i : pr)
        sum += i;
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
