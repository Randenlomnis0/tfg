#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N) {
        vector<int> V(N);
        for (auto &it : V) {
            cin >> it;
        }
        sort(ALL(V));
        priority_queue<int> pilas;
        pilas.push(0);
        for (auto &it : V) {
            int altura = -pilas.top();
            if (altura > it) {
                pilas.push(0);
                altura = 0;
            }
            pilas.pop();
            pilas.push(-(altura + 1));
        }
        cout << pilas.size() << '\n';
    }
    cout.flush();
    return 0;
}
