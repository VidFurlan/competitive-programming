#include <bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    int m = 0;

    vector<int> count(26);
    for (char ch : s) {
        count[ch - 'a']++;
        m = max(m, count[ch - 'a']);
    }

    vector<short> c(m + 1);
    for (int i : count)
        c[i]++;

    for (int i = 1; i <= m; i++)
        if (c[i] != 0 && c[i] != 2) {
            cout << "No" << endl;
            return;
        }

    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
