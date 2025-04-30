#include <bits/stdc++.h>
using namespace std;
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string name, studies, birth;
        int courses;
        cin >> name >> studies >> birth >> courses;
        cout << name << ' ';
        if (stoi(studies.substr(0, 4)) >= 2010 || stoi(birth.substr(0, 4)) >= 1991) {
            cout << "eligible\n";
        }else if (courses > 40) {
            cout << "ineligible\n";
        }else {
            cout << "coach petitions\n";
        }
    }
    cout.flush();
    return 0;
}
