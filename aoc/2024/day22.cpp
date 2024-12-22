#include <bits/stdc++.h>
#include <numeric>
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

const int MOD = 16777216;
const int INF = 1e9;
const ll LLINF = 1e18;

const string fileName = "day22.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vl in = elf.readLongs();
    cout << SZ(in) << endl;
    map<vi, int> mp;
    int i = 0;
    FORR(x, in) {
        map<vi, int> mp2;
        vi seq;
        int prev = x;
        //cout << i++ << endl;
        FOR(i, 2000) {
            x ^= x * 64;
            x %= MOD;
            x ^= x / 32;
            x %= MOD;
            x ^= x * 2048;
            x %= MOD;
            seq.push_back(x % 10 - prev);
            prev = x % 10;
            if (SZ(seq) > 4) seq.erase(seq.begin());
            if (SZ(seq) == 4 && mp2.find(seq) == mp2.end()) mp2[seq] = max((ll)mp2[seq], x % 10);
        }
        FORR2(k, v, mp2) mp[k] += v;
    }
    ans1 = accumulate(ALL(in), 0LL);
    vi seq;
    FORR2(k, v, mp) {
        //FORR(x, k) cout << x << " "; cout << " -> " << v << endl;
        if (v > ans2) {
            ans2 = v;
            seq = k;
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
