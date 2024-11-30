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

vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
map<char, int> dirMp = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};
vector<string> a;
vvi seen;
vvi esc;    
int n, m; 

int dfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 1;
    if (esc[r][c] != -1) return esc[r][c];
    if (seen[r][c] == 1) return 0;
    if (seen[r][c] == 2) return esc[r][c];
    seen[r][c] = 1;
    if (a[r][c] == -1) {
        esc[r][c] = 0;
    }
    else {
        int dr = dirs[a[r][c]].fi, dc = dirs[a[r][c]].se;
        esc[r][c] = dfs(r + dr, c + dc);
    }
    seen[r][c] = 2;
    return esc[r][c];
}

bool canEsc(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return 1;
    if (a[r][c] == -1) return 0;
    return esc[r][c];
}

void solve() {
    cin >> n >> m;
    a = vector<string>(n);
    seen = vvi(n, vi(m, 0));
    esc = vvi(n, vi(m, -1));
    FOR(i, n) cin >> a[i];
    FORR(r, a) {
        FORR(c, r) {
            if (c == '?') c = -1;
            else c = dirMp[c];
        }
    }

    int ans = 0;
    FOR(i, n) {
        FOR(j, m) {
            if (a[i][j] != -1) dfs(i, j);
        }
    }
    FOR(i, n) {
        FOR(j, m) {
            if (a[i][j] == -1) {
                bool ok = 0;
                FORR(d, dirs) {
                    if (!canEsc(i + d.fi, j + d.se)) {
                        ok = 1;
                        break;
                    }
                }
                if (ok) esc[i][j] = 0;
            }
            ans += esc[i][j] == 0;
        }
    }
    // FORR(r, esc) {
    //     FORR(c, r) cout << setw(3) << c << " ";
    //     cout << endl;
    // }
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
