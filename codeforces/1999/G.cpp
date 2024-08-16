#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define REP(i, k, n) for (int(i) = (k); (i) <= (n); ++(i))
#define REPR(i, k, n) for (int(i) = (k); (i) >= (n); --(i))
#define FORR(x, arr) for (auto &x : arr)
#define FORR2(x, y, arr) for (auto &[x, y] : arr)
#define ALL(a) (a.begin()), (a.end())
#define RALL(a) (a.rbegin()), (a.rend())
#define REVERSE(v) reverse(ALL(v))
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll low = 1, high = 999;
    while (high - low > 2) {
        ll midLow =  (2 * low + high) / 3;
        ll midHigh = (2 * high + low) / 3;

        cout << "? " << midLow << " " << midHigh << endl;
        ll area; cin >> area;
        if (area == (midLow + 1) * (midHigh + 1))
            high = midLow;
        else if (area == midLow * midHigh)
            low = midHigh;
        else {
            low = midLow;
            high = midHigh;
        }
        cout.flush();
    }

    if (high - low == 2) {
        cout << "? 1 " << low + 1 << endl;
        ll area; cin >> area;

        if (area != low + 1) {
            cout << "! " << low + 1 << endl;
            return;
        }
    }

    cout << "! " << high << endl;
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    return 0;
}
