#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9 + 7

#define ll long long
#define pll pair<long, long>
#define pii pair<int, int>

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;

    if (xa >= xb) {
        cout << "Draw\n";
        return;
    }

	int a_moves = (xb - xa + 1) / 2;
	int b_moves = (xb - xa) / 2;

	if ((ya < yb) == (xb - xa) % 2) {
		ya = w + 1 - ya;
		yb = w + 1 - yb;
	}

	ya = max(1, ya - a_moves);
	yb = max(1, yb - b_moves);

	if ((xb - xa) % 2) {
        if (ya <= yb)
            cout << "Alice\n";
        else 
            cout << "Draw\n";
	} 
    else {
        if (yb <= ya)
            cout << "Bob\n";
        else 
            cout << "Draw\n";
	}
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
