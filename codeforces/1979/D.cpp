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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    FORR(c, s) c -= '0';
    bool f = s[0];
    int cnt = 1, i;
    for (i = 1; i < n; i++) {
        if (s[i] == f) {
            cnt++;
        }
        else {
            if (cnt == k) {
                f = !f;
                cnt = 1;
            }
            else {
                break;
            }
        }
    }
    string t;
    if (cnt < k) {
        REP(j, i, n-1) t.push_back(s[j] + '0');
        REPR(j, i-1, 0) t += s[j] + '0';
    }
    else {
        REP(j, i-k, n-1) t.push_back(s[j] + '0');
        REPR(j, i-k-1, 0) t += s[j] + '0';
    }
    bool ok = 1;
    FOR(i, n / k) {
        FOR(j, k-1) {
            if (t[i * k + j] != t[i * k + j + 1]) {
                ok = 0;
                break;
            }
        }
        if (i < n / k - 1 && t[(i+1) * k] == t[i * k]) ok = 0;
        if (!ok) break;
    }
    if (cnt >= k) i -= k;
    if (i == 0) i = n;
    cout << (ok ? i : -1) << endl;
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
