#include <bits/stdc++.h>
#include <functional>
#include <queue>
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
    int n, d, k; cin >> n >> d >> k;
    vector<pii> a(k);
    FOR(i, k) cin >> a[i].fi >> a[i].se;
    sort(RALL(a));
    priority_queue<int, vi, greater<int>> pq;
    int l = 1, r = 0;
    FOR(i, d) {
        r++;
        while (SZ(a) && a.back().fi <= r) {
            pq.push(a.back().se);
            a.pop_back();
        }
    }
    pii mn = {SZ(pq), 1}, mx = {SZ(pq), 1};
    while (r < n) {
        r++;
        while (SZ(a) && a.back().fi <= r) {
            pq.push(a.back().se);
            a.pop_back();
        }
        while (SZ(pq) && pq.top() <= l) {
            pq.pop();
        }
        l++;

        mn = min(mn, {SZ(pq), l});
        if (mx.fi < SZ(pq)) mx = {SZ(pq), l};
    }

    //cout << "!" << mx.fi << " " << mn.fi << endl;
    cout << mx.se << " " << mn.se << endl;
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
