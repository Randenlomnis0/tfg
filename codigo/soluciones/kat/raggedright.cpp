#include <bits/stdc++.h>
using namespace std;
#define GL(x) getline(cin, x)
#define PB(x) push_back(x)
#define MAX(a,b) a = max(a, b)
#define LEN(x) ((int)x.length())
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define SZ(x) ((int)x.size())
int main() {
    string line;
    vector<int> longitudes;
    int longMasLarga = 0;
    while (GL(line)) {

        longitudes.PB(LEN(line));
        MAX(longMasLarga, LEN(line));
    }
    int ans = 0;
    FOR(i, 0, SZ(longitudes) - 1) {
        ans += (longMasLarga - longitudes[i]) * (longMasLarga - longitudes[i]);
    }
    cout << ans << '\n';
    cout.flush();
    return 0;
}
