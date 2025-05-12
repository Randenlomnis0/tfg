#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
vector<unordered_map<char, int>> score = {
    {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 2},
        {'T', 10},
        {'9', 0},
        {'8', 0},
        {'7', 0}
    },
    {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 20},
        {'T', 10},
        {'9', 14},
        {'8', 0},
        {'7', 0}
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    char dom;
    cin >> N >> dom;
    int ans = 0;
    FOR(i, 0, 4 * N) {
        char num, suit;
        cin >> num >> suit;
        ans += score[suit == dom][num];
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
