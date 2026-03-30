#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<long long, int> mp;
            int duplicate = 1;
            int maxi = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize slope
                if (dy < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dy == 0) {
                    dx = 1;
                }
                if (dx == 0) {
                    dy = 1;
                }

                long long key = ((long long)dx << 32) | (unsigned int)dy;

                mp[key]++;
                maxi = max(maxi, mp[key]);
            }

            ans = max(ans, maxi + duplicate);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter points (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    Solution obj;
    int result = obj.maxPoints(points);

    cout << "Maximum Points on Same Line: " << result << endl;

    return 0;
}