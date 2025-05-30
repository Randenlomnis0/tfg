#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define ALL(c) (c).begin(), (c).end()
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    FOR(tcase, 1, T + 1) {
        string alien_number, source_language, target_language;
        cin >> alien_number >> source_language >> target_language;
        unordered_map<char, int> source_pos;
        FOR(i, 0, LEN(source_language)) {
            source_pos[source_language[i]] = i;
        }
        int b10 = 0, aux = 1, base = LEN(source_language);
        FOR(i, 0, LEN(alien_number)) {
            b10 += aux * source_pos[alien_number[LEN(alien_number) - 1 - i]];
            aux *= base;
        }
        base = LEN(target_language);
        string ans = "";
        while (b10 > 0) {
            ans += target_language[b10%base];
            b10 /= base;
        }
        reverse(ALL(ans));
        cout << "Case #" << tcase << ": " << ans << '\n';
    }
    cout.flush();
    return 0;
}
