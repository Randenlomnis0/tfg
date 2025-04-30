#include <bits/stdc++.h>

using namespace std;

struct nodo {

    vector<nodo*> hijos;
    bool isPhoneNumber;
};

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {

        int n; cin >> n;
        nodo* root = new nodo;
        root->hijos = vector<nodo*>(10, nullptr);
        root->isPhoneNumber = false;
        bool fallo = false;

        for (int i = 0; i < n; ++i) {

            string phoneNumber; cin >> phoneNumber;
            nodo* aux = root;
            bool safe = false;

            for (auto &it : phoneNumber) {

                if (aux->isPhoneNumber) {

                    fallo = true;
                }

                if (aux->hijos[it - '0'] == nullptr) {

                    safe = true;
                    aux->hijos[it - '0'] = new nodo;
                    aux->hijos[it - '0']->hijos = vector<nodo*>(10, nullptr);
                    aux->hijos[it - '0']->isPhoneNumber = false;
                }
                aux = aux->hijos[it - '0'];
            }
            aux->isPhoneNumber = true;

            if (!safe) fallo = true;

            if (fallo) break;
        }

        if (fallo) {

            cout << "NO\n";
        }else {

            cout << "YES\n";
        }
    }
    cout.flush();

    return EXIT_SUCCESS;
}
