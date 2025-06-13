#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define MAX(a,b) a = max(a, b)
#define LEN(s) ((int)(s).length())
int mcd(int a, int b) {
    while (b) {
        int aux = a;
        a = b;
        b = aux%b;
    }
    return a;
}
string cociente(const string &dividendo, const int &divisor, const vector<int> &restos) {
    int resto = 0, aux = 1;
    string ans = "";
    for (auto &it : dividendo) {
        resto = (10 * resto + (it - '0'));
        if (ans == "" && resto < divisor) continue;
        ans += resto / divisor + '0';
        resto %= divisor;
        if (aux >= restos.size() || (restos[aux++] != resto)) return "-1";
    }
    if (aux < restos.size()) return "-1";
    return ans;
}
void explorar(map<int, string> &soluciones, unordered_map<int, int> &factores, const string &dividendo, const int &maxResto, const int &ans, const vector<int> &restos) {
    if (factores.empty()) {
        if (ans > maxResto && !soluciones.count(-ans)) {
            soluciones[-ans] = cociente(dividendo, ans, restos);
        }
        return;
    }
    int base = factores.begin()->first;
    --factores[base];
    if (factores[base] == 0) {
        factores.erase(base);
    }
    explorar(soluciones, factores, dividendo, maxResto, ans * base, restos);
    explorar(soluciones, factores, dividendo, maxResto, ans, restos);
    ++factores[base];
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string dividendo;
    while (cin >> dividendo, dividendo != "0") {
        int N;
        cin >> N;
        vector<int> restos(N + 1);
        int maxResto = 0;
        FOR(i, 0, N) {
            cin >> restos[i + 1];
            MAX(maxResto, restos[i + 1]);
        }
        int ans = stoi(dividendo.substr(0, LEN(dividendo) - N + 1)) - restos[1];
        FOR(i, 1, N) {
            int num = 10 * restos[i] + (dividendo[LEN(dividendo) - N + i] - '0') - restos[i + 1];
            ans = mcd(num, ans);
        }
        unordered_map<int, int> factores;
        int base = 2;
        while (base * base <= ans) {
            while (ans%base == 0) {
                ans /= base;
                ++factores[base];
            }
            ++base;
        }
        if (ans > 0) {
            ++factores[ans];
        }
        map<int, string> soluciones;
        explorar(soluciones, factores, dividendo, maxResto, 1, restos);
        bool first = true;
        for (auto &it : soluciones) {
            if (it.second == "-1") continue;
            if (!first) cout << " - ";
            else first = false;
            cout << -it.first << ' ' << it.second;
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}