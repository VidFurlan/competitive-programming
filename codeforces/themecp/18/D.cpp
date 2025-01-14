#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 0

typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
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
#define SZ(x) (int)(x).size()
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << (x) << endl

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll mn = m + n - 2;
    if (k < mn) {
        cout << "NO" << endl;
        return;
    }
    ll waste = k - mn;
    if (waste & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    //cout << waste % 10 << endl;
    vector<string> ans(n, string(m - 1, 'R'));
    for (int i = m-2; i >= 0; i -= 2) {
        ans[0][i] = 'B';
    }
    ans[1][m-2] = ans[2][m-2] = 'B';
    FORR(row, ans) {
        FORR(c, row) {
            cout << c << " ";
        }
        cout << endl;
    }

    ans = vector<string>(n-1, string(m, 'R'));
    for (int i = 1; i < n-1; i += 2) {
        ans[i][m-1] = 'B';
    }
    FORR(row, ans) {
        FORR(c, row) {
            cout << c << " ";
        }
        cout << endl;
    }
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
