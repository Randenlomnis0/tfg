#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, aux;
    bool first = true;
    string key, auxs, msg, ans;
    unordered_map<char, pair<int, int>> pos;
    unordered_map<int, char> character;
    vector<string> pairs;

    while (cin >> n, n) {

        if (!first) cout << '\n';
        else first = false;

        getline(cin, key);
        getline(cin, key);

        auxs = key;
        key = "";

        for (auto &it : auxs) {

            if (it == ' ') continue;

            if (toupper(it) == 'J') {

                key += 'I';

                continue;
            }
            key += toupper(it);
        }
        aux = 0;
        pos.clear();
        character.clear();

        for (auto &it : key) {

            if (pos.count(it)) continue;

            pos[it].first = aux / 5;
            pos[it].second = aux % 5;
            character[aux] = it;
            ++aux;
        }

        for (char c = 'A'; c <= 'Z'; ++c) {

            if (pos.count(c) || c == 'J') continue;

            pos[c].first = aux / 5;
            pos[c].second = aux % 5;
            character[aux] = c;
            ++aux;
        }

        while (n--) {

            getline(cin, msg);

            auxs = msg;
            msg = "";

            for (auto &it : auxs) {

                if (it == ' ') continue;

                if (toupper(it) == 'J') {

                    msg += 'I';

                    continue;
                }
                msg += toupper(it);
            }
            aux = 0;
            pairs.clear();

            while (aux < msg.length()) {

                if (aux == msg.length() - 1 || msg[aux] == msg[aux + 1]) {

                    pairs.push_back(string(1, msg[aux]) + "X");
                    ++aux;
                }else {
                    
                    pairs.push_back(msg.substr(aux, 2));
                    aux += 2;
                }

                if (pairs[pairs.size() - 1] == "XX") pairs[pairs.size() - 1] = "YY";
            }
            ans = "";

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
        }
    }
    cout.flush();

    return EXIT_SUCCESS;
}
