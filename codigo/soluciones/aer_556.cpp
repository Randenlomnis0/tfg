#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define RFOR(i,j,k) for (int i = j - 1; i >= k; --i)
#define MP(a,b) make_pair(a, b)
#define ALL(c) (c).begin(),(c).end()
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N;
    while (cin >> M, M) {
        cin >> N;
        vector<int> V(N);
        FOR(i, 0, N) {
            cin >> V[i];
        }
        sort(ALL(V));
        vector<pair<int, int>> subsets((1<<N));
        RFOR(mask, (1<<N), 0) {
            int poder = 0;
            FOR(i, 0, N) {
                if ((mask & (1<<i)) == 0) continue;
                poder += V[i];
            }
            subsets[mask] = MP(poder, mask);
        }
        sort(ALL(subsets), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });
        RFOR(i, (1<<N), 0) {
            priority_queue<int> combos;
            FOR(j, 0, N) {
                if ((subsets[i].second & (1<<j)) == 0) continue;
                combos.push(-V[j]);
            }
            int coste = 0;
            if (SZ(combos) == 1) {
                coste = -combos.top();
            }
            while (SZ(combos) > 1 && coste <= M) {
                int a = -combos.top();
                combos.pop();
                int b = -combos.top();
                combos.pop();
                coste += a + b;
                combos.push(-(a + b));
            }
            if (coste <= M) {
                cout << subsets[i].first << '\n';
                break;
            }
        }
    }
    cout.flush();
    return 0;
}
