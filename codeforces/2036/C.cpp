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
    string s; cin >> s;
    FORR(c, s) c -= '0';
    int n = SZ(s);
    int q; cin >> q;
    vector<bool> f(n);
    int cnt = 0;
    FOR(i, n-3) {
        if (s[i] == 1 && s[i+1] == 1 && s[i+2] == 0 && s[i+3] == 0) {
            f[i] = 1;
            cnt++;
        }
    }
    while (q--) {
        int i, v; cin >> i >> v;
        i--;
        s[i] = v;
        //FORR(c, s) cout << (char)(c + '0');
        //cout << endl;
        FOR(j, 4) {
            if (i - j < 0) continue;
            if (i - j + 3 >= n) continue;
            //cout << i - j << endl;
            if (s[i-j] == 1 && s[i-j+1] == 1 && s[i-j+2] == 0 && s[i-j+3] == 0) {
                if (f[i-j] == 0) {
                    f[i-j] = 1;
                    cnt++;
                }
            } 
            else {
                if (f[i-j] == 1) {
                    f[i-j] = 0;
                    cnt--;
                }
            }
        }
        //FOR(i, n) cout << f[i];
        //cout << endl;
        //debug(cnt);
        if (cnt) cout << "YES" << endl;
        else cout << "NO" << endl;
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
