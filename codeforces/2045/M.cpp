#include <bits/stdc++.h>
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
    int R, C; cin >> R >> C;
    vector<string> a(R);
    FOR(i, R) cin >> a[i];
    int cnt = 0;
    FOR(r, R) FOR(c, C) cnt += (a[r][c] != '.');

    vi dy = {0, 0, 1, -1};
    vi dx = {1, -1, 0, 0};
    set<pii> seen;
    string enter, exit;
    auto dfs = [&](int r, int c, int d, auto dfs) -> void {
        if (r < 0 || r >= R || c < 0 || c >= C) {
            char dir;
            int pos;
            if (r < 0) {
                dir = 'N';
                pos = c;
            }
            else if (r >= R) {
                dir = 'S';
                pos = c;
            }
            else if (c < 0) {
                dir = 'W';
                pos = r;
            }
            else {
                dir = 'E';
                pos = r;
            }
            exit = dir + to_string(pos + 1);
            //cout << endl;
            return;
        }
        //cout << r << " " << c << " " << d << endl;
        if (a[r][c] == '.') {
            dfs(r + dy[d], c + dx[d], d, dfs);
        }
        else {
            seen.insert({r, c});
            if (a[r][c] == '/') {
                if (d == 0) dfs(r - 1, c, 3, dfs);
                else if (d == 1) dfs(r + 1, c, 2, dfs);
                else if (d == 2) dfs(r, c - 1, 1, dfs);
                else dfs(r, c + 1, 0, dfs);
            }
            else {
                if (d == 0) dfs(r + 1, c, 2, dfs);
                else if (d == 1) dfs(r - 1, c, 3, dfs);
                else if (d == 2) dfs(r, c + 1, 0, dfs);
                else dfs(r, c - 1, 1, dfs);
            }
        }
    };

    set<string> ans;

    FOR(c, C) {
        seen.clear();
        dfs(0, c, 2, dfs);
        char dir = 'N';
        int pos = c + 1;
        if (seen.size() == cnt) {
            enter = dir + to_string(pos);
            ans.insert(enter);
            ans.insert(exit);
        }
        seen.clear();
        dfs(R - 1, c, 3, dfs);
        dir = 'S';
        pos = c + 1;
        if (seen.size() == cnt) {
            enter = dir + to_string(pos);
            ans.insert(enter);
            ans.insert(exit);
        }
    }

    FOR(r, R) {
        seen.clear();
        dfs(r, 0, 0, dfs);
        char dir = 'W';
        int pos = r + 1;
        if (seen.size() == cnt) {
            enter = dir + to_string(pos);
            ans.insert(enter);
            ans.insert(exit);
        }
        seen.clear();
        dir = 'E';
        pos = r + 1;
        dfs(r, C - 1, 1, dfs);
        if (seen.size() == cnt) {
            enter = dir + to_string(pos);
            ans.insert(enter);
            ans.insert(exit);
        }
    }

    cout << SZ(ans) << endl;
    if (SZ(ans)) {
        FORR(s, ans) cout << s << " ";
        cout << endl;
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
