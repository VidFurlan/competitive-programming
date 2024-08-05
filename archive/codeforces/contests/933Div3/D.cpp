#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        unordered_set<int> cur, next;
        cur.insert(x);

        for (int i = 0; i < m; i++) {
            int dist;
            char move;
            cin >> dist >> move;

            switch (move) {
                case '0':
                    for (int p : cur) 
                        next.insert((p + dist > n) ? - n + p + dist : p + dist);
                break;
                case '1':
                    for (int p : cur)
                        next.insert((p - dist <= 0) ? n + (p - dist) : p - dist);
                break;
                default:
                    for (int p : cur) {
                        next.insert((p + dist > n) ? - n + p + dist : p + dist);
                        next.insert((p - dist <= 0) ? n + (p - dist) : p - dist);
                    }
                break;
            }
        
            cur = next;
            next.clear();
        }

        vector<int> ans(cur.begin(), cur.end());
        sort(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for (int p : ans) 
            cout << p << " ";
        cout << endl;
    }
}
