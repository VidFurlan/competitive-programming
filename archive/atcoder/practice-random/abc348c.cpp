#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
        int a, c; cin >> a >> c;
        if (mp[c] == 0)
            mp[c] = a;
        else
            mp[c] = min(mp[c], a);
    }
    int ans = 0;
    for (auto p : mp)
        if (p.second > mp[ans])
            ans = p.first;
    cout << mp[ans] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    solve();

    return 0;
}
