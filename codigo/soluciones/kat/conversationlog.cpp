#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define LEN(s) ((int)(s).length())
#define SZ(c) ((int)(c).size())
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    cin >> M;
    unordered_set<string> users;
    unordered_map<string, unordered_set<string>> users_per_word;
    unordered_map<string, int> ft;
    while (M--) {
        string uname, line;
        cin >> uname;
        users.insert(uname);
        GL(line);
        int i = 1, j = 1;
        while (i < LEN(line)) {
            while (j < LEN(line) && line[j] != ' ') ++j;
            string aux = line.substr(i, j - i);
            i = j + 1;
            j = i;
            users_per_word[aux].insert(uname);
            ++ft[aux];
        }
    }
    set<pair<int, string>> ans;
    for (auto &it : users_per_word) {
        if (SZ(it.second) < SZ(users)) continue;
        ans.insert(mp(-ft[it.first], it.first));
    }
    for (auto &it : ans) {
        cout << it.second << '\n';
    }
    if (ans.empty()) {
        cout << "ALL CLEAR\n";
    }
    cout.flush();
    return 0;
}
