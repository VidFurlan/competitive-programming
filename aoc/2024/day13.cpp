#include <chrono>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "helper_elf.hpp"
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

const string fileName = "day13.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readLines();
    int n = SZ(in);
    FOR(i, n/4+1) {
        ll ax = stoi(in[i*4].substr(12, 2)), ay = stoi(in[i*4].substr(18, 2));
        ll bx = stoi(in[i*4+1].substr(12, 2)), by = stoi(in[i*4+1].substr(18, 2));
        ll tx = 0, ty = 0;
        stringstream s(in[i*4+2]);
        FOR(i, 3) {
            string t; s >> t;
            if (i == 1) {
                tx = stol(t.substr(2, SZ(t) - 3));
            }
            if (i == 2) {
                ty = stol(t.substr(2, SZ(t) - 2));
            }
        }
        //cout << ax << " " << ay << endl;
        //cout << bx << " " << by << endl;
        //cout << tx << " " << ty << endl;
        
        double kb = (ax*ty - tx*ay) / (double)(by*ax-bx*ay);
        double ka = (tx - kb*bx) / ax;
        if (kb == (int)kb && ka == (int)ka) {
            ans1 += ka*3 + kb;
        }

        tx += 10000000000000;
        ty += 10000000000000;

        kb = (ax*ty - tx*ay) / (double)(by*ax-bx*ay);
        ka = (tx - kb*bx) / ax;
        if (kb == (ll)kb && ka == (ll)ka) {
            ans2 += ka*3 + kb;
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
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Time: " << duration.count() / 1e6 << " ms" << std::endl;

    debug(ans1);
    debug(ans2);

    return 0;
}
