#include <bits/stdc++.h>

using namespace std;

double solve(const vector<string>& tokens, const int& i, const int& j) {

    vector<string> t1;

    cout << i << ' ' << j << ": ";

    for (int p = i; p < j; ++p) {
        
        cout << tokens[p] << ' ';
    }
    cout << '\n';

    if (i == j - 1) {

        return stod(tokens[i]);
    }

    if (i == j - 2 && tokens[i] == "-") {

        return -stod(tokens[i + 1]);
    }

    for (int p = i; p < j; ++p) {

        if (tokens[p] == "(") {

            for (int q = j - 1; q >= i; --q) {

                if (tokens[q] == ")") {

                    t1.push_back(to_string(solve(tokens, p + 1, q)));

                    p = q;
                }
            }
        }else {

            t1.push_back(tokens[p]);
        }
    }

    for (int p = t1.size() - 1; p >= 0; --p) {

        if (t1[p] == "+") {

            return solve(t1, 0, p) + solve(t1, p + 1, t1.size());
        }else if (t1[p] == "-") {

            if (p > 0 && t1[p - 1] != "+" && t1[p - 1] != "-" && t1[p - 1] != "*" && t1[p - 1] != "/") return solve(t1, 0, p) - solve(t1, p + 1, t1.size());
            else return solve(t1, 0, p - 1) - solve(t1, p, t1.size());
        }
    }

    for (int p = t1.size() - 1; p >= 0; --p) {

        if (t1[p] == "*") {

            return solve(t1, 0, p) * solve(t1, p + 1, t1.size());
        }else if (t1[p] == "/") {

            return solve(t1, 0, p) / solve(t1, p + 1, t1.size());
        }
    }
cout << "errooor\n";
    return -1.0;
}

int main() {

    cin.sync_with_stdio(false);
    cin.tie(nullptr);

    string line, token;
    vector<string> tokens;
    char prev;

    while (getline(cin, line)) {

        token = "";
        tokens.clear();
        prev = ' ';

        for (auto &it : line) {

            if (it == ' ') {

                if (token != "") tokens.push_back(token);
                token = "";
            }else if (it == '(' || it == ')' || it == '+' || it == '-' || it == '*' || it == '/') {

                if (token != "") tokens.push_back(token);
                token = "";

                token += it;
                tokens.push_back(token);
                token = "";
            }else {

                token += it;
            }
            prev = it;
        }

        if (token != "") tokens.push_back(token);

        cout << fixed << setprecision(2) << solve(tokens, 0, tokens.size()) << '\n';
    }
    cout.flush();

    return EXIT_SUCCESS;
}
