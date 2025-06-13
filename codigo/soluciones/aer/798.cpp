#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N, N) {
        queue<int> goal, src;
        FOR(i, 0, N) {
            int aux;
            cin >> aux;
            goal.push(aux);
            src.push(i + 1);
        }
        stack<int> estacion;
        while (!src.empty()) {
            estacion.push(src.front());
            src.pop();
            while (!estacion.empty() && estacion.top() == goal.front()) {
                estacion.pop();
                goal.pop();
            }
        }
        cout << (estacion.empty() ? "SI" : "NO") << '\n';
    }
    cout.flush();
    return 0;
}
