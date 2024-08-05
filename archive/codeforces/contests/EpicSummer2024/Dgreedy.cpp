#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    map<int, int> a;
    FOR(i, n) {
        int x; cin >> x;
        a[x]++;
    }

    FORR2(x, y, a) cout << x << " " << y << endl;

    int ans = 0;
    while (!a.empty()) {
        ans++;
        a.erase(a.begin()->first);

        if (a.empty()) 
            break;

        int bob = -1;
        int i = 0;
        FORR2(x, y, a) {
            i++;
            if (i >= y) {
                bob = x;
                break;
            }
        }
        if (bob != -1) {
            a[bob]--;
            if (a[bob] == 0) 
                a.erase(bob);
        }
        else 
            a.begin()->second--;
    }

    cout << " -> " <<ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        cout << "-------------------" << endl;
    }

    return 0;
}
