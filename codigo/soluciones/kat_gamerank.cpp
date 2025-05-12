#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
int starts(int lvl) {
    if (lvl > 20) return 2;
    if (lvl > 15) return 3;
    if (lvl > 10) return 4;
    return 5;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int stars = 0, lvl = 25, wstreak = 0;
    for (auto &it : s) {
        if (lvl == 0) break;
        if (it == 'W') {
            ++wstreak;
            if (lvl > 5 && wstreak >= 3) {
                stars += 2;
            }else {
                ++stars;
            }
            if (lvl != 0 && stars > starts(lvl)) {
                stars -= starts(lvl);
                --lvl;
            }
        }else {
            wstreak = 0;
            if (lvl <= 20) {
                stars -= 1;
            }
            if (lvl >= 20) {
                MAX(stars, 0);
            }
            if (stars < 0) {
                ++lvl;
                stars = starts(lvl) - 1;
            }
        }
    }
    if (lvl == 0) {
        cout << "Legend\n";
    }else {
        cout << lvl << '\n';
    }
    cout.flush();
    return 0;
}
