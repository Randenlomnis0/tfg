#include <bits/stdc++.h>

using namespace std;

bool checkCompatible(const string& s1, const string& s2) {

    unordered_map<char, char> equiv1, equiv2;
    int n;

    if (s1.length() != s2.length()) return false;

    n = s1.length();

    for (int i = 0; i < n; ++i) {

        if (!equiv1.count(s1[i]) && !equiv2.count(s2[i])) {

            equiv1[s1[i]] = s2[i];
            equiv2[s2[i]] = s1[i];
        }else if (!(equiv1.count(s1[i]) && equiv2.count(s2[i]) && equiv1[s1[i]] == s2[i])) {

            return false;
        }
    }
    return true;
}

string solve() {

    int n; cin >> n;
    vector<string> M(n);
    string D, X, key = "", ans = "";
    vector<bool> compatible(n);
    unordered_map<char, char> decrypt;

    for (int i = 0; i < n; ++i) {

        cin >> M[i];
    }
    cin >> D >> X;

    for (int i = 0; i < n; ++i) {

        compatible[i] = checkCompatible(M[i], D);

        if (!compatible[i]) continue;

        if (key == "") {

            key = M[i];

            for (int j = 0; j < key.length(); ++j) {

                decrypt[key[j]] = D[j];
            }
        }else {
            
            for (int j = 0; j < key.length(); ++j) {

                if (key[j] == M[i][j]) continue;

                decrypt[key[j]] = '?';
            }
        }
    }
    
    if (key == "") return "IMPOSSIBLE";

    for (auto &it : X) {

        if (!decrypt.count(it)) {

            ans += '?';
        }else {

            ans += decrypt[it];
        }
    }
    return ans;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;

    while (t--) {

        cout << solve() << '\n';
    }
    cout.flush();

    return EXIT_SUCCESS;
}
