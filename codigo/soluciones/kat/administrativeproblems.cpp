#include <bits/stdc++.h>
using namespace std;
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        unordered_set<string> driven;
        unordered_map<string, int> catalog_price;
        unordered_map<string, int> pickup_price;
        unordered_map<string, int> cost_per_km;
        unordered_map<string, string> driving;
        map<string, int> cost;
        unordered_set<string> inconsistent;
        while (n--) {
            string N;
            int p, q, k;
            cin >> N >> p >> q >> k;
            catalog_price[N] = p;
            pickup_price[N] = q;
            cost_per_km[N] = k;
        }
        while (m--) {
            int t;
            string S;
            char e;
            cin >> t >> S >> e;
            if (!cost.count(S)) {
                cost[S] = 0;
            }
            if (e == 'p') {
                string C;
                cin >> C;
                if (driving.count(S) || driven.count(C)) {
                    inconsistent.insert(S);
                }else {
                    driven.insert(C);
                    driving[S] = C;
                    cost[S] += pickup_price[C];
                }
            }else if (e == 'r') {
                int d;
                cin >> d;
                if (!driving.count(S)) {
                    inconsistent.insert(S);
                }else {
                    driven.erase(driving[S]);
                    cost[S] += cost_per_km[driving[S]] * d;
                    driving.erase(S);
                }
            }else {
                int s;
                cin >> s;
                if (!driving.count(S)) {
                    inconsistent.insert(S);
                }else {
                    cost[S] += ceil(s * (catalog_price[driving[S]] / 100.0));
                }
            }
        }
        for (auto &it : driving) {
            inconsistent.insert(it.first);
        }
        for (auto &it : cost) {
            cout << it.first << ' ';
            if (inconsistent.count(it.first)) {
                cout << "INCONSISTENT\n";
            }else {
                cout << it.second << '\n';
            }
        }
    }
    cout.flush();
    return 0;
}
