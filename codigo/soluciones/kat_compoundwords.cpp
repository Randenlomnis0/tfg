#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    set<string> words, ans;
    string word;
    while (cin >> word) {
        words.insert(word);
    }
    for (auto &it1 : words) {
        for (auto &it2 : words) {
            if (it1 == it2) continue;
            ans.insert(it1 + it2);
            ans.insert(it2 + it1);
        }
    }
    for (auto &it : ans) {
        cout << it << '\n';
    }
    cout.flush();
    return 0;
}
