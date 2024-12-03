#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define SINGLE_TEST 1

const string fileName = "day2.in";

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

ifstream file(fileName);
ll ans1 = 0;
ll ans2 = 0;

void solve() {
    string line;
    while (getline(file, line)) {
        vi a;
        stringstream ss(line);
        int x;
        while (ss >> x) {
            a.push_back(x);
        }
        int n = a.size();
        if (n == 0) {
            break;
        }
        REP(i, -1, SZ(a)-1) {
            vi b;
            FOR(j, n) {
                if (j == i) continue;
                b.push_back(a[j]);
            }
            bool ok = 1;
            FOR(i, SZ(b)-1) {
                if (b[i] < b[i+1] && abs(b[i] - b[i+1]) >= 1 && abs(b[i] - b[i+1]) <= 3) continue;
                ok = 0;
                break;
            }
            if (ok) {
                if (i == -1) {
                    ans1++;
                }
                ans2++;
                break;
            }
            ok = 1;
            FOR(i, SZ(b)-1) {
                if (b[i] > b[i+1] && abs(b[i] - b[i+1]) >= 1 && abs(b[i] - b[i+1]) <= 3) continue;
                ok = 0;
                break;
            }
            if (ok) {
                if (i == -1) {
                    ans1++;
                }
                ans2++;
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto start = std::chrono::high_resolution_clock::now();

#if SINGLE_TEST
    solve();
#else
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
#endif

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Time: " << duration.count() << " ms" << std::endl;

    debug(ans1);
    debug(ans2);

    return 0;
}
