#include <bits/stdc++.h>

using namespace std;

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, suma, primerasuma, lineas, aux;
    string s;
    char start;

    while (cin >> n, n) {

        cin >> s;

        while (lineas < n) {

            start = s[0];
            suma = 0;

            while (cin >> s, s != "#" && s != ".") {

                aux = stoi(s);
                suma += aux;

                
            }
            ++lineas;
        }
    }
    cout.flush();

    return EXIT_SUCCESS;
}
