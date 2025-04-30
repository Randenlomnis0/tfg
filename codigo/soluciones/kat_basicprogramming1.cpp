#include <bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for (int i = j; i < k; ++i)
#define ALL(c) (c).begin(),(c).end()
#define ll long long
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int N, t;
    cin >> N >> t;
    vector<int> A(N);
    for (auto &it : A) {
        cin >> it;
    }
    if (t == 1) {
        cout << "7\n";
    }else if (t == 2) {
        if (A[0] == A[1]) {
            cout << "Equal\n";
        }else if (A[0] > A[1]) {
            cout << "Bigger\n";
        }else {
            cout << "Smaller\n";
        }
    }else if (t == 3) {
        vector<int> aux(3);
        FOR(i, 0, 3) {
            aux[i] = A[i];
        }
        sort(ALL(aux));
        cout << aux[1] << '\n';
    }else if (t == 4) {
        ll sum = 0;
        for (auto &it : A) {
            sum += it;
        }
        cout << sum << '\n';
    }else if (t == 5) {
        ll sum = 0;
        for (auto &it : A) {
            if (it%2) continue;
            sum += it;
        }
        cout << sum << '\n';
    }else if (t == 6) {
        for (auto &it : A) {
            cout << (char)('a' + (char)(it%26));
        }
        cout << '\n';
    }else if (t == 7) {
        int i = 0;
        vector<bool> visited(N, false);
        while (i >= 0 && i < N - 1 && !visited[i]) {
            visited[i] = true;
            i = A[i];
        }
        if (i == N - 1) {
            cout << "Done\n";
        }else if (i < 0 || i >= N) {
            cout << "Out\n";
        }else {
            cout << "Cyclic\n";
        }
    }
    cout.flush();
    return 0;
}
