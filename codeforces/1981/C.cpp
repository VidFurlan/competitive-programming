#include <bits/stdc++.h>
using namespace std;
#define SINGLE_TEST 0

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

void solve() {
    int n; cin >> n;
    vi a(n);
    vi b;
    vi ans(n);
    FOR(i, n) {
        cin >> a[i];
        if (a[i] != -1) b.push_back(i);
    }
    if (!SZ(b)) {
        FOR(i, n) cout << (i % 2 == 1 ? 1 : 2) << " ";
        cout << endl;    
        return;
    }
    int m = SZ(b);
    ans[b[0]] = a[b[0]];
    FOR(i, m-1) {
        ll x = a[b[i]], y = a[b[i+1]];
        ans[b[i]] = x;
        ans[b[i+1]] = y;
        if (b[i] + 1 == b[i+1]) {
            int mn = min(a[b[i]], a[b[i+1]]);
            int mx = max(a[b[i]], a[b[i+1]]);
            if (mx / 2 != mn) {
                cout << -1 << endl;
                return;
            }
            continue;
        }
        vector<pii> vx{{0, x}}, vy{{0, y}};   
        int c = 1;
        while ((x << 1ll) <= INF) {
            x <<= 1ll;
            vx.push_back({c++, x});
        }
        c = 1;
        while ((y << 1ll) <= INF) {
            y <<= 1ll;
            vy.push_back({c++, y});
        }
        x = a[b[i]], y = a[b[i+1]];
        c = 1;
        while ((x >> 1ll) >= 1) {
            x >>= 1ll;
            vx.push_back({c++, x});
        }
        c = 1;
        while ((y >> 1ll) >= 1) {
            y >>= 1ll;
            vy.push_back({c++, y});
        }
        sort(ALL(vx));
        sort(ALL(vy));
        //FORR2(xx, xxx, vx) cout << xx << " " << xxx << endl;
        //cout << endl;
        //FORR2(xx, xxx, vy) cout << xx << " " << xxx << endl;
        //cout << endl;
        int odd = 100, even = 100;
        int tarOdd = 0, tarEven = 0;
        FOR(xx, SZ(vx)) {
            FOR(yy, SZ(vy)) {
                if (vx[xx].fi + vy[yy].fi <= b[i+1] - b[i] && vx[xx].se == vy[yy].se) {
                    int cur = vx[xx].fi + vy[yy].fi;
                    if (cur & 1) {
                        odd = min(odd, cur);
                        if (odd == cur) tarOdd = vx[xx].se;
                    }
                    else {
                        even = min(even, cur);
                        if (even == cur) tarEven = vx[xx].se;
                    }
                }
            }
        }
        //debug(odd);
        //debug(even);
        if ((b[i+1] - b[i]) % 2 == 1 && odd <= b[i+1] - b[i]) {
            int cur = a[b[i]], idx = b[i];
            while (cur != tarOdd) {
                idx++;
                if (cur > tarOdd) cur /= 2;
                else cur *= 2;
                ans[idx] = cur;
            }
            cur = a[b[i+1]], idx = b[i+1];
            while (cur != tarOdd) {
                idx--;
                if (cur > tarOdd) cur /= 2;
                else cur *= 2;
                ans[idx] = cur;
            }
        }  
        else if ((b[i+1] - b[i]) % 2 == 0 && even <= b[i+1] - b[i]) {
            int cur = a[b[i]], idx = b[i];
            while (cur != tarEven) {
                idx++;
                if (cur > tarEven) cur /= 2;
                else cur *= 2;
                ans[idx] = cur;
            }
            cur = a[b[i+1]], idx = b[i+1];
            while (cur != tarEven) {
                idx--;
                if (cur > tarEven) cur /= 2;
                else cur *= 2;
                ans[idx] = cur;
            }           
        }  
        else {
            //cout << b[i] << " " << b[i+1] << " : ";
            cout << -1 << endl;
            return;
        }
    }
    REPR(i, b[0] - 1, 0) {
        if (ans[i+1] * 2 >= 1e9) ans[i] = ans[i+1] / 2;
        else ans[i] = ans[i+1] * 2;
    }
    REP(i, b.back() + 1, n-1) {
        if (ans[i-1] * 2 >= 1e9) ans[i] = ans[i-1] / 2;
        else ans[i] = ans[i-1] * 2;
    }
    FOR(i, n-1) {
        bool f = ans[i] == 1;
        while (i < n-1 && ans[i+1] == 0) {
            ans[i+1] = f ? ans[i]*2 : ans[i]/2;
            i++;
            f ^= 1;
        }
    }

    FORR(x, ans) cout << x << " "; cout << endl;
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
