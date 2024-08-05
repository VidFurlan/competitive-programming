#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    string s; cin >> s;
    bool f = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1]) {
            swap(s[i], s[i - 1]);
            f = 1;
            break;
        }
    if (f)
        cout << "YES\n" << s << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
