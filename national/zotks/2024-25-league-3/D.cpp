#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define SINGLE_TEST 1

typedef long long ll;
typedef unsigned long long ull; 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
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
    string s, t; cin >> s >> t;
    int n; cin >> n; n+=2;
    int m = SZ(s);
    vvi adj(n);
    vector<string> a(n);
    a[0] = s; a[n-1] = t;
    REP(i, 1, n-2) cin >> a[i];
    FOR(pos, m) {
        unordered_map<string, vi> mp;
        auto addString = [&](string s, int idx, int pos) -> void {
            string c = s;
            c[pos] = '_';
            mp[c].push_back(idx);
        };
        addString(s, 0, pos);
        addString(t, n-1, pos);
        REP(i, 1, n-2) {
            addString(a[i], i, pos);
        }
        FORR2(dummy, b, mp) {
            int k = SZ(b);
            FOR(u, k) {
                REP(v, u+1, k-1) {
                    adj[b[u]].push_back(b[v]);
                    adj[b[v]].push_back(b[u]);
                }
            }
        }
    }
    //FOR(i, n) { cout << i << ": "; FORR(x, adj[i]) cout << x << " "; cout << endl; }
    vi dist(n, INF);
    dist[0] = 1;
    priority_queue<pii> pq;
    pq.push({1, 0});
    while(SZ(pq)) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        FORR(v, adj[u]) {
            if (d + 1 < dist[v]) {
                dist[v] = d+1;
                pq.push({d+1, v});
            }
        }
    }
    cout << dist[n-1] << endl;
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
