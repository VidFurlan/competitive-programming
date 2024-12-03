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

ll fact(ll n) {
    if (n <= 1) return 1;
    ll ans = 1;
    REP(i, 2, n) {
        ans *= i;
    }
    return ans;
}

ll cntPerm(string s) {
    ll n = SZ(s);
    map<char, int> mp;
    FORR(c, s) mp[c]++;
    ll den = 1;
    FORR2(k, v, mp) {
        den *= fact(v);
    }
    return fact(n) / den;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> mp;
    FOR(i, n) {
        mp[s[i]]++;
    }
    if (mp.size() == 1) {
        cout << s << endl;
        return;
    }
    string ans;
    ll mn = LLINF;
    FOR(i, n) {
        FOR(j, n) {
            string t = s;
            t[i] = s[j];
            ll cnt = cntPerm(t);
            if (cnt < mn) {
                mn = cnt;
                ans = t;
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
