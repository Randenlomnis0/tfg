#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a, b)
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> languages(n);
    for (auto &it : languages) {
        cin >> it;
    }
    unordered_map<string, set<pair<string, int>>> AL;
    while (m--) {
        string l1, l2;
        int c;
        cin >> l1 >> l2 >> c;
        AL[l1].insert(mp(l2, c));
        AL[l2].insert(mp(l1, c));
    }
    queue<string> q;
    q.push("English");
    unordered_map<string, int> dist, c;
    unordered_map<string, string> p;
    while (!q.empty()) {
        string language = q.front();
        q.pop();
        for (auto &it : AL[language]) {
            if (!dist.count(it.first)) {
                dist[it.first] = dist[language] + 1;
                p[it.first] = language;
                c[it.first] = lower_bound(ALL(AL[language]), mp(it.first, 0))->second;
                q.push(it.first);
            }else if (dist[it.first] == dist[language] + 1 && lower_bound(ALL(AL[language]), mp(it.first, 0))->second < c[it.first]) {
                p[it.first] = language;
                c[it.first] = lower_bound(ALL(AL[language]), mp(it.first, 0))->second;
            }   
        }
    }
    if (SZ(c) == n) {
        int ans = 0;
        for (auto &it : c) {
            ans += it.second;
        }
        cout << ans << '\n';
    }else {
        cout << "Impossible\n";
    }
    cout.flush();
    return 0;
}
