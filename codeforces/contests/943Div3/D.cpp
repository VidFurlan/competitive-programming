#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

const ll MOD = 1e9 + 7;

void solve() {
    ll n, k, pB, pS;
    cin >> n >> k >> pB >> pS;
    vector<ll> p(n), a(n);
    for (ll &i : p) cin >> i;
    for (ll &i : a) cin >> i;
    unsigned ll maxB = k * a[pB - 1], maxS = k * a[pS - 1];
    vector<bool> vB(n), vS(n);

    ll b = pB, s = pS;
    ll curB = 0, curS = 0;
    for (ll i = 0; i < k; i++) {
        if (vB[b - 1] == 1)
            break;
        maxB = max(maxB, (unsigned ll)(curB + (k - i) * a[b - 1]));
        curB += a[b - 1];
        vB[b - 1] = 1;
        b = p[b - 1];
    }

    for (ll i = 0; i < k; i++) {
        if (vS[s - 1] == 1)
            break;
        maxS = max(maxS, (unsigned ll)(curS + (k - i) * a[s - 1]));
        curS += a[s - 1];
        vS[s - 1] = 1;
        s = p[s - 1];
    }

    //cout << maxB << " " << maxS << endl;
    if (maxB > maxS)
        cout << "Bodya\n";
    else if (maxB < maxS)
        cout << "Sasha\n";
    else 
        cout << "Draw\n";
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
