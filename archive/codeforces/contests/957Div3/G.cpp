#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string river;
        cin >> river;

        vector<bool> visited(n + 2, false);
        queue<pair<int, int>> q; // (position, swim_distance)

        // Starting point at position 0 with 0 swim distance
        q.push({0, 0});
        visited[0] = true;

        bool canReach = false;

        while (!canReach && !q.empty()) {
            auto [pos, swim] = q.front();
            q.pop();

            // Try jumping from the current position
            if (pos == 0 || river[pos - 1] == 'L') {
                for (int jump = 1; jump <= m; ++jump) {
                    int newPos = pos + jump;
                    if (newPos == n + 1) {
                        canReach = true;
                        cout << "1";
                        break;
                    }
                    if (newPos <= n && river[newPos - 1] != 'C' && !visited[newPos]) {
                        visited[newPos] = true;
                        q.push({newPos, swim});
                    }
                }
            }

            // Try swimming to the next position if currently in water
            if (pos > 0 && pos <= n && river[pos - 1] == 'W' && swim < k) {
                int newPos = pos + 1;
                if (newPos == n + 1) {
                    canReach = true;
                    break;
                }
                if (newPos <= n && river[newPos - 1] != 'C' && !visited[newPos]) {
                    visited[newPos] = true;
                    q.push({newPos, swim + 1});
                }
            }
        }

        cout << (canReach ? "YES" : "NO") << endl;
    }
    
    return 0;
}
