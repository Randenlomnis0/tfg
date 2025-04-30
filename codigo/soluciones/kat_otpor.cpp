#include <bits/stdc++.h>

using namespace std;

double solve(const string& tokens, const int& i, const int& j, const vector<int>& R) {

    char op;
    double ans = 0.0;
    int prof = 0, aux;

    for (int p = i; p < j; ++p) {

        if (tokens[p] == '(') ++prof;
        else if (tokens[p] == ')') --prof;
        else if (!prof && (tokens[p] < '1' || tokens[p] > '9')) {

            op = tokens[p];
        }
    }

    for (int k = i; k < j; ++k) {

        if (tokens[k] == '(') {
            
            if (!prof) {

                aux = k + 1;
            }
            ++prof;
        }else if (tokens[k] == ')') {

            --prof;

            if (!prof) {

                if (op == '-') {

                    ans += solve(tokens, aux, k, R);
                }else {

                    ans += 1.0 / solve(tokens, aux, k, R);
                }
            }
        }else if (!prof && tokens[k] >= '1' && tokens[k] <= '9') {

            if (op == '-') {

                ans += R[tokens[k] - '1'];
            }else {

                ans += 1.0 / R[tokens[k] - '1'];
            }
        }
    }

    if (op == '|') {

        ans = 1.0 / ans;
    }
    return ans;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> R(N);
    string line, tokens = "";

    for (int i = 0; i < N; ++i) {

        cin >> R[i];
    }
    getline(cin, line);
    getline(cin, line);

    for (int i = 0; i < line.length(); ++i) {

        if (line[i] == ' ') continue;

        if (line[i] == '(' || line[i] == ')' || line[i] == '|' || line[i] == '-') tokens.push_back(line[i]);
        else {
            
            tokens.push_back(line[i + 1]);
            ++i;
        }
    }
    cout << fixed << setprecision(5) << solve(tokens, 1, tokens.size() - 1, R) << '\n';

    cout.flush();

    return EXIT_SUCCESS;
}
