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
    ll n; cin >> n;
    vector<ll> a(n);
    FORR(x, a) cin >> x;

    bool f = 0;
    FORR(x, a) {
        if (x == 1 && f) {
            cout << -1 << endl;
            return;
        }
        else if (x != 1) {
            f = 1;
        }
    }

    ll ans = 0, total = 0;
    for (ll i = 1; i < n; i++) {
        ll prevNum = a[i - 1];
        if (prevNum < a[i] && total != 0) {
            ll power = 0;
            bool f = 0;
            while (power < total && prevNum < a[i]) {
                prevNum *= prevNum;
                power++;
            }

            if (prevNum > a[i]) power--;
            total -= power;
            ans += total;
        }
        else {
            ll cur = 0, curNum = a[i];
            while (curNum < a[i - 1]) {
                curNum *= curNum;
                cur++;
            }

            total += cur;
            ans += total;
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
