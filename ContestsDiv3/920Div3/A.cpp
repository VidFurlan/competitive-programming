#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        vector<pair<int, int>> corners(4);
        for (int i = 0; i < 4; i++) {
            cin >> corners[i].first >> corners[i].second;
        }
        
        int minX = corners[0].first, maxX = corners[0].first;
        int minY = corners[0].second, maxY = corners[0].second;
    
        for (auto& corner : corners) {
            minX = min(minX, corner.first);
            maxX = max(maxX, corner.first);
            minY = min(minY, corner.second);
            maxY = max(maxY, corner.second);
        }
    
        int side = max(maxX - minX, maxY - minY);
        int area = side * side;
        
        cout << area << endl;
    }
}
