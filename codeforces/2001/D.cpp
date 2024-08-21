#include <bits/stdc++.h>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;
#define SINGLE_TEST 0

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
#define MODD 1e9 + 7

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const int MAXN = 300005;

void solve() {
    int n; cin >> n; 
    vi a(n);
    FOR(i, n) cin >> a[i];
    bitset<MAXN> b;
    int k = 0;
    FOR(i, n) {
        if (b[a[i]]) continue;
        b[a[i]] = 1;
        k++;
    }

    vi l(n + 1, INF);
    FOR(i, n)
        l[a[i]] = i;

    priority_queue<int, vi, greater<int>> ls(ALL(l));
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> mx, mn;

    bitset<MAXN> seen;
    FOR(i, ls.top() + 1) {
        mx.push({-a[i], i});
        mn.push({a[i], i});
    }

    vi ans;
    int i = 0;
    bool t = 1;
    while (!mn.empty()) {
        auto [x, j] = (t ? mx.top() : mn.top());
        if (t) {
            mx.pop();
            x *= -1;
        }        
        else mn.pop();

        ans.push_back(x);
        t = !t;
        i = j + 1;
        seen[x] = 1;
        while (ls.top() != INF && seen[a[ls.top()]]) {
            int j = ls.top();
            ls.pop();

            REP(k, j + 1, min(ls.top(), n - 1)) {
                mx.push({-a[k], k});
                mn.push({a[k], k});
            }
        }

        while (!mx.empty() && (seen[-mx.top()[0]] || mx.top()[1] < i)) mx.pop();
        while (!mn.empty() && (seen[mn.top()[0]] || mn.top()[1] < i)) mn.pop();
    }

    cout << ans.size() << endl;
    FORR(x, ans) cout << x << " ";
    cout << endl;
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
