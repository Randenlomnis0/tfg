#include <bits/stdc++.h>
using namespace std;
struct Line {
    double a, b, c;
    Line(double x1, double y1, double x2, double y2) {
        a = -(double)(y1 - y2) / (x1 - x2);
        b = 1.0;
        c = -(double)(a * x1) - y1;
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        double x1, y1, x2, y2;
        Line line(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2;
        int m;
        cin >> m;
        while (m--) {
            string name;
            int x, y;
            cin >> name >> x >> y;
        }
    }
    cout.flush();
    return 0;
}
