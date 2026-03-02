#include <bits/stdc++.h>
using namespace std;
struct Point {
    double x, y;
    bool operator==(const Point& t) const {
        return x == t.x && y == t.y;
    }
};
int orientation(Point a, Point b, Point c) {
    double v = a.x * (b.y - c.y) + 
               b.x * (c.y - a.y) + 
               c.x * (a.y - b.y);
    if (v < 0) return -1; 
    if (v > 0) return +1; 
    return 0;
}
double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + 
           (a.y - b.y) * (a.y - b.y);
}
vector<vector<int>> findConvexHull(vector<vector<int>> points) {
    int n = points.size();
    if (n < 3) return {{-1}};
    vector<Point> a;
    for (auto& p : points) {
        a.push_back({(double)p[0], (double)p[1]});
    }
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const Point& a, const Point& b) {
        int o = orientation(p0, a, b);
        if (o == 0) {
            return distSq(p0, a) < distSq(p0, b);
        }
        return o < 0;
    });
    vector<Point> st;
    for (int i = 0; i < (int)a.size(); ++i) {
        while (st.size() > 1 && orientation(st[st.size() - 2], st.back(), a[i]) >= 0)
            st.pop_back();

        st.push_back(a[i]);
    }
    if (st.size() < 3) return {{-1}};
    vector<vector<int>> result;
    for (auto& p : st) {
        result.push_back({(int)p.x, (int)p.y});
    }
    return result;
}
int main() {
    vector<vector<int>> points = {
        {0, 0}, {1, -4}, {-1, -5}, {-5, -3}, {-3, -1},
        {-1, -3}, {-2, -2}, {-1, -1}, {-2, -1}, {-1, 1}
    };
    vector<vector<int>> hull = findConvexHull(points);
    if(hull.size() == 1 && hull[0].size() == 1){
        cout << hull[0][0] << " ";
    }
    else {
        for (auto& point : hull) {
            cout << point[0] << ", " << point[1] << "\n";
        }
    }
    return 0;
}
