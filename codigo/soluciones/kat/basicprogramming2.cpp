#include <bits/stdc++.h>
using namespace std;
#define ALL(c) (c).begin(), (c).end()
#define SZ(c) ((int)(c).size())
#define ll long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, t;
    cin >> N >> t;
    vector<ll> A(N);
    for (auto &it : A) {
        cin >> it;
    }
    if (t == 1) {
        bool found = false;
        sort(ALL(A));
        for (auto &it1 : A) {
            if (!binary_search(ALL(A), 7777 - it1)) continue;
            found = true;
        }
        cout << (found ? "Yes" : "No") << '\n';
    }else if (t == 2) {
        unordered_set<int> uniq;
        for (auto &it : A) {
            uniq.insert(it);
        }
        cout << (SZ(uniq) != N ? "Contains duplicate" : "Unique") << '\n';
    }else if (t == 3) {
        unordered_map<int, int> ft;
        int ans = -1;
        for (auto &it : A) {
            ++ft[it];
            if (ft[it] <= N / 2) continue;
            ans = it;
        }
        cout << ans << '\n';
    }else if (t == 4) {
        sort(ALL(A));
        if (N%2 == 0) {
            cout << A[(N - 1) / 2] << ' ';
        }
        cout << A[N / 2] << '\n';
    }else {
        priority_queue<int, vector<int>, greater<int>> selected;
        for (auto &it : A) {
            if (it < 100 || it > 999) continue;
            selected.push(it);
        }
        bool first = true;
        while (!selected.empty()) {
            if (!first) cout << ' ';
            else first = false;
            cout << selected.top();
            selected.pop();
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
