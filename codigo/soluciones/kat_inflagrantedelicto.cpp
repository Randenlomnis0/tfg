#include <bits/stdc++.h>

using namespace std;

int score(const char& c1, const char& c2) {

    if (c1 != c2) return -500000;

    return 1;
}

int lcs(const vector<int>& s1, const vector<int>& s2, const int& n) {

    vector<vector<int>> ans(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; ++i) {

        ans[i][0] = 0;
        ans[0][i] = 0;
    }

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= n; ++j) {

            ans[i][j] = max(ans[i - 1][j - 1] + score(s1[i - 1], s2[j - 1]), max(ans[i - 1][j], ans[i][j - 1]));
        }
    }
    return ans[n][n];
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> p(n), d(n);

    for (int i = 0; i < n; ++i) {

        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {

        cin >> d[i];
    }
    cout << "2 " << lcs(p, d, n) + 1 << "\n";

    cout.flush();

    return EXIT_SUCCESS;
}
