#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

int n; 

void calcPos(vector<ll>& pos, vector<ll>& sum, ll mn) {
    for (int i = 0, j = 0; i <= n; i++) {
        while (j <= n && sum[j] - sum[i] < mn) 
            j++;

        if (j <= n)
            pos[i] = j;
        else 
            break;
    }
}

void solve() {
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    ll sum = 0;
    FORR(i, a) { cin >> i; sum += i; }
    FORR(i, b) cin >> i; 
    FORR(i, c) cin >> i; 
    
    vector<ll> asum(n + 1), bsum(n + 1), csum(n + 1);
    for (int i = 1; i <= n; i++) {
        asum[i] = asum[i - 1] + a[i - 1];
        bsum[i] = bsum[i - 1] + b[i - 1];
        csum[i] = csum[i - 1] + c[i - 1];
    }

    // FORR(i, asum) cout << i << " ";
    // cout << endl;
    // FORR(i, bsum) cout << i << " ";
    // cout << endl;
    // FORR(i, csum) cout << i << " ";
    // cout << endl;

    ll mn = ceill(sum / 3.0);
    vector<ll> apos(n + 1, -1), bpos(n + 1, -1), cpos(n + 1, -1);
    calcPos(apos, asum, mn);
    calcPos(bpos, bsum, mn);
    calcPos(cpos, csum, mn);

    // cout << endl;
    // FORR(i, apos) cout << i << " "; 
    // cout << endl;
    // FORR(i, bpos) cout << i << " ";
    // cout << endl;
    // FORR(i, cpos) cout << i << " ";
    // cout << endl;

    ll astart = 0, aend = 0, bstart = 0, bend = 0, cstart = 0, cend = 0;
    if (apos[0] != -1 && bpos[apos[0]] != -1 && cpos[bpos[apos[0]]] != -1) {
        astart = 1; aend = apos[0];
        bstart = apos[0] + 1; bend = bpos[apos[0]];
        cstart = bpos[apos[0]] + 1; cend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else if (apos[0] != -1 && cpos[apos[0]] != -1 && bpos[cpos[apos[0]]] != -1) {
        astart = 1; aend = apos[0];
        cstart = apos[0] + 1; cend = cpos[apos[0]];
        bstart = cpos[apos[0]] + 1; bend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else if (bpos[0] != -1 && apos[bpos[0]] != -1 && cpos[apos[bpos[0]]] != -1) {
        bstart = 1; bend = bpos[0];
        astart = bpos[0] + 1; aend = apos[bpos[0]];
        cstart = apos[bpos[0]] + 1; cend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else if (bpos[0] != -1 && cpos[bpos[0]] != -1 && apos[cpos[bpos[0]]] != -1) { 
        bstart = 1; bend = bpos[0];
        cstart = bpos[0] + 1; cend = cpos[bpos[0]];
        astart = cpos[bpos[0]] + 1; aend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else if (cpos[0] != -1 && apos[cpos[0]] != -1 && bpos[apos[cpos[0]]] != -1) {
        cstart = 1; cend = cpos[0];
        astart = cpos[0] + 1; aend = apos[cpos[0]];
        bstart = apos[cpos[0]] + 1; bend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else if (cpos[0] != -1 && bpos[cpos[0]] != -1 && apos[bpos[cpos[0]]] != -1) {
        cstart = 1; cend = cpos[0];
        bstart = cpos[0] + 1; bend = bpos[cpos[0]];
        astart = bpos[cpos[0]] + 1; aend = n;
        cout << astart << " " << aend << " " << bstart << " " << bend << " " << cstart << " " << cend << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; cin >> t;

    while (t--) {
        solve();
        // cout << "====================\n";
    }

    return 0;
}
