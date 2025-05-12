#include <bits/stdc++.h>
using namespace std;
#define LEN(s) ((int)(s).length())
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,j,k) for (int i = j; i < k; ++i)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<string, string>> ans(n);
        FOR(i, 0, n) {
            string name, cls, extra;
            cin >> name >> cls >> extra;
            name = name.substr(0, LEN(name) - 1);
            string compactCls = "";
            while (cls.find('-') != string::npos) {
                string aux = cls.substr(0, cls.find('-'));
                if (aux == "upper") {
                    compactCls += 'a';
                }else if (aux == "middle") {
                    compactCls += 'b';
                }else {
                    compactCls += 'c';
                }
                cls = cls.substr(cls.find('-') + 1);
            }
            if (cls == "upper") {
                compactCls += 'a';
            }else if (cls == "middle") {
                compactCls += 'b';
            }else {
                compactCls += 'c';
            }
            int j = 0;
            while (j < LEN(compactCls) && compactCls[j] == 'b') {
                ++j;
            }
            compactCls = compactCls.substr(j);
            reverse(ALL(compactCls));
            compactCls += "bbbbbbbbbb";
            ans[i].first = compactCls;
            ans[i].second = name;
        }
        sort(ALL(ans));
        for (auto &it : ans) {
            cout << it.second << '\n';
        }
        cout << "==============================\n";
    }
    cout.flush();
    return 0;
}
