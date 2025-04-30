#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int k, iguales = 0, diferentes = 0; cin >> k;
    string a, b; cin >> a >> b;

    for (int i = 0; i < a.length(); ++i) {

        iguales += (a[i] == b[i]);
        diferentes += (a[i] != b[i]);
    }
    cout << max(iguales, k) + max(diferentes, ((int)a.length()) - k);

    cout.flush();

    return EXIT_SUCCESS;
}
