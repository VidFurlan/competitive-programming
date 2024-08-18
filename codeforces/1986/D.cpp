#include <iostream>
#include <vector>
#include <algorithm>
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
    string s; cin >> s;
    if (n == 2) {
        cout << stoi(s) << endl;
        return;
    }
    ll ans = INF;
    bool f = 1;
    FOR(i, n) {
        s[i] -= '0';
        if (s[i] == 0 && (i != 1 || n > 3)) {
            cout << 0 << endl;
            return;
        }
        if (s[i] != 1) f = 0;
    }
    if (f) {
        cout << 11 << endl;
        return;
    }
    FOR(i, n - 1) {
        ll sum = 0;
        f = 0;
        if (s[i] * 10 + s[i + 1] > 1)
            sum = s[i] * 10 + s[i + 1];
        FOR(j, n) {
            if (i == j || i + 1 == j || s[j] == 1) continue;
            sum += s[j];
        }
        ans = min(ans, max(1ll, sum));
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
