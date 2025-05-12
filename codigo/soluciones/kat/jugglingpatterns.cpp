#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define LEN(s) ((int)(s).length())
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (cin >> s) {
        cout << s << ": ";
        int balls = 0;
        for (auto &it : s) {
            balls += it - '0';
        }
        if (balls%LEN(s)) {
            cout << "invalid # of balls\n";
            continue;
        }
        s = s.substr(0, balls);
        priority_queue<pair<int, int>> l, r;
        FOR(i, 0, LEN(s)) {
            int h = s[i] - '0';
            if (h == 0) continue;
            if (i%2) {
                r.push(mp(-i, -h));
            }else {
                l.push(mp(-i, -h));
            }
        }
        int aux = 2 * 2520;
        bool problemo = false;
        while (aux--) {
            if (l.size() > 1) {
                int a = -l.top().first;
                int c = -l.top().second;
                l.pop();
                int b = -l.top().first;
                int d = -l.top().second;
                l.pop();
                if (a == b) {
                    cout << "invalid pattern\n";
                    problemo = true;
                    break;
                }
                l.push(mp(-a, -c));
                l.push(mp(-b, -d));
            }
            if (r.size() > 1) {
                int a = -r.top().first;
                int c = -r.top().second;
                r.pop();
                int b = -r.top().first;
                int d = -r.top().second;
                r.pop();
                if (a == b) {
                    cout << "invalid pattern\n";
                    problemo == true;
                    break;
                }
                r.push(mp(-a, -c));
                r.push(mp(-b, -d));
            }
            int a = INT_MAX, b = INT_MAX;
            if (!l.empty()) a = -l.top().first;
            if (!r.empty()) b = -r.top().first;
            if (a < b) {
                int c = -l.top().second;
                l.pop();
                if (c%2) {
                    r.push(mp(-(a + c), -c));
                }else {
                    l.push(mp(-(a + c), -c));
                }
            }else if (b < a) {
                int c = -r.top().second;
                r.pop();
                if (c%2) {
                    l.push(mp(-(a + c), -c));
                }else {
                    r.push(mp(-(a + c), -c));
                }
            }else {
                break;
            }
        }
        if (!problemo) {
            cout << "valid with " << balls << " balls\n";
        }
    }
    cout.flush();
    return 0;
}
/*
33333
- - -
 - -
*/