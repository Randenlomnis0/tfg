#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    unordered_map<char, string> rules;
    char left;
    string right, aux, S;
    while (n--) {
        cin >> left >> aux >> right;
        rules[left] = right;
    }
    cin >> S;
    while (m--) {
        aux = S;
        S = "";
        for (auto &it : aux) {
            if (!rules.count(it)) {
                S += it;
            }else {
                S += rules[it]; 
            }
        }
    }
    cout << S << '\n';
    cout.flush();
    return 0;
}
