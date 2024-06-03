#include <bits/stdc++.h>
#include <iterator>
#include <numeric>
#include <vector>
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
    vector<int> a(n), b(n - 1);
    FORR(i, a) cin >> i;
    FOR(i, n - 1) b[i] = gcd(a[i], a[i + 1]);

    // FORR(i, b) cout << i << " ";
    // cout << endl;

    bool f = 1;
    int i = 0;
    for (; i < n - 2; i++)
        if (b[i] > b[i + 1]) {
            f = 0;
            break;
        }

    if (f) {
        cout << "YES" << endl;
        return;
    }

    FOR(k, 3) {
        vector<int> nwa, nwb(n - 2);
        FOR(j, n) 
            if (j != i + k)
                nwa.push_back(a[j]);
        //FORR(j, nwa) cout << i << " ";
        //cout << endl;

        FOR(j, n - 2) nwb[j] = gcd(nwa[j], nwa[j + 1]);

        //FORR(j, nwb) cout << i << " ";
        //cout << endl << "----" << endl;
        f = 1;
        for (int j = 0; j < nwb.size() - 1; j++)
            if (nwb[j] > nwb[j + 1]) {
                //cout << j << " " << j + 1 << endl;
                f = 0;
                break;
            }

        if (f) {
            cout << "YES" << endl;
            return;
        }
    }
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
