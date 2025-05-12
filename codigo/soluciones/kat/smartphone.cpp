#include <bits/stdc++.h>
using namespace std;
#define LEN(x) ((int)x.length())
int solve(const string& start, const string& goal) {
    int i = 0, n = LEN(start), m = LEN(goal);
    while (i < n && i < m && start[i] == goal[i]) {
        ++i;
    }
    return n - i + m - i;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    string goal, start, s1, s2, s3;
    while (t--) {
        cin >> goal >> start >> s1 >> s2 >> s3;
        cout << min(solve(start, goal), min(1 + solve(s1, goal), min(1 + solve(s2, goal), 1 + solve(s3, goal)))) << '\n';
    }
    cout.flush();
    return 0;
}
