#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a, b)
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> ask, bid;
        int stock = -1;
        while (n--) {
            string order_type, aux;
            int x, y;
            cin >> order_type >> x >> aux >> aux >> y;
            if (order_type == "buy") {
                bid[y] += x;
            }else {
                ask[y] += x;
            }
            while (!bid.empty() && !ask.empty() && bid.rbegin()->first >= ask.begin()->first) {
                stock = ask.begin()->first;
                int askPrice = ask.begin()->first, bidPrice = bid.rbegin()->first;
                int quantity = min(bid.rbegin()->second, ask.begin()->second);
                ask[askPrice] -= quantity;
                bid[bidPrice] -= quantity;
                if (ask[askPrice] == 0) {
                    ask.erase(askPrice);
                }
                if (bid[bidPrice] == 0) {
                    bid.erase(bidPrice);
                }
            }
            if (!ask.empty()) {
                cout << ask.begin()->first;
            }else {
                cout << '-';
            }
            cout << ' ';
            if (!bid.empty()) {
                cout << bid.rbegin()->first;
            }else {
                cout << '-';
            }
            cout << ' ';
            if (stock != -1) {
                cout << stock;
            }else {
                cout << '-';
            }
            cout << '\n';
        }
    }
    cout.flush();
    return 0;
}
