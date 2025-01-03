#include <bits/stdc++.h>
#include <cmath>
#include <string>
using namespace std;
#define SINGLE_TEST 1

typedef long long ll;
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
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

typedef vector<string> vs;
typedef vector<vector<string>> vvs;

void solve() {
    string s; cin >> s;
    ll g, r; cin >> g >> r;
    vvs v(r + 1, vs(r + 1, string(r + 1, '#')));
    if (s == "Evklida") {
        int rr = r*r;
        FOR(x, r+1) {
            FOR(y, r+1) {
                FOR(z, r+1) {
                    double minDist = (x-0.5)*(x-0.5) + (y-0.5)*(y-0.5) + (z-0.5)*(z-0.5);
                    if (minDist <= rr) {
                        v[x][y][z] = '%';
                    }
                    double maxDist = (x+0.5)*(x+0.5) + (y+0.5)*(y+0.5) + (z+0.5)*(z+0.5);
                    if (maxDist <= rr) {
                        v[x][y][z] = '.';
                    }
                }
            }
        }
    }
    else if (s == "Manygede") {
        FOR(x, r+1) {
            FOR(y, r+1) {
                FOR(z, r+1) {
                    ll rr = r - x;
                    double minDist = y + z;
                    if (minDist <= rr) {
                        v[x][y][z] = '%';
                    }
                    double maxDist = y + z + 1;
                    if (maxDist <= rr) {
                        v[x][y][z] = '.';
                    }
                }
            }
        }
    }
    else if (s == "Infinisto") {
        FOR(x, r+1) {
            FOR(y, r+1) {
                FOR(z, r+1) {
                    double minDist = max({x, y, z});
                    if (minDist <= r) {
                        v[x][y][z] = '%';
                    }
                    double maxDist = max({(x+0.5), (y+0.5), (z+0.5)});
                    if (maxDist <= r) {
                        v[x][y][z] = '.';
                    }
                }
            }
        }
    }

    vvs ans(r+1+max(g, r), vs(2*r+1, string(2*r+1, '#')));
    FOR(x, r+1) {
        FOR(y, r+1) {
            FOR(z, r+1) {
                // Bot right
                ans[x+r][y+r][z+r] = v[x][y][z];
                ans[x+r][r-y][z+r] = v[x][y][z];

                // Bot left
                ans[x+r][y+r][r-z] = v[x][y][z];
                ans[x+r][r-y][r-z] = v[x][y][z];

                // Top right
                ans[r-x][y+r][z+r] = v[x][y][z];
                ans[r-x][r-y][z+r] = v[x][y][z];

                // Top left
                ans[r-x][y+r][r-z] = v[x][y][z];
                ans[r-x][r-y][r-z] = v[x][y][z];
            }
        }
    }
    REVERSE(ans);
    FOR(x, max(r, g)) {
        ans[x][r][r] = '.';
    }

    if (r <= g)
    FOR(x, r+1+max(g, r)) {
        FOR(y, 2*r+1) {
            FOR(z, 2*r+1) {
                cout << ans[x][y][z];
            }
            cout << " ";
        }
        cout << endl;
    }
    else
    REP(x, r-g, 2*r) {
        FOR(y, 2*r+1) {
            FOR(z, 2*r+1) {
                cout << ans[x][y][z];
            }
            cout << " ";
        }
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
