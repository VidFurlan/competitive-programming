#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

vector<int> binary;

void precompute() {
    for (int i = 2; i <= 100007; i++) {
        bool f = 0;
        int n = i;
        while (n) {
            if (n % 10 > 1) {
                f = 1;
                break;
            }
            n = n / 10;
        }
        if (!f)
            binary.push_back(i);
    }
}

bool valid(int n) {
    if (n == 1)
        return true;
    bool f = 0;
    for (int i : binary) 
        if (n % i == 0) 
            f |= valid(n / i);
    return f;
}

void solve() {
    int n; cin >> n;
    cout << (valid(n) ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    precompute();

    while (t--) {
        solve();
    }

    return 0;
}
