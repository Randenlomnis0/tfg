#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define mp make_pair
#define SZ(c) ((int)(c).size())
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int cnt = 0;
};
class Trie {
private:
    TrieNode *root;
    int dfs(TrieNode* node, const string &s, int i) {
        if (i >= LEN(s)) return node->cnt;
        int ans = node->cnt;
        if (s[i] == '-') {
            for (auto &it : node->children) {
                ans += dfs(it.second, s, i + 1);
            }
        }else {
            if (node->children.count(s[i])) {
                ans += dfs(node->children[s[i]], s, i + 1);
            }
            if (node->children.count('-')) {
                ans += dfs(node->children['-'], s, i + 1);
            }
        }
        return ans;
    }
public:
    Trie() {
        root = new TrieNode;
    }
    void insert(const string &s) {
        int j = LEN(s) - 1;
        while (j >= 0 && s[j] == '-') --j;
        TrieNode* node = root;
        FOR(i, 0, j + 1) {
            if (!node->children.count(s[i])) {
                node->children[s[i]] = new TrieNode;
            }
            node = node->children[s[i]];
        }
        ++node->cnt;
    }
    int query(const string &s) {
        return dfs(root, s, 0);
    }
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<string> cadenas(n);
        for (auto &it : cadenas) {
            cin >> it;
        }
        int m = LEN(cadenas[0]);
        priority_queue<pair<int, int>> pq;
        FOR(j, 0, m) {
            int cnt = 0;
            for (auto &it : cadenas) {
                if (it[j] == '-') continue;
                ++cnt;
            }
            pq.push(mp(cnt, j));
        }
        vector<string> cadenasPermutadas(n, string(m, ' '));
        while(!pq.empty()) {
            int j = pq.top().second;
            pq.pop();
            FOR(i, 0, n) {
                cadenasPermutadas[i][m - SZ(pq) - 1] = cadenas[i][j];
            }
        }
        Trie trie;
        for (auto &it : cadenasPermutadas) {
            cout << it << '\n';
            trie.insert(it);
        }
        bool first = true;
        for (auto &it : cadenasPermutadas) {
            if (!first) cout << ' ';
            else first = false;
            cout << trie.query(it) - 1;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
