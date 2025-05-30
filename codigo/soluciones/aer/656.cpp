#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(), (c).end()
#define LEN(s) ((int)(s).length())
#define SZ(c) ((int)(c).size())
#define pb(x) push_back(x)
unordered_map<char, int> ctoid = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'-', 4}};
struct Nodo {
    int hijos[5];
    unordered_multiset<int> ans;
    Nodo() { fill(hijos, hijos + 5, -1); };
};
void solve(const vector<Nodo> &trie, const int &id, const string &cadena, const int &j, vector<int> &ans, const int &i) {
    ans[i] += SZ(trie[id].ans);
    for (auto &it : trie[id].ans) {
        ++ans[it];
    }
    if (j == LEN(cadena)) return;
    if (cadena[j] == '-') {
        FOR(k, 0, 5) {
            if (trie[id].hijos[k] == -1) continue;
            solve(trie, trie[id].hijos[k], cadena, j + 1, ans, i);
        }
    }else {
        if (trie[id].hijos[ctoid['-']] != -1) {
            solve(trie, trie[id].hijos[ctoid['-']], cadena, j + 1, ans, i);
        }
        if (trie[id].hijos[ctoid[cadena[j]]] != -1) {
            solve(trie, trie[id].hijos[ctoid[cadena[j]]], cadena, j + 1, ans, i);
        }
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N) {
        vector<string> cadenas(N);
        unordered_map<string, int> long_prefijo(N);
        FOR(i, 0, N) {
            cin >> cadenas[i];
            for (auto &c : cadenas[i]) {
                if (c != '-') break;
                ++long_prefijo[cadenas[i]];
            }
        }
        sort(ALL(cadenas), [&long_prefijo](const string &a, const string &b) {
            return long_prefijo[a] < long_prefijo[b];
        });
        for (auto &it : cadenas) {
            cout << it << '\n';
        }
        vector<Nodo> trie(1);
        vector<vector<int>> nodes_of_level(51);
        nodes_of_level[0].pb(0);
        vector<int> ans(N);
        FOR(i, 0, N) {
            for (auto &it : nodes_of_level[long_prefijo[cadenas[i]]%LEN(cadenas[i])]) {
                solve(trie, it, cadenas[i], long_prefijo[cadenas[i]], ans, i);
            }
            int k = LEN(cadenas[i]) - 1;
            while (k >= 0 && cadenas[i][k] == '-') {
                --k;
            }
            int aux = 0;
            FOR(j, 0, k + 1) {
                if (trie[aux].hijos[ctoid[cadenas[i][j]]] == -1) {
                    trie[aux].hijos[ctoid[cadenas[i][j]]] = SZ(trie);
                    nodes_of_level[j + 1].pb(SZ(trie));
                    trie.emplace_back();
                }
                aux = trie[aux].hijos[ctoid[cadenas[i][j]]];
            }
            trie[aux].ans.insert(i);
        }
        bool first = true;
        for (auto &it : ans) {
            if (!first) cout << ' ';
            else first = false;
            cout << it;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
