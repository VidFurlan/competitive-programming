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
    int n, k, q; cin >> n >> k >> q;
    vvi a(n, vi(k));
    FOR(i, n) {
        FOR(j, k) {
            cin >> a[i][j];
        }
    }
    vvi b(n, vi(k));
    b[0] = a[0];
    FOR(i, n-1) {
        FOR(j, k) {
            b[i+1][j] = b[i][j] | a[i+1][j];
        }
    }

    //FOR(i, n) {
    //    FOR(j, k) {
    //        cout << b[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    FOR(query, q) {
        int m; cin >> m;
        vector<tuple<int, char, int>> req(m);
        FORR(tmp, req) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            tmp = {r, o, c};
        }

        int low = 0, high = n-1;
        
        FOR(mm, m) {
            auto [r, o, c] = req[mm];
            
            if (o == '<') {
                int l = low, h = high;
                while (l <= h) {
                    int mid = (l + h) / 2;
                    if (b[mid][r] < c) {
                        l = mid + 1;
                    } 
                    else {
                        h = mid - 1;
                    }
                }
                high = h;
            } 
            else if (o == '>') {
                int l = low, h = high;
                while (l <= h) {
                    int mid = (l + h) / 2;
                    if (b[mid][r] > c) {
                        h = mid - 1;
                    } 
                    else {
                        l = mid + 1;
                    }
                }
                low = l;
            }
            
            if (low > high) break;
        }

        cout << (low > high ? -1 : low + 1) << endl;
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
