#include <bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define ALL(c) (c).begin(),(c).end()
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s, token;
    unordered_map<string, int> aft;
    bool first = true;
    while (cin >> n) {
        if (first) first = false;
        else cout << '\n';
        aft.clear();
        while (cin >> s, s != "EndOfText") {
            token = "";
            for (auto &it : s) {
                if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z')) {
                    token += tolower(it);
                }else {
                    if (token != "") {
                        ++aft[token];
                        token = "";
                    }
                }
            }
            if (token != "") {
                ++aft[token];
            }
        }
        vector<string> ans;
        for (auto &it : aft) {
            if (it.second == n) {
                ans.PB(it.first);
            }
        }
        sort(ALL(ans));
        if (ans.empty()) {
            cout << "There is no such word.\n";
        }
        for (auto &it : ans) {
            cout << it << '\n';
        }
    }
    cout.flush();
    return 0;
}
