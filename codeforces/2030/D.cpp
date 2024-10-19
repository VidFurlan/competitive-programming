#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
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
    int n, q; cin >> n >> q;
    vi p(n), mx(n);
    cin >> p[0];
    p[0]--;
    mx[0] = p[0];
    REP(i, 1, n-1) {
        cin >> p[i];
        p[i]--;
        mx[i] = max(mx[i-1], p[i]);
    }
    vector<bool> b(n);
    FOR(i, n) {
        if (i == mx[i]) {
            b[i] = 1;
        }
    }

    string s; cin >> s;
    int bad = 0;
    FOR(i, n - 1) {
        if (s[i] == 'L' && s[i+1] == 'R' && !b[i]) {
            bad++;
        }
    }

    // debug(bad);
    FOR(qq, q) {
        int idx; cin >> idx;
        idx--;

        bool badPrev = (s[idx-1] == 'L' && s[idx] == 'R' && !b[idx-1]);
        bool badNext = (s[idx] == 'L' && s[idx+1] == 'R' && !b[idx]);
        s[idx] = (s[idx] == 'L') ? 'R' : 'L';
        bad -= badPrev + badNext;

        if (s[idx-1] == 'L' && s[idx] == 'R' && !b[idx-1]) {
            bad++;
        }
        if (s[idx] == 'L' && s[idx+1] == 'R' && !b[idx]) {
            bad++;
        }

        if (bad == 0) {
            cout << "YES" << endl;
        } 
        else {
            cout << "NO" << endl;
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
        // cout << "---" << endl;
    }
#endif

    return 0;
}
