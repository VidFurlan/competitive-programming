#include <bits/stdc++.h>
using namespace std;

int main () {
    int k;
    for (cin >> k; k > 0; k--) {
        int t;
        vector<int> c1, c2, c3;
        int a, x;

        for (cin >> t; t > 0; t--) {
            cin >> a >> x;
            if (a == 1)
                c1.push_back(x);
            else if (a == 2)
                c2.push_back(x);
            else
                c3.push_back(x);
        }

        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        sort(c3.begin(), c3.end());

        int mi = c1[c1.size() - 1], ma = c2[0], nv = 0;
        if (!c3.empty()) {
            for (int i = 0; c3[i] < mi; i++, nv++);
            for (int i = c3.size() - 1; c3[i] > ma; i--, nv++);
        }
        if (ma < mi)
            cout << "0\n";
        else
            cout << ma - mi - (c3.size() - nv) + 1 << '\n';
    }
}
