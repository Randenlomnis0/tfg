#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, (s))
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
#define pb(x) push_back(x)
#define SZ(c) ((int)(c).size())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string aux;
    GL(aux);
    int N;
    cin >> N;
    GL(aux);
    vector<vector<string>> answers(N);
    FOR(i, 0, N) {
        GL(aux);
        while (true) {
            answers[i].pb(aux.substr(0, aux.find(',')));
            if (aux.find(',') == string::npos) break;
            aux = aux.substr(aux.find(',') + 2);
        }
    }
    vector<int> incongruosity(N);
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            if (i == j) continue;
            int c = 0;
            FOR(k, 0, SZ(answers[i])) {
                c += answers[i][k] != answers[j][k];
            }
            MAX(incongruosity[i], c);
        }
    }
    int mx = INT_MAX;
    FOR(i, 0, N) {
        MIN(mx, incongruosity[i]);
    }
    FOR(i, 0, N) {
        if (incongruosity[i] > mx) continue;
        bool first = true;
        for (auto &it : answers[i]) {
            if (!first) cout << ", ";
            else first = false;
            cout << it;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
