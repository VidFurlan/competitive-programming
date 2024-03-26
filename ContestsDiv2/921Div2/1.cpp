#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string s, seg;

        for (int i = 0; i < k; i++)
            seg += ('a' + i);
        for (int i = 0; i < n; i++)
            s += seg;
        cout << s << '\n';
    }
}
