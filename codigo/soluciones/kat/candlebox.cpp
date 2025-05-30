#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool isvalid(const int &b, const int &x) {
    int lb = 0, hb = x;
    while (lb != hb - 1) {
        int nb = (lb + hb + 1) / 2;
        if (nb * (nb + 1) / 2 - b * (b + 1) / 2 >= x) {
            hb = nb;
        }else {
            lb = nb;
        }
    }
    return hb * (hb + 1) / 2 - b * (b + 1) / 2 == x;
}
int age(const int &b, const int &x) {
    int lb = 0, hb = x;
    while (lb != hb - 1) {
        int nb = (lb + hb + 1) / 2;
        if (nb * (nb + 1) / 2 - b * (b + 1) / 2 >= x) {
            hb = nb;
        }else {
            lb = nb;
        }
    }
    return hb;
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int D, R, T;
    cin >> D >> R >> T;
    FOR(i, 0, R) {
        if (isvalid(3, R - i) && isvalid(2, T + i) && abs(age(3, R - i) - age(2, T + i)) == D) {
            cout << i << '\n';
            break;
        }
    }
    cout.flush();
    return 0;
}
