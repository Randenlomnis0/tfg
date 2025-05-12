#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string aux, prev;
    cin >> aux;
    int problemo = -1;
    unordered_set<string> strings;
    strings.insert(aux);
    FOR(i, 1, N) {
        prev = aux;
        cin >> aux;
        if ((prev[LEN(prev) - 1] != aux[0] || strings.count(aux)) && problemo == -1) {
            problemo = i;
        }
        strings.insert(aux);
    }
    if (problemo == -1) {
        cout << "Fair Game\n";
    }else {
        cout << "Player " << (problemo%2 ? 2 : 1) << " lost\n";
    }
    cout.flush();
    return 0;
}
