#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(x) ((int)x.length())
#define PB(x) push_back(x)
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string key, msg, auxs, ans = "";
    vector<string> cypher(5, string(5, '-'));
    unordered_map<char, pair<int, int>> pos;
    unordered_map<int, char> character;
    int aux;
    vector<string> pairs;
    GL(key);
    GL(msg);
    FOR(i, 0, LEN(key)) {
        key[i] = toupper(key[i]);
    }
    FOR(i, 0, LEN(msg)) {
        msg[i] = toupper(msg[i]);
    }
    auxs = key;
    key = "";
    for (auto &it : auxs) {
        if (it == ' ') continue;
        key += it;
    }
    aux = 0;
    for (auto &it : key) {
        if (pos.count(it)) continue;
        pos[it].first = aux / 5;
        pos[it].second = aux % 5;
        character[aux] = it;
        ++aux;
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (pos.count(c) || c == 'Q') continue;
        pos[c].first = aux / 5;
        pos[c].second = aux % 5;
        character[aux] = c;
        ++aux;
    }
    auxs = msg;
    msg = "";
    for (auto &it : auxs) {
        if (it == ' ') continue;
        msg += it;
    }
    aux = 0;
    while (aux < LEN(msg)) {
        if (aux == LEN(msg) - 1 || msg[aux] == msg[aux + 1]) {
            pairs.PB(string(1, msg[aux]) + "X");
            ++aux;
        }else {
            pairs.PB(msg.substr(aux, 2));
            aux += 2;
        }
    }
    for (auto &it : pairs) {
        if (pos[it[0]].first == pos[it[1]].first) {
            ans += string(1, character[pos[it[0]].first * 5 + (pos[it[0]].second + 1)%5]) + string(1, character[pos[it[1]].first * 5 + (pos[it[1]].second + 1)%5]);
        }else if (pos[it[0]].second == pos[it[1]].second) {
            ans += string(1, character[((pos[it[0]].first + 1)%5) * 5 + pos[it[0]].second]) + string(1, character[((pos[it[1]].first + 1)%5) * 5 + pos[it[1]].second]);
        }else {
            ans += string(1, character[pos[it[0]].first * 5 + pos[it[1]].second]) + string(1, character[pos[it[1]].first * 5 + pos[it[0]].second]);
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
