#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define SINGLE_TEST 1

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
    vvi a(n, vi(k));
    FOR(i, n) FOR(j, k) cin >> a[i][j];
    vector<set<int>> c(n);
    FOR(i, n) c[i] = set<int>(ALL(a[i]));
    //int sum = 0;
    //FOR(i, n) sum += accumulate(ALL(a[i]), 0);
    //debug(sum);
    int p = 0;
    vi ans(n);
    FOR(i, k) {
        int mx = *c[p].begin(), mxidx = p;
        c[p].erase(mx);
        vi cards = {mx};
        int sum = mx;
        REP(j, 1, n-1) {
            int idx = (p + j) % n;
            auto pc = c[idx].upper_bound(mx);
            int card;
            if (pc == c[idx].end()) card = *c[idx].begin();
            else card = *pc;

            c[idx].erase(card);
            cards.push_back(card);
            sum += card;

            if (card > mx) {
                mx = card;
                mxidx = idx;
            }
        }
        // c[mxidx].insert(ALL(cards));
        // ans[mxidx] = accumulate(ALL(cards), 0);
        ans[mxidx] += sum;

        //cout << i + 1 << ": " << p << endl;
        //FOR(j, n){
        //    FORR(x, c[j]) cout << x << " ";
        //    cout << endl;
        //}
        //cout << endl;

        p = mxidx;
    }

    FOR(i, n) cout << ans[i] << endl;
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

