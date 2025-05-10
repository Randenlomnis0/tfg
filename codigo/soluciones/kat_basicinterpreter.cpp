#include <bits/stdc++.h>
using namespace std;
#define GL(s) getline(cin, s)
#define LEN(s) ((int)(s).length())
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, string> program;
    int line_number;
    string line;
    while (cin >> line_number) {
        GL(line);
        program[line_number] = line;
    }
    unordered_map<string, int> mem;
    auto it = program.begin();
    while (it != program.end()) {
        cout << it->first << '\n';
        line = it->second;
        cout << line << '\n';
        if (line.substr(0, 4) == " LET") {
            regex pattern(R"(\sLET\s(\w+)\s=\s(\w+)(?:\s([\+\-\*/])\s(\w+))?)");
            smatch match;
            regex_match(line, match, pattern);
            string X = match[1];
            string A = match[2];
            string op = match[3].matched ? match[3].str() : "";
            string B = match[4].matched ? match[4].str() : "";
            cout << X << ' ' << A << endl;
            int a, b;
            if (mem.count(A)) {
                a = mem[A];
            }else {
                a = stoi(A);
            }
            if (op != "") {
                if (mem.count(B)) {
                    b = mem[B];
                }else {
                    b = stoi(B);
                }
                if (op == "+") {
                    mem[X] = a + b;
                }else if (op == "-") {
                    mem[X] = a - b;
                }else if (op == "*") {
                    mem[X] = a * b;
                }else {
                    mem[X] = a / b;
                }
            }else {
                mem[X] = a;
            }
            ++it;
        }else if (line.substr(0, 3) == " IF") {
            regex pattern(R"(\sIF\s(\w+)\s(=|<>|<|>|<=|>=)\s(\w+)\sGOTO\s(\d+))");
            smatch match;
            regex_match(line, match, pattern);
            string X = match[1];
            string op = match[2];
            string Y = match[3];
            string L = match[4];
            int a, b;
            if (mem.count(X)) {
                a = mem[X];
            }else {
                a = stoi(X);
            }
            if (mem.count(Y)) {
                b = mem[Y];
            }else {
                b = stoi(Y);
            }
            bool jmp;
            if (op == "=") {
                jmp = a == b;
            }else if (op == "<>") {
                jmp = a != b;
            }else if (op == "<") {
                jmp = a < b;
            }else if (op == ">") {
                jmp = a > b;
            }else if (op == "<=") {
                jmp = a <= b;
            }else {
                jmp = a >= b;
            }
            if (jmp) {
                it = program.find(stoi(L));
            }else {
                ++it;
            }
        }else if (line.substr(0, 8) == " PRINTLN") {
            line = line.substr(9);
            if (line[0] == '\"') {
                cout << line.substr(1, LEN(line) - 2) << '\n';
            }else {
                cout << mem[line] << '\n';
            }
            ++it;
        }else {
            line = line.substr(7);
            if (line[0] == '\"') {
                cout << line.substr(1, LEN(line) - 2);
            }else {
                cout << mem[line];
            }
            ++it;
        }
    }
    cout.flush();
    return 0;
}
