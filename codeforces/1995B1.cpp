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
        ll n, m; cin >> n >> m;
    vector<ll> a(n);
    FORR(x, a) cin >> x;
    sort(ALL(a));
    vector<pll> b;
    for (ll i = 0; i < n; i++) {
        if (b.empty() || b.back().first != a[i]) {
            b.push_back({a[i], 1});
        } 
        else {
            b.back().second++;
        }
    }
 
    ll ans = 0;
    for (ll i = 0; i < b.size(); i++) {
        pll cur = b[i];
        pll next = {0, 0};
        if (i + 1 < b.size() && b[i + 1].first == b[i].first + 1) next = b[i + 1];

        for (ll j = 0; j <= cur.second; j++) {
            if (j * cur.first <= m) {
                ll sum = min((m - j * cur.first) / (cur.first + 1), next.second);
                ans = max(ans, j * cur.first + sum * (cur.first + 1));
            }
            else {
                break;
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
