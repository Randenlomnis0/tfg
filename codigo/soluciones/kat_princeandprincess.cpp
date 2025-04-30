#include <bits/stdc++.h>

using namespace std;

int score(const int& a, const int& b) {

    if (a == b) return 1;

    return -1000;
}

int solve() {

    int n, p, q; cin >> n >> p >> q;
    vector<int> P(p), Q(q), ans(q + 1), prev(q + 1);

    cin >> P[0];

    for (int i = 0; i < p; ++i) {

        cin >> P[i];
    }
    cin >> Q[0];

    for (int i = 0; i < q; ++i) {

        cin >> Q[i];
    }

    for (int i = 0; i <= q; ++i) {

        ans[i] = 0;
    }
    
    for (int i = 1; i <= p; ++i) {

        for (int j = 1; j <= q; ++j) {

            prev[j] = ans[j];
            ans[j] = max(prev[j - 1] + score(P[i - 1], Q[j - 1]), max(prev[j], ans[j - 1]));
        }
    }
    return ans[q] + 1;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    for (int i = 0; i < t; ++i) {

        cout << "Case " << i + 1 << ": " << solve() << "\n";
    }
    cout.flush();

    return EXIT_SUCCESS;
}
