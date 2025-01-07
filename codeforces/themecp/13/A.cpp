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
    int n, k; cin >> n >> k;
    k *= 2;
    vi a(n), b(n);
    FOR(i, n) cin >> a[i];
    FOR(i, n) cin >> b[i];
    int l = 0, lCur = 0;
    map<int, int> mp1, mp2;
    FOR(i, n) {
        mp1[a[i]]++;
        mp2[b[i]]++;
    }
    vi aOnly, bOnly;
    vi both;
    FOR(i, n) {
        if (mp1[a[i]] == 1 && mp2[a[i]] == 1) {
            both.push_back(a[i]);
            mp1[a[i]] = mp2[a[i]] = 0;
        } 
        else if (mp1[a[i]] == 2) {
            aOnly.push_back(a[i]);
            mp1[a[i]] = 0;
        }
    }
    FOR(i, n) {
        if (mp2[b[i]] == 2) {
            bOnly.push_back(b[i]);
            mp2[b[i]] = 0;
        }
    }
    vi ansA, ansB;
    while (SZ(ansA) + 1 < k && SZ(aOnly)) {
        ansA.push_back(aOnly.back());
        ansA.push_back(aOnly.back());
        aOnly.pop_back();
    }
    while (SZ(ansB) + 1 < k && SZ(bOnly)) {
        ansB.push_back(bOnly.back());
        ansB.push_back(bOnly.back());
        bOnly.pop_back();
    }
    while (SZ(ansA) < k) {
        ansA.push_back(both.back());
        ansB.push_back(both.back());
        both.pop_back();
    }
    FORR(x, ansA) cout << x << " "; cout << endl;
    FORR(x, ansB) cout << x << " "; cout << endl;
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
