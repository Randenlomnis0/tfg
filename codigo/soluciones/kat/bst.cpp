#include <bits/stdc++.h>
using namespace std;
struct nodo {
    int val = 0;
    nodo* l = nullptr;
    nodo* r = nullptr;
};
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, C = 0;
    cin >> N;
    nodo* root = new nodo;
    while (N--) {
        int val;
        cin >> val;
        nodo* aux = root;
        int c = 0;
        while (aux->val != 0) {
            if (val < aux->val) {
                if (!aux->l) {
                    aux->l = new nodo;
                }
                aux = aux->l;
            }else {
                if (!aux->r) {
                    aux->r = new nodo;
                }
                aux = aux->r;
            }
            ++c;
        }
        aux->val = val;
        C += c;
        cout << C << '\n';
    }
    cout.flush();
    return 0;
}
