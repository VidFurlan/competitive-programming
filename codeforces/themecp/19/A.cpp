#include <algorithm>
#include <iostream>
#include <vector>
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
    int ans = 0;
    ans += n / 15;
    n %= 15;
    if (n < 15 && ans) {
        n += 15;
        ans -= 1;
    }
    if (n == 1) ans += 1;
    else if (n == 2) ans += 2;
    else if (n == 3) ans += 1;
    else if (n == 4) ans += 2;
    else if (n == 5) ans += 3;
    else if (n == 6) ans += 1;
    else if (n == 7) ans += 2;
    else if (n == 8) ans += 3;
    else if (n == 9) ans += 2;
    else if (n == 10) ans += 1;
    else if (n == 11) ans += 2;
    else if (n == 12) ans += 2;
    else if (n == 13) ans += 2;
    else if (n == 14) ans += 3;
    else if (n == 15) ans += 1;
    else if (n == 16) ans += 2;
    else if (n == 17) ans += 3;
    else if (n == 18) ans += 2;
    else if (n == 19) ans += 3;
    else if (n == 20) ans += 2;
    else if (n == 21) ans += 2;
    else if (n == 22) ans += 3;
    else if (n == 23) ans += 3;
    else if (n == 24) ans += 3;
    else if (n == 25) ans += 2;
    else if (n == 26) ans += 3;
    else if (n == 27) ans += 3;
    else if (n == 28) ans += 3;
    else if (n == 29) ans += 4;
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
