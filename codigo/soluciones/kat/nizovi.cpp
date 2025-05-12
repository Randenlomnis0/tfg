#include <bits/stdc++.h>
using namespace std;
#define PB(x) push_back(x)
#define FOR(i,j,k) for (int i = j; i < k; ++i)
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s, token = ""; cin >> s;
    int depth = 0;
    vector<string> tokens;
    for (auto &it : s) {
        if (it == ' ') {
            if (token != "") {
                tokens.PB(token);
                token = "";
            }
        }else if (it == '{' || it == '}' || it == ',') {
            if (token != "") {
                tokens.PB(token);
                token = "";
            }
            tokens.PB(string(1, it));
        }else {
            token += it;
        }
    }
    if (token != "") {
        tokens.PB(token);
    }
    bool faltaEspacio = false;
    for (auto &it : tokens) {
        if (it == "{") {
            FOR(i, 0, depth) cout << "  ";
            cout << "{\n";
            ++depth;
        }else if (it == "}") {
            --depth;
            if (faltaEspacio) {
                cout << "\n";
                faltaEspacio = false;
            }
            FOR(i, 0, depth) cout << "  ";
            cout << "}";
            faltaEspacio = true;
        }else if (it == ",") {
            faltaEspacio = false;
            cout << ",\n";
        }else {
            faltaEspacio = true;
            FOR(i, 0, depth) cout << "  ";
            cout << it;
        }
    }
    if (faltaEspacio) cout << '\n';
    cout.flush();
    return 0;
}
