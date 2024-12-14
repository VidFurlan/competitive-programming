#include <array>
#include <chrono>
#include <queue>
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

const string fileName = "day14.in";
ifstream file(fileName);
Elf elf = Elf(file);

ll ans1 = 0;
ll ans2 = 0;

void solve() {
    vector<string> in = elf.readStrings();
    int n = 101, m = 103;
    queue<array<int, 4>> q;
    int cycle = 0;
    set<queue<array<int, 4>>> seen;
    FOR(i, SZ(in) / 2) {
        int x = 0, y = 0;
        int j = 2;
        for (; in[i * 2][j] != ','; j++) {
            x = x * 10 + in[i * 2][j] - '0';
        }
        j++;
        for (; j < SZ(in[i * 2]); j++) {
            y = y * 10 + in[i * 2][j] - '0';
        }
        int vx = 0, vy = 0;
        bool neg = 0;
        j = 2;
        for (; in[i * 2 + 1][j] != ','; j++) {
            if (in[i * 2 + 1][j] == '-') {
                neg = 1;
                continue;
            }
            vx = vx * 10 + in[i * 2 + 1][j] - '0';
        }
        if (neg) vx *= -1;
        neg = 0;
        j++;
        for (; j < SZ(in[i * 2 + 1]); j++) {
            if (in[i * 2 + 1][j] == '-') {
                neg = 1;
                continue;
            }
            vy = vy * 10 + in[i * 2 + 1][j] - '0';
        }
        if (neg) vy *= -1;
        q.push({x, y, vx, vy});
        //cout << x << " " << y << " " << vx << " " << vy << endl;
    }
    //cout << endl;

    ofstream out("day14.out");
    FOR(i, 10000000) {
        queue<array<int, 4>> q2;
        vector<string> grid(n, string(m, '.'));
        while (!q.empty()) {
            auto [x, y, vx, vy] = q.front();
            q.pop();
            int xx = x + vx, yy = y + vy;
            if (xx >= n) xx = xx % n;
            if (yy >= m) yy = yy % m;
            if (xx < 0) xx = n + xx;
            if (yy < 0) yy = m + yy;
            q2.push({xx, yy, vx, vy});
            grid[xx][yy] = '#';
        }
        out << "After " << i + 1 << " seconds:" << endl;
        FORR(row, grid) out << row << endl;
        FORR(row, grid) {
            int streak = 0;
            FORR(c, row) {
                if (c == '#') streak++;
                else {
                    if (streak >= 10) {
                        ans2 = i + 1;
                        break;
                    }
                    streak = 0;
                }
            }
        }
        out << endl;
        if (seen.count(q2)) {
            cout << "Cycle found at " << i << endl;
            break;
        }
        seen.insert(q2);
        q = q2;
        if (i == 99) {
            queue<array<int, 4>> q2 = q;
            vi qart(4);
            while (!q.empty()) {
                auto [x, y, vx, vy] = q.front();
                q.pop();
                if (x < n / 2 && y < m / 2) qart[0]++;
                else if (x < n / 2 && y > m / 2) qart[1]++;
                else if (x > n / 2 && y < m / 2) qart[2]++;
                else if (x > n / 2 && y > m / 2) qart[3]++;
            }
            ans1 = qart[0] * qart[1] * qart[2] * qart[3];
            q = q2;
        }
    }
    out.close();
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
