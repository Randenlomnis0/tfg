#include <bits/stdc++.h>
using namespace std;
#define MAX(a,b) a = max(a, b)
#define MIN(a,b) a = min(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int tallest = -1, smallest = -1, ans = 0;
    while (N--) {
        int aux;
        cin >> aux;
        if (tallest != -1) {
            if (smallest != -1) {
                MAX(ans, min(aux, tallest) - smallest);
                MIN(smallest, aux);
            }else {
                smallest = aux;
            }
            if (aux > tallest) {
                tallest = aux;
                smallest = -1;
            }
        }else {
            tallest = aux;
        }
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
