#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> cards(N);
    int K;
    cin >> K;
    while (K--) {
        int C1, C2;
        string P1, P2;
        cin >> C1 >> C2 >> P1 >> P2;
        if (P1 == P2) {
            cards[C1] = cards[C2] = " ";
        }else {
            cards[C1] = P1;
            cards[C2] = P2;
        }
    }
    unordered_map<string, int> ft;
    int seen = 0, found = 0;
    for (auto &it : cards) {
        if (it == "") continue;
        ++seen;
        if (it != " ") {
            ++ft[it];
        }else {
            ++found;
        }
    }
    found /= 2;
    int ans = 0, aux = 0;
    for (auto &it : ft) {
        it.second /= 2;
        ans += it.second == 2;
        ans += it.second == 1;
    }
    if (seen == N - 2 && SZ(ft) + found == N / 2 - 1) {
        ans += 1;
    }else if (aux == N - seen) {
        ans += aux;
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
