#include <bits/stdc++.h>
using namespace std;
#define MP(a,b) make_pair(a, b)
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
map<char, map<char, char>> afd = {
    {'F', {{'e', 'e'}, {'w', 'w'}, {'n', 'n'}, {'s', 's'}}},
    {'R', {{'e', 's'}, {'w', 'n'}, {'n', 'e'}, {'s', 'w'}}},
    {'L', {{'e', 'n'}, {'w', 's'}, {'n', 'w'}, {'s', 'e'}}},
    {'B', {{'e', 'w'}, {'w', 'e'}, {'n', 's'}, {'s', 'n'}}}
};
void move(const char& instr, char& orientation, int& i, int& j, set<pair<int, int>>& visited) {
    orientation = afd[instr][orientation];
    switch (orientation) {
        case 'e':
            ++j;
            break;
        case 'w':
            --j;
            break;
        case 'n':
            --i;
            break;
        case 's':
            ++i;
            break;
    }
    visited.insert(make_pair(i, j));
}
void solve(const string& s) {
    set<pair<int, int>> visited;
    int i = 0, j = 0, mini = 0, maxi = 0, minj = 0, maxj = 0;
    char orientation = 'e';
    visited.insert(MP(0, 0));
    for (auto &it : s) {
        move(it, orientation, i, j, visited);
        MIN(mini, i);
        MAX(maxi, i);
        MIN(minj, j);
        MAX(maxj, j);
    }
    int h = maxi - mini + 1, w = maxj - minj + 1;
    cout << h + 2 << ' ' << w + 1 << '\n';
    FOR(i, 0, w + 1) {
        cout << '#';
    }
    cout << '\n';
    FOR(i, mini, maxi + 1) {
        for (j = minj; j <= maxj; ++j) {
            cout << (visited.count(MP(i, j)) ? "." : "#");
        }
        cout << "#\n";
    }
    FOR(i, 0, w + 1) {
        cout << '#';
    }
    cout << '\n';
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    cout << t << '\n';
    while (t--) {
        string s; cin >> s;
        solve(s);
    }
    cout.flush();
    return 0;
}
