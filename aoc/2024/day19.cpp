#include "helper_elf.hpp"
#include <chrono>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <fstream>
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

const string fileName = "day19.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readLines();
    vector<string> t;
    stringstream ss(in[0]);
    string s;
    while (ss >> s) {
        if (s[SZ(s) - 1] == ',') {
            s.pop_back();
        }
        t.push_back(s);
        //cout << s << endl;
    }
    
    set<string> st(ALL(t));
    REP(i, 1, SZ(in) - 1) {
        if (!SZ(in[i])) continue;
        //cout << "\t" << in[i] << endl;
        string s = in[i];
        int n = SZ(s);
        vl dp(n+1);
        dp[0] = 1;
        FOR(i, n) {
            FOR(j, i + 1) {
                if (!dp[j]) continue;
                string t = s.substr(j, i - j + 1);
                if (st.find(t) != st.end()) {
                    dp[i+1] += dp[j];
                }
            }
        }
        if (dp.back()) ans1++;
        ans2 += dp.back();
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
