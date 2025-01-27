#include <bits/stdc++.h>
#include <ios>
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
    int n; cin >> n;
    vector<pair<double, double>> a(n);
    FOR(i, n) cin >> a[i].fi;
    FOR(i, n) cin >> a[i].se;
    if (n == 1) {
        cout << a[0].fi << endl;
        return;
    }
    sort(ALL(a));
    //FOR(i, n) cout << a[i].fi << " "; cout << endl;
    //FOR(i, n) cout << a[i].se << " "; cout << endl;
    vector<double> pref(n), suff(n);
    pref[0] = a[0].se;
    suff[n-1] = a[n-1].se;
    REP(i, 1, n-1) pref[i] = max(pref[i-1] + a[i].fi - a[i-1].fi, a[i].se);
    REPR(i, n-2, 0) suff[i] = max(suff[i+1] + a[i+1].fi - a[i].fi, a[i].se);
    //FOR(i, n) cout << setw(3) << pref[i] << " "; cout << endl;
    //FOR(i, n) cout << setw(3) << suff[i] << " "; cout << endl;
    double t = LLINF;
    double ans = -1;
    FOR(i, n-1) {
        double dist = a[i+1].fi - a[i].fi;
        if (dist + min(pref[i], suff[i+1]) <= max(pref[i], suff[i+1]))  {
            if (max(pref[i], suff[i+1]) < t) {
                if (pref[i] > suff[i+1]) {
                    t = pref[i];
                    ans = a[i].fi;
                }
                else {
                    t = suff[i+1];
                    ans = a[i+1].fi;
                }
            }
            continue;
        }

        double p1 = a[i].fi;
        double p2 = a[i+1].fi;
        if (pref[i] > suff[i+1]) {
            p2 -= pref[i] - suff[i+1];
        }
        else if (pref[i] < suff[i+1]) {
            p1 += suff[i+1] - pref[i];
        }
        double cur = max(pref[i], suff[i+1]) + (p2 - p1) / 2.0;
        if (cur < t) {
            t = cur;
            ans = (p1 + p2) / 2.0;
        }
        //cout << i << ": "; debug(cur);
    }
    cout << fixed << ans << endl;
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
