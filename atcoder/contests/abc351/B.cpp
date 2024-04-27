#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    vector<string> b(n);

    for (auto &r : a)
        cin >> r;

    for (auto &r : b)
        cin >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
