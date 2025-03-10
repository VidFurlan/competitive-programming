#include <bits/stdc++.h>
#include <chrono>
#include <unordered_set>
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

const string fileName = "day9.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    string in = elf.readStrings()[0];
    int n = SZ(in);
    vi a;
    unordered_map<int, int> mp;
    FOR(i, n) {
        if (i % 2 == 0) {
            while (in[i] - '0' > 0) {
                a.push_back(i / 2);
                mp[i / 2]++;
                in[i]--;
            }
        }
        else {
            while (in[i] - '0' > 0) {
                a.push_back(-1);
                in[i]--;
            }
        }
    }
    vi b = a;
    int mx = a.back();
    REPR(i, mx, 1) {
        int cur = 0;
        int need = mp[i];
        FOR(j, SZ(b)) {
            if (b[j] == i) break;
            if (b[j] == -1) {
                cur++;
                if (cur == mp[i]) {
                    FOR(k, SZ(b)) {
                        if (b[k] == i) {
                            b[k] = -1;
                        }
                    }
                    while (cur-- > 0) {
                        b[j - cur] = i;
                    }
                    break;
                }
            }
            else {
                cur = 0;
            }
        }
    }

    int l = 0, r = SZ(a) - 1;
    while (l < r) {
        if (a[l] != -1) {
            l++;
        }
        else if (a[r] == -1) {
            r--;
        }
        else {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }
    FOR(i, SZ(a)) {
        if (a[i] != -1) ans1 += a[i] * i * 1ll;
        if (b[i] != -1) ans2 += b[i] * i * 1ll;
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
