#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<string> field(n);
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }
        
        vector<int> max_targets(4, 0); // Initialize max_targets for each quadrant
        
        for (int dx = -k; dx <= k; dx++) {
            for (int dy = -k; dy <= k; dy++) {
                if (abs(dx) + abs(dy) <= k) {
                    int targets = 0;
                    
                    // Separate the field into four quadrants based on dx and dy
                    int quad1 = 0, quad2 = 0, quad3 = 0, quad4 = 0;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                            int x = i + dx;
                            int y = j + dy;
                            if (x >= 0 && x < n && y >= 0 && y < m && field[x][y] == '#') {
                                // Just add the checksi if in right-down, left-down, left-up, or right-up quadrant
                                if (dx >= 0 && dy >= 0) {
                                    quad1++;
                                } else if (dx >= 0 && dy < 0) {
                                    quad2++;
                                } else if (dx < 0 && dy >= 0) {
                                    quad3++;
                                } else {
                                    quad4++;
                                }
                            }
                        }
                    }
                    
                    // Update max_targets for each quadrant
                    max_targets[0] = max(max_targets[0], quad1);
                    max_targets[1] = max(max_targets[1], quad2);
                    max_targets[2] = max(max_targets[2], quad3);
                    max_targets[3] = max(max_targets[3], quad4);
                }
            }
        }
        
        // Output the max targets for each quadrant separately
        for (int i = 0; i < 4; i++) {
            cout << max_targets[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
