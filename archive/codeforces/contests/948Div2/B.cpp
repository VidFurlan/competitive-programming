#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())

const ll MOD = 1e9 + 7;

void solve() {
    int x; cin >> x;
    vector<int> a(32);
    
    for (int i = 0; i < 32; i++)
        a[i] = (x >> i) & 1;

    int f = 1;
    while (f) {
        f = 0;
        for (int i = 30; i > 0; i--) {
            if (a[i] == 1 && a[i - 1] == 1) {
                a[i] = 0;
                a[i + 1] = 1;
                a[i - 1] = -1;
                //cout << "1 -> ";
                break;
            }
            else if (a[i] == -1 && a[i - 1] == 1) {
                a[i] = 0;
                a[i - 1] = -1;
                //cout << "2 -> ";
                break;
            }
            else if (a[i] == 1 && a[i - 1] == -1) {
                a[i] = 0;
                a[i - 1] = 1;
                //cout << "3 -> ";
                break;
            }
        }

        for (int i = 31; i > 0; i--)
             if (a[i] != 0 && a[i - 1] != 0) {
                 f = 1;
                 break;
             }

       // FORR(i, a)
       //     cout << i << " ";
       // cout << endl;
    }

    cout << 32 << endl;
    FORR(i, a)
        cout << i << " ";
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
