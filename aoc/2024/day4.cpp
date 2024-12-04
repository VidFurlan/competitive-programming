#include <bits/stdc++.h>
#include <chrono>
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

const string fileName = "day4.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    int n = SZ(in), m = SZ(in[0]);
    FOR(i, 3) {
        in.push_back("");
        FOR(j, m) in[n + i] += '.';
    }
    FORR(x, in) {
        FOR(i, 3) x += '.';
    }
    FOR(i, n) {
        FOR(j, m) {
            vector<string> a;
            a.push_back("");
            FOR(k, 4) {
                a[0] += in[i + k][j];
            }
            a.push_back("");
            FOR(k, 4) {
                a[1] += in[i][j + k];
            }
            a.push_back("");
            a.push_back("");
            FOR(k, 4) {
                a[2] += in[i + k][j + k];
                a[3] += in[i + k][j + 3 - k];
            }
            FOR(x, 4) {
                if (a[x] == "XMAS") {
                    ans1++;
                }
                REVERSE(a[x]);
                if (a[x] == "XMAS") {
                    ans1++;
                }
            }
            
            a.push_back("");
            a.push_back("");
            FOR(k, 3) {
                a[4] += in[i + k][j + k];
                a[5] += in[i + k][j + 2 - k];
            } 
            int ok = 0;
            REP(x, 4, 5) {
                if (a[x] == "MAS") {
                    ok++;
                }
                REVERSE(a[x]);
                if (a[x] == "MAS") {
                    ok++;
                }
            }
            if (ok == 2) {
                ans2++;
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
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

    std::cout << "Time: " << duration.count() / 1e6 << " ms" << std::endl;

    debug(ans1);
    debug(ans2);

    return 0;
}
