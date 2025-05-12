#include <bits/stdc++.h>
using namespace std;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<string, string> m = {
        {"A#", "Bb"},
        {"Bb", "A#"},
        {"C#", "Db"},
        {"Db", "C#"},
        {"D#", "Eb"},
        {"Eb", "D#"},
        {"F#", "Gb"},
        {"Gb", "F#"},
        {"G#", "Ab"},
        {"Ab", "G#"}
    };
    string note, tonality;
    int tcase = 1;
    while (cin >> note >> tonality) {
        cout << "Case " << tcase << ": ";
        ++tcase;
        if (m.count(note)) {
            cout << m[note] << ' ' << tonality << '\n';
        }else {
            cout << "UNIQUE\n";
        }
    }
    cout.flush();
    return 0;
}
