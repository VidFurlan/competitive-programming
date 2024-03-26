#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, ans, sum = 0;
        cin >> n;
        vector<int> nums (3);

        while (n--) {
            int num;
            cin >> num;
            nums[num%3]++;
            sum += num;
        }

        int num1 = nums[1] - (nums[1] / 3) * 3;
        int num2 = nums[2] - (nums[2] / 3) * 3;
        ans = abs(num1 - num2);
        
        if (sum % 3 == 1) { 
            if (nums[1] >= 1)
                cout << 1 << endl;
            else 
                cout << 2 << endl;
        }
        else if (sum % 3 == 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
