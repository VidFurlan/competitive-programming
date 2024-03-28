#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
void solve() {
    int w, h;
    cin >> w >> h;
    
    vector<ii> g = {
        {1, 1},
        {w, 1},
        {w, h}
    };
    vector<int> d(4);

    for (int i = 0; i < 3; i++) {
        cout << "? " << g[i].first << " " << g[i].second << endl;
        cin >> d[i];
        cout.flush();
    }

    float x1 = (d[0] + w - d[1] - 1) / 2.0 + 1, x2 = w + (h - d[2] - d[1] + 1) / 2.0 - 1;
    float y1 = d[0] - x1, y2 = w + h - d[2] - x2;
    //cout << x1 << ", " << y1 << endl;
    //cout << x2 << ", " << y2 << endl;

    if (x1 == (int)x1 && x2 == (int)x2) {
        int v1;
        if (x1 <= w && x1 >= 1 && y1 <= h && y1 >= 1)
            cout << "? " << x1 << " " << y1 << endl;
        else 
            cout << "? " << x2 << " " << y2 << endl;
        cout.flush();
        cin >> v1;

        if (v1 == 0 && (x1 <= w && x1 >= 1 && y1 <= h && y1 >= 1))
            cout << "! " << x1 << " " << y1 << endl;
        else 
            cout << "! " << x2 << " " << y2 << endl;
    }
    else {
        if (x1 == (int)x1)
            cout << "! " << x1 << " " << y1 << endl;
        else 
            cout << "! " << x2 << " " << y2 << endl;
    }

    cout.flush();
}

int main() {
    int t; cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
