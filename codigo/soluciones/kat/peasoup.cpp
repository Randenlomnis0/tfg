#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string ans = "";
    while (n--) {
        int k;
        cin >> k;
        string name;
        GL(name);
        GL(name);
        bool peasoup = false, pancakes = false;
        while (k--) {
            string item;
            GL(item);
            if (item == "pea soup") {
                peasoup = true;
            }
            if (item == "pancakes") {
                pancakes = true;
            }
        }
        if (ans != "") continue;
        if (peasoup && pancakes) {
            ans = name;
        }
    }
    cout << (ans != "" ? ans : "Anywhere is fine I guess") << '\n';
    cout.flush();
    return 0;
}
