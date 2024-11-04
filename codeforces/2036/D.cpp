#include <bits/stdc++.h>
#include <string>
#include <vector>
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
    int n, m; cin >> n >> m;
    vector<string> a(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) {
        FOR(j, m) {
            a[i][j] -= '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < min(n, m) / 2; i++) {
        vi c;
        for (int j = i; j < m - i; j++) {
            c.push_back(a[i][j]);
        }
        for (int j = i + 1; j < n - i; j++) {
            c.push_back(a[j][m - i - 1]);
        }
        for (int j = m - i - 2; j >= i; j--) {
            c.push_back(a[n - i - 1][j]);
        }
        for (int j = n - i - 2; j > i; j--) {
            c.push_back(a[j][i]);
        }
        int k = SZ(c);
        c.push_back(c[0]);
        c.push_back(c[1]);
        c.push_back(c[2]);
        //FORR(x, c) cout << x << " ";
        //cout << endl;
        FOR(i, k) {
            if (c[i] == 1 && c[i + 1] == 5 && c[i + 2] == 4 && c[i + 3] == 3) {
                ans++;
            }
        }
    }
    cout << ans << endl;
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
