#include <bits/stdc++.h>
#include <string>
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
    int n; cin >> n;
    vi a(n);
    FORR(x, a) cin >> x;
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }
        FORR(c, s) c -= 'a';
        vector<set<int>> r(26);
        FOR(i, n) {
            r[s[i]].insert(a[i]);
        }

        bool f = 0;
        map<int, int> mp;
        FOR(i, 26) {
            FORR(x, r[i]) {
                mp[x]++;
            }
            if (r[i].size() > 1) {
                f = 1;
                break;
            }
        }
        FORR(x, mp) {
            if (x.se > 1) {
                f = 1;
                break;
            }
        }
        if (f) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
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
