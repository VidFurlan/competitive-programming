#include <bits/stdc++.h>
#include <cctype>
#include <string>
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
    int n; cin >> n;
    string s; cin >> s;

    FORR(c, s) {
        if (!(isdigit(c) || (c >= 'a' && c <= 'z'))) {
            cout << "NO" << endl;
            return;
        }
    }

    bool f = 0;
    FORR(c, s) {
        if (isdigit(c)) {
            if (f) {
                cout << "NO" << endl;
                return;
            }
        } else {
            f = 1;
        }
    }

    char prev = '0';
    FORR(c, s) {
        if (isdigit(c)) {
            if (c < prev) {
                cout << "NO" << endl;
                return;
            }
            prev = c;
        }
    }

    prev = 'a';
    FORR(c, s) {
        if (!isdigit(c)) {
            if (c < prev) {
                cout << "NO" << endl;
                return;
            }
            prev = c;
        }
    }
    cout << "YES" << endl;
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
