#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define pb(x) push_back(x)
#define LEN(s) ((int)(s).length())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string cmd;
        cin >> cmd;
        int n;
        cin >> n;
        string line;
        vector<int> nums;
        GL(line);
        GL(line);
        int d = 0;
        for (auto &it : cmd) {
            d += (it == 'D');
        }
        if (d > n) {
            cout << "error\n";
            continue;
        }
        int i = 1, j = 1;
        while (i < LEN(line) - 1) {
            while (line[j] != ']' && line[j] != ',') ++j;
            nums.pb(stoi(line.substr(i, j - i)));
            i = j + 1;
            j = i;
        }
        int dir = 1;
        i = 0;
        j = n - 1;
        for (auto &it : cmd) {
            if (it == 'R') {
                dir *= -1;
                continue;
            }
            if (dir == 1) {
                ++i;
            }else {
                --j;
            }
        }
        bool first = true;
        cout << '[';
        if (dir == 1) {
            FOR(k, i, j + 1) {
                if (!first) cout << ',';
                else first = false;
                cout << nums[k];
            }
        }else {
            RFOR(k, j + 1, i) {
                if (!first) cout << ',';
                else first = false;
                cout << nums[k];
            }
        }
        cout << ']' << '\n';
    }
    cout.flush();
    return 0;
}
