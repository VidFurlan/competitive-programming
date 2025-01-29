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
    int q; cin >> q;
    ll mn = -LLINF;
    ll mx = LLINF;

    auto check = [&](ll n, ll a, ll b) -> bool {
        if (n <= 0) return 0;
        ll curMn = (n-2)*(a-b)+a+1;
        ll curMx = (n-1)*(a-b)+a;
        if (n == 1) {
            curMn = 1;
            curMx = a;
        }
        //cout << curMn << " " << curMx << " : " << !(curMn > mx || mn > curMx) << endl;
        return !(curMn > mx || mn > curMx);
    };

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            ll a, b, n; cin >> a >> b >> n;
            ll curMn = (n-2)*(a-b)+a+1;
            ll curMx = (n-1)*(a-b)+a;
            if (n == 1) {
                curMn = 1;
                curMx = a;
            }
            bool ok = !(curMn > mx || mn > curMx);
            if (ok) {
                mx = min(mx, curMx);
                mn = max(mn, curMn);
                cout << 1 << " ";
            }
            else {
                cout << 0 << " ";
            }
            //cout << endl;
            //debug(curMn);
            //debug(curMx);
        }
        else {
            ll a, b; cin >> a >> b;
            ll ans1 = max(1ll, (mn-b-1)/(a-b)+1);
            ll ans2 = max(1ll, (mx-b-1)/(a-b)+1);
            cout << (ans1 == ans2 ? ans1 : -1) << " ";
        }
    }
    cout << endl;
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
