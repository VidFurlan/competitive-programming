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

const string fileName = "day7.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vvl in = elf.readLong2D();
    FORR(a, in) {
        ll tar = a[0];
        unordered_set<ll> s;
        s.insert(0ll);
        REP(i, 1, SZ(a) - 1) {
            unordered_set<ll> t;
            FORR(x, s) {
                if (x + a[i] <= tar)
                    t.insert(x + a[i]);
                if (x * a[i] <= tar)
                    t.insert(x * a[i]);
            }
            s = t;
        }
        if (s.find(tar) != s.end()) {
            ans1 += tar;
        }
    }

    FORR(a, in) {
        ll tar = a[0];
        unordered_set<ll> s;
        s.insert(0ll);
        REP(i, 1, SZ(a) - 1) {
            unordered_set<ll> t;
            FORR(x, s) {
                if (x + a[i] <= tar)
                    t.insert(x + a[i]);
                if (x * a[i] <= tar)
                    t.insert(x * a[i]);
                int cnt = log10(a[i]) + 1;
                if (x * pow(10, cnt) + a[i] <= tar && x * pow(10, cnt) + a[i] > 0)
                    t.insert(x * pow(10, cnt) + a[i]);
            }
            s = t;
        }
        if (s.find(tar) != s.end()) {
            ans2 += tar;
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
