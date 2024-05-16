#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

void solve() {
    for (int a = 1; a < 1000; a++) 
        for (int b = 1; b < 1000; b++) 
            for (int c = 1; c < 1000; c++) {
                if (a + b + c != 1000)
                    continue;
                if (a * a + b * b == c * c) {
                    cout << a * b * c << endl;
                    return;
                }
            }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
