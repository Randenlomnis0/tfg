#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
bool beats(string a, string b) {
    if (a == "rock") return b == "scissors";
    if (a == "paper") return b == "rock";
    return b == "paper";
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    bool first = true;
    while (cin >> n, n) {
        int k;
        cin >> k;
        int games = k * (n * (n - 1)) / 2;
        vector<int> w(n), l(n);
        while (games--) {
            int p1, p2;
            string cmd1, cmd2;
            cin >> p1 >> cmd1 >> p2 >> cmd2;
            --p1;
            --p2;
            if (beats(cmd1, cmd2)) {
                ++w[p1];
                ++l[p2];
            }
            if (beats(cmd2, cmd1)) {
                ++l[p1];
                ++w[p2];
            }
        }
        if (!first) cout << '\n';
        else first = false;
        FOR(i, 0, n) {
            if (w[i] + l[i] == 0) {
                cout << "-\n";
            }else {
                cout << fixed << setprecision(3) << w[i] / (double)(w[i] + l[i]) << '\n';
            }
        }
    }
    cout.flush();
    return 0;
}
