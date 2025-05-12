#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    unordered_map<string, pair<int, int>> info;
    map<pair<int, int>, string> q;
    int aux = 0;
    while (N--) {
        ++aux;
        int cmd;
        cin >> cmd;
        if (cmd == 0) {
            string name;
            int infection;
            cin >> name >> infection;
            info[name] = mp(-infection, aux);
            q[info[name]] = name;
        }else if (cmd == 1) {
            string name;
            int increaseInfection;
            cin >> name >> increaseInfection;
            q.erase(info[name]);
            info[name].first -= increaseInfection;
            q[info[name]] = name;
        }else if (cmd == 2) {
            string name;
            cin >> name;
            q.erase(info[name]);
            info.erase(name);
        }else {
            if (!q.empty()) {
                cout << q.begin()->second << '\n';
            }else {
                cout << "The clinic is empty\n";
            }
        }
    }
    cout.flush();
    return 0;
}
