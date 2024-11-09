#include <vector>
#include <iostream>
#include <algorithm>
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
    vi a(n);
    FOR(i, n) cin >> a[i];
    int ans = 0;
    vi done(n+1);
    vi skip(n+1);
    vi noSkip(n+1);
    FOR(i, n) {
        if (a[i] > noSkip[i]) noSkip[i+1] = noSkip[i] + 1;
        else if (a[i] < noSkip[i]) noSkip[i+1] = noSkip[i] - 1;
        else noSkip[i+1] = noSkip[i];
    }
    REP(i, 1, n) {
        skip[i] = max(skip[i-1], noSkip[i-1]);
    }
    REP(i, 2, n) {
        done[i] = done[i-1];
        if (a[i-1] > done[i]) done[i]++;
        else if (a[i-1] < done[i]) done[i]--;
        int skipDone = skip[i];
        done[i] = max(done[i], skipDone);
    }
    
    //FORR(x, done) cout << x << " ";
    //cout << endl;
    //FORR(x, skip) cout << x << " ";
    //cout << endl;
    //FORR(x, noSkip) cout << x << " ";
    //cout << endl;

    cout << done.back() << endl;
    //cout << endl;
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
