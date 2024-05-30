#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>
#define pbb pair<int, int>

#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int p, t; cin >> p >> t;
    const int n = p + t + 1;
    vector<int> a(n), b(n);
    FORR(i, a) cin >> i;
    FORR(i, b) cin >> i;

    vector<pbb> ans(n);
    ll psum = 0, tsum = 0;
    int pcnt = 0, tcnt = 0;
    FOR(i, n)
        if (a[i] == max(a[i], b[i]) && pcnt <= p) {
            pcnt++;
            psum += a[i];
            ans[i].first = 1;
        } 
        else if (b[i] == max(a[i], b[i]) && tcnt < t) {
            tcnt++;
            psum += b[i];
            ans[i].first = 0;
        } 
        else if (pcnt <= p) {
            pcnt++;
            psum += a[i];
            ans[i].first = 1;
        } 
        else {
            tcnt++;
            psum += b[i];
            ans[i].first = 0;
        }

    pcnt = 0, tcnt = 0;
    FOR(i, n)
        if (b[i] == max(a[i], b[i]) && tcnt <= t) {
            tcnt++;
            tsum += b[i];
            ans[i].second = 0;
        } 
        else if (a[i] == max(a[i], b[i]) && pcnt < p) {
            pcnt++;
            tsum += a[i];
            ans[i].second = 1;
        } 
        else if (tcnt <= t) {
            tcnt++;
            tsum += b[i];
            ans[i].second = 0;
        } 
        else {
            pcnt++;
            tsum += a[i];
            ans[i].second = 1;
        }

    FOR(i, n)
        if (ans[i].first == 1)
            cout << psum - a[i] << " ";
        else if (ans[i].second == 0)
            cout << tsum - b[i] << " ";
        else
            cout << "0 ";
    cout << endl;
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
