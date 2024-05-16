#include <bits/stdc++.h>
#include <string>
using namespace std;

using ll = long long;
using pll = pair<long, long>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll LL_INF = 1e18;

bool valid(string s) {
    for (int i =  0; i < s.size() / 2; i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

void solve() {
    int m = 0;
    for (int i = 100; i < 1000; i++)
        for (int j = 100; j < 1000; j++) {
            int n = i * j;
            if (valid(to_string(n)))
                m = max(m, n);
        }
    cout << m << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
